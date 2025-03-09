#include <iostream>
#include <vector>


template <typename T>
void vector_print_helper(std::vector<T> vector, std::string inner_sep_left="", std::string inner_sep_right="") {
    std::cout << "[";
    for (int i = 0; i < vector.size(); ++i) {
        std::cout << inner_sep_left << vector[i] << inner_sep_right << ", ";
    }
    std::cout << "\b\b";
    std::cout <<"]" << std::endl;
}

template <typename K, typename V>
void vector_print_helper(std::vector<std::pair<K, V> > vector, std::string inner_sep_left="", std::string inner_sep_right="") {
    std::cout << "[";
    for (int i = 0; i < vector.size(); ++i) {
        std::cout << inner_sep_left << vector[i].first << ": " << vector[i].second << inner_sep_right << ", ";
    }
    std::cout << "\b\b";
    std::cout <<"]" << std::endl;
}

template <typename T>
void vector_print(std::vector<T> vector) {
    vector_print_helper(vector, "", "");
}


template<>
void vector_print(std::vector<std::string> vector) {
    vector_print_helper(vector, "\"", "\"");
}


template<>
void vector_print(std::vector<char> vector) {
    vector_print_helper(vector, "'", "'");
}


template<typename K, typename V>
void vector_print(std::vector<std::pair<K, V> > vector) {
    vector_print_helper(vector, "(", ")");
}


int main() {
    std::vector<int> int_vector = {1, 2, 3, 4, 5};
    std::vector<std::string> string_vector = {"Hello", "Kitty", "move", "on", "ok"};
    std::vector<char> char_vector = {'a', 'b', 'c', 'd', 'e'};
    std::vector<std::pair<int, std::string>> pair_vector = {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};

    vector_print(int_vector);
    vector_print(string_vector);
    vector_print(char_vector);
    vector_print(pair_vector);
    return 0;
}