#include <iostream>

template <typename T>
struct add_pointer{ 
    typedef T* type;
};

int main() {
    int a = 5;
    add_pointer<int>::type b = &a;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "*b = " << *b << std::endl;

    return 0;
}