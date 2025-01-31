#include <iostream>
#include <map>

std::map<int, int> memo;


int fibonacci(int n) {
    if (memo.find(n) != memo.end()) {
        return memo[n];
    }
    int fib_num = 0;
    switch(n) {
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 3;
    }


    if (n % 2 == 1) {
        fib_num =  pow(fibonacci(n/2), 2) + pow(fibonacci(n/2 + 1), 2);
    } else {
        fib_num = fibonacci(n/2) * (fibonacci(n/2 - 1) + fibonacci(n/2 + 1));
    }

    // if (n % 2 == 1) {
    //     fib_num =  pow(fibonacci(n/2), 2) + pow(fibonacci(n/2 + 1), 2);
    // } else {
    //     fib_num = fibonacci(n/2) * (2 * fibonacci(n/2 + 1) - fibonacci(n/2));
    // }
    if (memo.find(n) == memo.end()) {
        memo[n] = fib_num;
    }
    return fib_num;
}


int main() {
    for (int i = 1; i < 50; ++i) {
        std::cout << "fibonacci(" << i << "): " << fibonacci(i) << std::endl;
    }
    return 0;
}