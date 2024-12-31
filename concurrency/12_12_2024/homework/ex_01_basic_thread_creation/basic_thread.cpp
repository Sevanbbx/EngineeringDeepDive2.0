#include <iostream>
#include <pthread.h>

pthread_t threads[3];

void *my_thread(void *arg) {
    int* id = (int*)arg;
    printf("Thread %d is running \n", *id);

    return NULL;
}

int main() {
    for(int i = 0; i < 3; ++i) {
        int* a = new int(i);
        pthread_create(&threads[i], NULL, my_thread, a);
    }
    for(int i = 0; i < 3; ++i) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}