#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    char data;
    int frequency;
    Node* left;
    Node* right;

    Node(char d, int f) {
        data = d;
        frequency = f;
        left = right = nullptr;
    }
};

struct compare {
    bool operator()(Node* a, Node* b) {
        return a->frequency > b->frequency;
    }
};

void printCodes(Node* root, string code, long long &totalMemory) {
    if (!root->left && !root->right) {
        long long memory = (long long)code.length() * root->frequency;
        totalMemory += memory;
        cout << root->data << ":" << code << "  (Memory used = " << memory << " bits)" << endl;
        return;
    }

    if (root->left)
        printCodes(root->left, code + "0", totalMemory);

    if (root->right)
        printCodes(root->right, code + "1", totalMemory);
}

int main() {
    int n;
    cin >> n;

    priority_queue<Node*, vector<Node*>, compare> pq;

    for (int i = 0; i < n; i++) {
        char ch;
        int freq;
        cin >> ch >> freq;
        pq.push(new Node(ch, freq));
    }

    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();

        Node* newNode = new Node('$', left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    Node* root = pq.top();

    long long totalMemory = 0;
    printCodes(root, "", totalMemory);

    return 0;
}
