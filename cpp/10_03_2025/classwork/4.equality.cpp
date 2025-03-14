#include <iostream>

template <int A, int B>
struct Equality {
    static const bool value = A == B;
};

int main() {
    std::cout << Equality<5, 5>::value << std::endl;
    std::cout << Equality<5, 6>::value << std::endl;
    return 0;
}