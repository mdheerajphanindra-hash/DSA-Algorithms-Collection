#include <stdio.h>


void linearSearch(int array[],int size,int key){
    int f=0;
    for(int j=0;j<size;j++){
        if(key==array[j]){
            printf("Element found in %d index",j);
            f=1;
            break;
        }
    }
    if(f==0){
        printf("Element not found");
    }
}


int main() {
    int n;
    printf("Enter number of numbers in an array=");
    scanf("%d",&n);
    
    int array[n];
    for(int i=0;i<n;i++){
        printf("Enter the value in array of index %d=",i);
        scanf("%d",&array[i]);
    }

    int key;
    printf("Enter the key=");
    scanf("%d",&key);
    linearSearch(array,n,key);
    return 0;
}
