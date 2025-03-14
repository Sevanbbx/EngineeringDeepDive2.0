#include <iostream>

template <typename T>
struct IsPointer {
    static const bool value = false;
};


template<typename T>
struct IsPointer<T*> {
    static const bool value = true;
};


int main() {
    std::cout << "int: " << IsPointer<int>::value << std::endl;
    std::cout << "int*: " << IsPointer<int*>::value << std::endl;
    std::cout << "int**: " << IsPointer<int**>::value << std::endl;
    std::cout << "int[5]: " << IsPointer<int[5]>::value << std::endl;
    
    return 0;
}