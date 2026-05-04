#include <stdio.h>
#include <stdlib.h>
struct node{
    char data;
    int frequency;
    struct node* left;
    struct node* right;
};
int size=0;
struct node* arr[100];
void swap(int i,int j){
    struct node* temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
void heapifyUp(int index){
    if(index==0){
        return;
    }
    int parent=(index-1)/2;
    while(index>0&&arr[parent]->frequency>arr[index]->frequency){
        swap(parent,index);
        index=parent;
        parent=(index-1)/2;
    }
}
void heapifyDown(){
    if(size==0){
        return;
    }
    int index=0;
    while(1){
        int left=2*index+1;
        int right=2*index+2;
        int smallest=index;
        if(left<size&&arr[left]->frequency<=arr[smallest]->frequency){
            smallest=left;
        }
        if(right<size&&arr[right]->frequency<=arr[smallest]->frequency){
            smallest=right;
        }
        if(smallest==index){
            break;
        }
        swap(index,smallest);
        index=smallest;
    }
}
void add(struct node* node){
    arr[size]=node;
    heapifyUp(size);
    size++;
}
struct node* delete(){
    struct node* temp=arr[0];
    swap(0,size-1);
    size--;
    heapifyDown();
    return temp;
}
void creatingTree(struct node* a,struct node* b){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data='$';
    newnode->frequency=a->frequency+b->frequency;
    newnode->left=b;
    newnode->right=a;
    add(newnode);
}
long long totalMemory = 0; 
void printingCodes(struct node* ptr,char code[],int top){
    if(ptr->left==NULL && ptr->right==NULL){
        code[top]='\0';
        long long memory = (long long)top * ptr->frequency;
        totalMemory += memory;
        printf("%c:%s  (Memory used = %lld bits)\n", ptr->data, code, memory);
        return;
    }
    code[top]='0';
    if(ptr->left){
        printingCodes(ptr->left,code,top+1);
    }
    code[top]='1';
    if(ptr->right){
        printingCodes(ptr->right,code,top+1);
    }
}
int main(){
    int n;
    printf("NO.OF ELEMENTS to be stored: ");
    scanf("%d",&n);
     printf("Enter character and its frequency: \n");
    for(int i=1;i<=n;i++){
        struct node* node=(struct node*)malloc(sizeof(struct node));
        scanf(" %c",&(node->data));
        scanf("%d",&(node->frequency));
        node->left=NULL;
        node->right=NULL;
        add(node);
    }
    while(size!=1){
        creatingTree(delete(),delete());
    }
    struct node* ptr=delete();
    char code[20];
    printf("The final huffman codes are: \n");
    printingCodes(ptr,code,0);
}
