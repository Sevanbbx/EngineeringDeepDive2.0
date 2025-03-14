#include <iostream>

template <typename T>
struct remove_extent {
    typedef T type;
};

template <typename Q, size_t N>
struct remove_extent<Q[N]> {
    typedef Q type;
};

int main() {
    int a[5] = {1, 2, 3, 4, 5};
    remove_extent<int[5]>::type b = a[0];
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    return 0;
}