#include <iostream>
#include <pthread.h>
#include <vector>
#include <unistd.h>
#include <algorithm>

int const N = 5;

std::vector <int> tickets(N, 0);
std::vector <bool> being_used(N, false);


void* bakery_thread(void *arg) {
    int thread_id = *(int*) arg;
    being_used[thread_id] = true; // lock
    tickets[thread_id] = *std::max_element(tickets.begin(), tickets.end()) + 1;
    being_used[thread_id] = false; // unlock
    for (int i = 0; i < N; ++i) {
        if (i != thread_id) {
            while (being_used[i]);
            while (tickets[i] && (tickets[thread_id] > tickets[i] || (tickets[thread_id] == tickets[i] && thread_id > i)));
        }
    }
    //critical section
    for (int i = 0; i < 2; ++i) {
        std::cout << "Thread " << thread_id << " is in critical section" << std::endl;
        sleep(1);
    }
    //end of critical section
    tickets[thread_id] = 0;
    return NULL;
}


int main() {
    pthread_t threads[N];
    
    for (int i = 0; i < N; ++i) {
        pthread_create(&threads[i], NULL, bakery_thread, new int(i));
    }
    
    for (int i = 0; i < N; ++i) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}