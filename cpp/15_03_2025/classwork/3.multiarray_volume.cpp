#include <iostream>


template <typename T, int... Extents>
struct multi_array {
    static_assert(false, "Implementation is placed only in the specializations.");
};

template <typename T, int Ext1, int... Extents>
struct multi_array<T, Ext1, Extents...> {
    static constexpr int size =  Ext1 * multi_array<T, Extents...>::size;
    multi_array<T, Extents...> data[Ext1];
};

template <typename T>
struct multi_array<T> {
    static constexpr int size = 1;
    T data;
};

int main() {
    multi_array<float, 5, 4, 3> y;

    y.data[2].data[0].data[1].data = 5.27f;

    static_assert(sizeof(y) == sizeof(float) * 5 * 4 * 3, "Check of size of 'multi_array' failed.");

    std::cout << "y.data[2].data[0].data[1].data = " << y.data[2].data[0].data[1].data << std::endl;
    std::cout << "y.size = " << y.size << std::endl;

    return 0;
}