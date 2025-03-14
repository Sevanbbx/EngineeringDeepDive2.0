#include <iostream>

template <int X>
struct Abs {
    static const int value = (X < 0) ? -X : X;
};


int main() {
    std::cout << Abs<-5>::value << std::endl;
    std::cout << Abs<5>::value << std::endl;
    return 0;
}