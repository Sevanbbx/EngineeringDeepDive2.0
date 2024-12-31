#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>


sem_t empty_spots;

pthread_t threads[10];
int thread_amount = 20;

void *play_game(void *arg) {
    int* args = (int*)arg;
    printf("Gamer trying to enter: %d \n", *args);
    sem_wait(&empty_spots);
    printf("Gamer entered: %d \n", *args);
    sleep(rand() % 10 + 1);
    sem_post(&empty_spots);
    printf("Gamer left %d \n", *args);

    return NULL;
}


int main(){
    sem_init(&empty_spots, 0, 10);
    for(int i = 0; i < thread_amount; ++i) {
        int *a = new int(i);
        pthread_create(&threads[i], NULL, play_game, a);
    }

    for(int i = 0; i < thread_amount; ++i) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}