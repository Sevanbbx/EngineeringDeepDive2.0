#include <iostream>

template <typename T>
struct rank {
    static const size_t value = 0;
};

template <typename T, size_t N>
struct rank<T[N]>{
    static const size_t value = 1 + rank<T>::value;
};

int main() {
    std::cout << "rank<int>::value = " << rank<int>::value << std::endl;
    std::cout << "rank<int[4][3][2][1] = " << rank<int[4][3][2][1]>::value << std::endl;
    return 0;
}