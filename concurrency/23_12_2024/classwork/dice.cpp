#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <bits/stdc++.h>
#include <algorithm>

std::vector<int> results;
pthread_t thread1, thread2;
pthread_barrier_t barrier;
#define NUM_THREADS 10

int counter = 0;

void *dice_roll(void * arg) {
    sleep(1);
    int i = *(int*)arg;
    results[i] = rand() % 6 + 1;
    printf("Dice rolled: %d \n", results[i]);
    pthread_barrier_wait(&barrier);
    return NULL;
}


int main() {
    results.resize(NUM_THREADS);
    pthread_t threads[10];
    int max = 0;
    while (true) {
        pthread_barrier_init(&barrier, NULL, 10);
        for(int i = 0; i < NUM_THREADS; ++i) {
            int *index = new int(i);
            pthread_create(&threads[i], NULL, dice_roll, index);
        }
        // for(int i = 0; i < NUM_THREADS; ++i) {
        //     pthread_join(threads[i], NULL);
        // }
        max = *std::max_element(results.begin(), results.end());
        printf("Maximum is %d \n", max);
        
        sleep(3);
    }

    return 0;
}