#include <iostream>

void print_reverse() {
    std::cout << std::endl;
}

template<typename HeadType, typename... Types>
void print_reverse(const HeadType& head, Types... body) {
    print_reverse(body...);
    std::cout << " " << head;
}

int main() {
    print_reverse(1, 2, 3, 4, 5);
    return 0;
}