#include <iostream>

template <int A, int B>
struct Max2 {
    static const int value = (A > B) ? A : B;
};


template <int A, int B, int C>
struct Max3 {
    static const int value = Max2<A, Max2<B, C>::value>::value;
};


int main() {
    std::cout << Max3<1, 2, 3>::value << std::endl;
    return 0;
}
