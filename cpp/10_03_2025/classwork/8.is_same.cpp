#include <iostream>


template <typename A, typename B>
struct is_same {
    static const bool value = false;
};

template <typename A>
struct is_same<A, A> {
    static const bool value = true;
};


int main() {
    std::cout << "is_same<int, int>::value = " << is_same<int, int>::value << std::endl;
    std::cout << "is_same<int, float>::value = " << is_same<int, float>::value << std::endl;
    std::cout << "is_same<float, float>::value = " << is_same<float, float>::value << std::endl;
    return 0;
}