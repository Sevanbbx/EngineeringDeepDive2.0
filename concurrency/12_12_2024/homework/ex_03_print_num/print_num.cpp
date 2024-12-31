#include <iostream>
#include <pthread.h>
#include <unistd.h>

#define THREAD_NUM 3


pthread_t threads[THREAD_NUM];

void *print_num(void *arg){
    int *id = (int*)arg;
    for(int i = 1; i <= 5; ++i) {
        printf("thread %d: %d \n", *id, i);
        sleep(1);
    }

    return NULL;
}

int main() {
    for(int i = 0; i < THREAD_NUM; ++i) {
        int *index = new int(i);
        pthread_create(&threads[i], NULL, print_num, index);
    }

    for(int i = 0; i < THREAD_NUM; ++i) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}