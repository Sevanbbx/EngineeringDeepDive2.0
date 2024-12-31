#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#define NUM_ITERATIONS 1000000
// Shared counter
volatile int counter = 0;
pthread_mutex_t mutex_lock;
pthread_spinlock_t spin_lock;
sem_t sem_lock;

// Function for incrementing the counter (Critical Section)
void *increment_counter_mutex(void *arg) {
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        // Critical Section: Increment the shared counter
	// Use all 3 mechanisms to sync this section. Keep two of them commented out.
        pthread_mutex_lock(&mutex_lock);
        counter++;
        pthread_mutex_unlock(&mutex_lock);

    }
    return NULL;
}

void *increment_counter_spinlock(void *arg) {
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        // Critical Section: Increment the shared counter
	// Use all 3 mechanisms to sync this section. Keep two of them commented out.
        pthread_spin_lock(&spin_lock);
        counter++;
        pthread_spin_unlock(&spin_lock);

    }
    return NULL;
}

void *increment_counter_semaphore(void *arg) {
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        // Critical Section: Increment the shared counter
	// Use all 3 mechanisms to sync this section. Keep two of them commented out.
        sem_wait(&sem_lock);
        counter++;
        sem_post(&sem_lock);

    }
    return NULL;
}

void *increment_counter_triple_lock(void *arg) {
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        // Critical Section: Increment the shared counter
	// Use all 3 mechanisms to sync this section. Keep two of them commented out.
        pthread_spin_lock(&spin_lock);
        pthread_mutex_lock(&mutex_lock);
        sem_wait(&sem_lock);
        counter++;
        sem_post(&sem_lock);
        pthread_mutex_unlock(&mutex_lock);
        pthread_spin_unlock(&spin_lock);


    }
    return NULL;
}

int main() {
    // mutex
    pthread_t thread1, thread2;
    // Create two threads
    pthread_create(&thread1, NULL, increment_counter_mutex, NULL);
    pthread_create(&thread2, NULL, increment_counter_mutex, NULL);
    // Wait for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    // Print the final value of the counter
    printf("Final Counter: %d\n", counter);


    //spin lock
    counter = 0;
    // Create two threads
    pthread_create(&thread1, NULL, increment_counter_spinlock, NULL);
    pthread_create(&thread2, NULL, increment_counter_spinlock, NULL);
    // Wait for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    // Print the final value of the counter
    printf("Final Counter: %d\n", counter);

    //semaphore lock
    counter = 0;
    sem_init(&sem_lock, 0, 1);
    // Create two threads
    pthread_create(&thread1, NULL, increment_counter_semaphore, NULL);
    pthread_create(&thread2, NULL, increment_counter_semaphore, NULL);
    // Wait for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    // Print the final value of the counter
    printf("Final Counter: %d\n", counter);
    sem_destroy(&sem_lock);

    //triple lock
    counter = 0;
    sem_init(&sem_lock, 0, 1);
    // Create two threads
    pthread_create(&thread1, NULL, increment_counter_triple_lock, NULL);
    pthread_create(&thread2, NULL, increment_counter_triple_lock, NULL);
    // Wait for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    // Print the final value of the counter
    printf("Final Counter: %d\n", counter);
    sem_destroy(&sem_lock);
    return 0;

}
