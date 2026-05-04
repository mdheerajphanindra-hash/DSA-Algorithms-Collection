#include <iostream>
using namespace std;

const int SIZE = 10;

class Chain {
public:
    int data;
    Chain* next;

    Chain(int value) {
        data = value;
        next = nullptr;
    }
};

class HashTable {
private:
    Chain* table[SIZE];

    int hashFunction(int value) {
        return value % SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < SIZE; i++) {
            table[i] = nullptr;
        }
    }

    ~HashTable() {
        for (int i = 0; i < SIZE; i++) {
            Chain* temp = table[i];
            while (temp != nullptr) {
                Chain* nextNode = temp->next;
                delete temp;
                temp = nextNode;
            }
            table[i] = nullptr;
        }
        cout << "HashTable destroyed. Memory freed.\n";
    }

    void insert(int value) {
        int index = hashFunction(value);
        Chain* newNode = new Chain(value);

        if (table[index] == nullptr) {
            table[index] = newNode;
        } else {
            Chain* temp = table[index];
            while (temp->next != nullptr) {
                if (temp->data == value) {
                    cout << "Value already exists!\n";
                    delete newNode;
                    return;
                }
                temp = temp->next;
            }
            if (temp->data == value) {
                cout << "Value already exists!\n";
                delete newNode;
                return;
            }
            temp->next = newNode;
        }
        cout << "Inserted " << value << " at index " << index << "\n";
    }

    void search(int value) {
        int index = hashFunction(value);
        Chain* temp = table[index];
        while (temp != nullptr) {
            if (temp->data == value) {
                cout << "Value " << value << " found at index " << index << "\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Value not found!\n";
    }

    void remove(int value) {
        int index = hashFunction(value);
        Chain* temp = table[index];
        Chain* prev = nullptr;

        while (temp != nullptr) {
            if (temp->data == value) {
                if (prev == nullptr) {
                    table[index] = temp->next;
                } else {
                    prev->next = temp->next;
                }
                delete temp;
                cout << "Deleted " << value << " from index " << index << "\n";
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        cout << "Value not found!\n";
    }

    void display() {
        for (int i = 0; i < SIZE; i++) {
            cout << i << ": ";
            Chain* temp = table[i];
            while (temp != nullptr) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    HashTable ht;
    int choice, value;

    do {
        cout << "\n--- Hash Table Menu ---\n";
        cout << "1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            ht.insert(value);
            break;
        case 2:
            cout << "Enter value to search: ";
            cin >> value;
            ht.search(value);
            break;
        case 3:
            cout << "Enter value to delete: ";
            cin >> value;
            ht.remove(value);
            break;
        case 4:
            ht.display();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
