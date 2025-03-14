#include <iostream>

template <typename T>
struct decay {
    typedef T type;
};

template <typename Q, size_t N>
struct decay<Q[N]> {
    typedef Q type;
};

template <typename Q>
struct decay<Q*> {
    typedef Q type;
};


template <typename Q>
struct decay<const Q> {
    typedef Q type;
};

template <typename Q>
struct decay<Q const*> {
    typedef Q type;
};


int main() {
    int a = 5;
    int *b = &a;
    const int d = 10;
    decay<int*>::type c = a;
    decay<const int>::type e = d;
    e += 1;
    std::cout << "c = " << c << std::endl;
    std::cout << "e = " << e << std::endl;

    return 0;
}