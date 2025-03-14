#include <iostream>

template <int N, int M = 0>
struct NumberOfDigits {
    static const int value = 1 + NumberOfDigits<N / 10, M + 1>::value;
};

template <int M>
struct NumberOfDigits<0, M> {
    static const int value = 1 ? M == 0 : 0;
};

int main() {
    std::cout << "Number of digits: " << 1234 << ": " << NumberOfDigits<1234>::value << std::endl;
    std::cout << "Number of digits: " << 0 << ": " << NumberOfDigits<1>::value << std::endl;
    std::cout << "Number of digits: " << 1 << ": " << NumberOfDigits<1>::value << std::endl;
    std::cout << "Number of digits: " << 123456789 << ": " << NumberOfDigits<123456789>::value << std::endl;
    return 0;
}