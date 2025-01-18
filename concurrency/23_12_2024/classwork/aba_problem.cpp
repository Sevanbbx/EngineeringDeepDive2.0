#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <bits/stdc++.h>

std::vector<char> statuses;
pthread_mutex_t mutex_lock;
pthread_t thread1, thread2;

int counter = 0;

void *writer(void * arg) {
    while (true){
        if (counter % 2 == 0) {
            printf("Added A: %d \n", counter);
            statuses.push_back('A');
        } else {
            printf("Added B: %d \n", counter);
            statuses.push_back('B');
        }
        ++counter;
        sleep(1);
    }
    return NULL;
}


void *reader(void * arg) {
    int index = 0;
    while (true){
        if (index >= statuses.size())
            continue;
        
        if (statuses[index] == 'B') {
            printf("%c: %d \n", statuses[index], index);
        }
        ++index;
        sleep(2);
    }
    return NULL;
}

int main() {
    pthread_create(&thread1, NULL, writer, NULL);
    pthread_create(&thread2, NULL, reader, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}