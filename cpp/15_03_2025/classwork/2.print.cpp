#include <iostream>

template<typename T, T TailValue >
void print()
{
	std::cout << " " << TailValue << std::endl;
}

template<typename T, T Value1, T Value2, T... Values >
void print()
{
	std::cout << " " << Value1;
	print<T, Value2, Values... >();
}

int main() {
	print<int, 1, 2, 3, 4, 5, 6>();
	print<char, '1', '2', '3', '4', '5', '6'>();
    return 0;
}
