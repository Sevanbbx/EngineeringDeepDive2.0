#include <iostream>
#include <unistd.h>
#include <pthread.h>
#define THREAD_NUM 5


pthread_t threads[THREAD_NUM];

int arr[THREAD_NUM] = {1, 2, 3, 4, 5};

void* print_sum(void *arg) {
    int num = *(int*) arg;
    printf("The square of %d is %d \n", num, num * num);
    sleep(0);
    return NULL;
}


int main() {
    for(int i = 0; i < THREAD_NUM; ++i) {
        int* num = new int(arr[i]);
        pthread_create(&threads[i], NULL, print_sum, num);
    }

    for(int i = 0; i < THREAD_NUM; ++i) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}