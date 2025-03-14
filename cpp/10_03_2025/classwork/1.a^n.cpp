#include <iostream>

template <int A, int N>
struct Power {
    static const int value = A * Power<A, N - 1>::value;
};

template<int A>
struct Power<A, 0> {
    static const int value = 1;
};

int main() {
    std::cout << Power<2, 10>::value << std::endl;
    return 0;
}
