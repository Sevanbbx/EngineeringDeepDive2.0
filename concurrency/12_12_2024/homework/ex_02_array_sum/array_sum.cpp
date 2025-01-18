#include <iostream>
#include <pthread.h>

pthread_t threads[2];

int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

struct Range {
    int start;
    int end;
};

void *calc_sum_by_range(void *arg) {
    double sum = 0;
    Range* range = (Range*)arg;
    for(int i = range->start; i < range->end; ++i) {
        sum += arr[i];
    }
    printf("Sum is: %.2f \n", sum);
    return NULL;
}

int main() {
    Range* range_1 = new Range();
    Range* range_2 = new Range();

    range_1->start = 0;
    range_1->end = 5;
    range_2->start = 5;
    range_2->end = 10;
    pthread_create(&threads[0], NULL, calc_sum_by_range, range_1);
    pthread_create(&threads[1], NULL, calc_sum_by_range, range_2);
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
    return 0;
}