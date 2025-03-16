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

template <typename Array, int... Indices>
struct multi_array_accessor {
    static_assert(false, "Implementation is placed only in the specializations.");
};

template <typename T, int Ext1, int... Extents, int Index1, int... Indices>
struct multi_array_accessor<multi_array<T, Ext1, Extents...>, Index1, Indices...> {
    typedef multi_array_accessor<multi_array<T, Extents...>, Indices...>::type type;
    static type& access(multi_array<T, Ext1, Extents...>& array) {
        return multi_array_accessor<multi_array<T, Extents...>, Indices...>::access(array.data[Index1]);
    }
};

template <typename T, int Ext1>
struct multi_array_accessor<multi_array<T, Ext1>> {
    typedef T type;
    static type& access(multi_array<T, Ext1>& array) {
        return array.data;
    }
};

template <typename T>
struct multi_array_accessor<multi_array<T>> {
    typedef T type;
    static type& access(multi_array<T>& array) {
        return array.data;
    }
};

int main() {
    multi_array<float, 5, 4, 3> y;

    multi_array_accessor<decltype(y), 2, 0, 1>::access(y) = 5.27f;
    std::cout << "multi_array_accessor<decltype(y), 2, 0, 1>::access(y) = " << multi_array_accessor<decltype(y), 2, 0, 1>::access(y) << std::endl;

    std::cout << "multi_array_accessor<decltype(y), 2, 0, 1>::access(y) = " << multi_array_accessor<decltype(y), 2, 0, 0>::access(y) << std::endl;
    return 0;
}