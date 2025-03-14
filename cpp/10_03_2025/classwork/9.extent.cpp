#include <iostream>

template <typename T>
struct extent {
    static const size_t value = 0;
};

template <typename T, size_t N>
struct extent<T[N]> {
    static const size_t value = N;
};


int main() {
    std::cout << "extent<int>::value = " << extent<int>::value << std::endl;
    std::cout << "extent<arr[4]>::value = " << extent<int[4]>::value << std::endl;
    return 0;
}