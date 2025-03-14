#include <iostream>

template <typename T>
struct IsStaticArray {
    static const bool value = false;
};


template<typename T>
struct IsStaticArray<T[]> {
    static const bool value = true;
};


template<typename T, std::size_t N>
struct IsStaticArray<T[N]> {
    static const bool value = true;
};


int main() {
    int arr[3] = {1, 2, 3};
    int* ptr = arr;
    std::cout << "int: " << IsStaticArray<int>::value << std::endl;
    std::cout << "int*: " << IsStaticArray<int*>::value << std::endl;
    std::cout << "int[]: " << IsStaticArray<int[]>::value << std::endl;
    std::cout << "int[3]: " << IsStaticArray<int[3]>::value << std::endl;

    return 0;
}