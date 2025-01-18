#include <iostream>
#include <math.h>

class Node {
public:
    std::string value;
    Node* next;

    Node(std::string value="") {
        this->value = value;
        this->next = nullptr;
    }

    int hash(int size){
        int hash = 0;
        for (int i = 0; i < this->value.length(); i++) {
            hash += std::pow(7, i) * this->value[i];
        }
        hash %= size;
        return hash;
    }
};

class HashTable {
public:
    int size;
    Node** table;

    HashTable(int size=10) {
        this->size = size;
        this->table = new Node*[size];
        for (int i = 0; i < size; i++) {
            this->table[i] = nullptr;
        }
    }

    void insert(std::string value) {
        Node* new_node = new Node(value);
        int index = new_node->hash(this->size);
        if (this->table[index] == nullptr) {
            this->table[index] = new_node;
        } else {
            Node* current = this->table[index];
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new_node;
        }
    }

    void print() {
        for (int i = 0; i < this->size; ++i) {
            Node* current = this->table[i];
            std::cout << i << ": ";
            while (current != nullptr) {
                std::cout << current->value << " ";
                current = current->next;
            }
            std::cout << std::endl;
        }
    }

};

int main() {
    HashTable* ht = new HashTable();

    std::string word = "";

    char c = 'a';
    for (int i = 0; i < 20; ++i) {
        c += 1;
        word = "";
        for (int j = 0; j < 5; ++j) {
            word += std::string(1, c + j);
        }
        ht->insert(word);
    }

    ht->insert("apple");
    ht->insert("Apple");
    ht->insert("APpple");
    ht->insert("aa");
    ht->insert("ab");
    ht->insert("bb");
    ht->insert("aa");
    ht->insert("ba");
    ht->insert("ca");
    ht->insert("ac");
    ht->insert("aa");
    ht->insert("cc");

    ht->print();


    return 0;
}