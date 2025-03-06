#include <iostream>

template <typename T>
class Stack {
public:
    T* data;
    int size;
    int top;

    Stack() {
        this->size = 1;
        this->top = -1;
        this->data = new T[this->size];
    }

    ~Stack() {
        delete[] this->data;
    }

    int getSize() {
        return this->size;
    }

    bool empty() const {
        return this->top == -1;
    }

    void push(T value) {
        if (this->top == this->size) {
            this->size = size * 2;
            T* new_data = new T[this->size];
            for (int i = 0; i <= this->top; ++i) {
                new_data[i] = data[i];
            }
            delete[] data;
            this->data = new_data;
        }
        this->data[++this->top] = value;
    }

    T& getTop() const {
        if (this->empty()) {
            throw "Stack is empty";
        }
        std::cout << "const" << std::endl;
        return this->data[this->top];
    }

    T& getTop() {
        if (this->empty()) {
            throw "Stack is empty";
        }
        std::cout << "NOT const" << std::endl;

        return this->data[this->top];
    }

    T pop() {
        if (this->empty()) {
            throw "Stack is empty";
        }
        return this->data[this->top--];
    }

    void print() {
        for (int i = 0; i <= this->top; ++i) {
            std::cout << this->data[i] << " ";
        }
        std::cout << std::endl;
    }
};


class BoolWrapper{ 
public:
    unsigned char& byte;
    int bitIndex;

    BoolWrapper(unsigned char& byte, int bitIndex=0): byte(byte), bitIndex(bitIndex) {
        this->byte = byte;
        this->bitIndex = bitIndex;
    }

    BoolWrapper& operator=(bool value) {
        if (value) {
            this->byte |= (value << this->bitIndex);
        } else {
            this->byte &= ~(1 << this->bitIndex);
        }
        
        return *this;
    } 

};
    
std::ostream& operator<<(std::ostream& os, const BoolWrapper& bw) {
    os << ((bw.byte >> bw.bitIndex) & 1);
    return os;
}


template<>
class Stack<bool> : public Stack<unsigned char>{
public:
    Stack() {
        this->size = 8;
        this->top = -1;
        this->data = new unsigned char[this->size / 8];
    }

    void push(bool value) {
        if (this->top == this->size) {
            this->size = size * 2;
            unsigned char* new_data = new unsigned char[this->size / 8];
            for (int i = 0; i <= this->top; ++i) {
                new_data[i] = data[i];
            }
            delete[] data;
            this->data = new_data;
        }
        this->top++;
        this->data[this->top / 8] |= (value << (this->top % 8));
    }

    BoolWrapper getTop() {
        if (this->empty()) {
            throw "Stack is empty";
        }
        return BoolWrapper(this->data[this->top / 8], this->top % 8);
    }

    BoolWrapper getTop() const {
        if (this->empty()) {
            throw "Stack is empty";
        }
        return BoolWrapper(this->data[this->top / 8], this->top % 8);
    }

    bool pop() {
        if (this->empty()) {
            throw "Stack is empty";
        }
        bool value = (this->data[this->top / 8] >> (this->top % 8)) & 1;
        this->top--;
        return value;
    }

    void print() {
        for (int i = 0; i <= this->top; ++i) {
            std::cout << ((this->data[i / 8] >> (i % 8)) & 1) << " ";
        }
        std::cout << std::endl;
    }

};



int main() {
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6);

    stack.print();

    std::cout << "stack.getTop() = " << stack.getTop() << std::endl;
    stack.getTop() = 100;
    std::cout << "stack.pop() = " << stack.pop() << std::endl;


    stack.print();

    std::cout << "=========================" << std::endl;

    Stack<bool> stack_bool;
    stack_bool.push(true);
    stack_bool.push(true);
    stack_bool.push(true);
    stack_bool.push(false);
    stack_bool.push(true);
    stack_bool.push(true);
    stack_bool.push(false);
    stack_bool.push(false);
    stack_bool.push(true);

    stack_bool.print();

    std::cout << "stack.bool.getTop() = " << stack_bool.getTop() << std::endl;
    stack_bool.getTop() = false;
    std::cout << "stack.bool.pop() = " << stack_bool.pop() << std::endl;

    stack_bool.print();


    return 0;
}