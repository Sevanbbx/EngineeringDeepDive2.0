#include <iostream>

template <typename T>
struct type_name_printer {
    static void print() {
        std::cout << "Unknown type" << std::endl;
    }
};

template <>
struct type_name_printer<int> {
    static void print() {
        std::cout << "int";
    }
};

template <>
struct type_name_printer<float> {
    static void print() {
        std::cout << "float";
    }
};

template <>
struct type_name_printer<double> {
    static void print() {
        std::cout << "double";
    }
};

template <>
struct type_name_printer<char> {
    static void print() {
        std::cout << "char";
    }
};

template <typename T, size_t N>
struct type_name_printer<T[N]> {
    static void print() {
        type_name_printer<T>::print();
        std::cout << "[" << N << "]";
    }
};

template <typename T>
struct type_name_printer<T*> {
    static void print() {
        type_name_printer<T>::print();
        std::cout << "*";
    }
};

template <typename T>
struct type_name_printer<const T> {
    static void print() {
        std::cout << "const ";
        type_name_printer<T>::print();
    }
};

int main() {
    type_name_printer<int>::print();
    std::cout << std::endl;
    type_name_printer<int*>::print();
    std::cout << std::endl;
    type_name_printer<const int>::print();
    std::cout << std::endl;
    type_name_printer<const int*>::print();
    std::cout << std::endl;
    type_name_printer<int[5]>::print();
    std::cout << std::endl;
    return 0;
}