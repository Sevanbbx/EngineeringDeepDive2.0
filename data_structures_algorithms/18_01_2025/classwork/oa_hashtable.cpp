#include <iostream>
#include <vector>

class OAHashTable {
private:
    std::vector<int> table;
    int capacity;
    double max_load_factor;
    double min_load_factor;

    int hash(int value) {
        return value % this->size();
    }

    void insert_helper(int value, std::vector<int>& table) {
        int index = this->hash(value);
        while (table[index] != -1) {
            index = (index + 1) % table.size();
        }
        table[index] = value;
    }

public:

    OAHashTable(int size) {
        this->table = std::vector<int>(size, -1);
        this->capacity = 0;
        this->max_load_factor = 0.85;
        this->min_load_factor = 0.25;
    }

    int size() {
        return this->table.size();
    }

    void insert(int value) {
        std::cout << "load_factor: " << this->get_load_factor() << std::endl;
        std::cout << "capacity: " << this->capacity << std::endl;
        std::cout << "size: " << this->size() << std::endl;
        if (this->get_load_factor() > this->max_load_factor) {
            this->normal_rehash();
        }
        this->insert_helper(value, this->table);
        this->capacity++;
    }

    void print() {
        for (int i = 0; i < this->size(); ++i) {
            std::cout << i << ": " << this->table[i] << std::endl;
        }
    }

    double get_load_factor() {
        return static_cast<double>(this->capacity) / this->size();
    }

    int search(int value) {
        int index = this->hash(value);
        while (this->table[index] != value) {
            if (this->table[index] == -1) {
                return -1;
            }
            index = (index + 1) % this->size();
        }
        return index;
    }

    void normal_rehash() {
        std::vector<int> old_table = this->table;
        std::vector<int> new_table = std::vector<int>(this->size() * 2, -1);

        for (int i = 0; i < old_table.size(); ++i) {
            if (old_table[i] != -1) {
                this->insert_helper(old_table[i], new_table);
            }
        }
        this->table = new_table;
    }

 
};


int main() {
    OAHashTable ht = OAHashTable(10);
    for (int i = 0; i < 15; ++i) {
        ht.insert(i);
        ht.print();
        std::cout << std::endl;
    }
    std::cout << "ht.search(20): " << ht.search(20) << std::endl;
    return 0;
}