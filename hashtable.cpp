#include <iostream>
#include <list>
using namespace std;
class HashTable {
private:
    int size;
    list<int>* table;
public:
    HashTable(int s) {
        size = s;
        table = new list<int>[size];
    }
    int hashFunction(int key) {
        return key % size;
    }
    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
        cout << key << " inserted at index " << index << endl;
    }
    void search(int key) {
        int index = hashFunction(key);
        for (int val : table[index]) {
            if (val == key) {
                cout << key << " found at index " << index << endl;
                return;
            }
        }
        cout << key << " not found!" << endl;
    }
    void remove(int key) {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); it++) {
            if (*it == key) {
                table[index].erase(it);
                cout << key << " deleted from index " << index << endl;
                return;
            }
        }
        cout << key << " not found, cannot delete!" << endl;
    }
    void display() {
        for (int i = 0; i < size; i++) {
            cout << "Bucket " << i << ": ";
            for (int val : table[i]) {
                cout << val << " -> ";
            }
            cout << "NULL" << endl;
        }
    }
};
int main() {
    int choice, key, size;
    cout << "Enter size of hash table: ";
    cin >> size;
    HashTable h(size);
    cout << "\n--- Hash Table Menu ---\n";
    cout << "1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\n";
    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                h.insert(key);
                break;
            case 2:
                cout << "Enter key to search: ";
                cin >> key;
                h.search(key);
                break;
            case 3:
                cout << "Enter key to delete: ";
                cin >> key;
                h.remove(key);
                break;
            case 4:
                h.display();
                break;
            case 5:
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
