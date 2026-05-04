#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* topNode = nullptr;

bool isEmpty() {
    return topNode == nullptr;
}

void push(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = topNode;
    topNode = newNode;
}

int pop() {
    if (isEmpty())
        return -1;

    Node* temp = topNode;
    int val = temp->data;
    topNode = topNode->next;
    delete temp;
    return val;
}

int peek() {
    if (isEmpty())
        return -1;
    return topNode->data;
}

void display() {
    Node* temp = topNode;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    push(5);
    push(15);
    push(25);
    push(35);

    display();
    cout << endl;

    cout << peek() << endl;

    pop();

    display();
    cout << endl;

    push(45);

    display();

    return 0;
}
