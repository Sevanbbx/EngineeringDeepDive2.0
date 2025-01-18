#include <pthread.h>
#include <stdio.h>

int x = 5;

bool T1_wants_to_enter = false;
bool T2_wants_to_enter = false;
int turn = 0;

void* increment(void* arg) {
        T1_wants_to_enter = true;
        turn = 2;
        while(T1_wants_to_enter && turn == 2) {};
        x++;
        T1_wants_to_enter = false;
    return NULL;
}

void* decrement(void* arg) {
        T2_wants_to_enter = true;
        turn = 1;
        while(T2_wants_to_enter && turn == 1) {};
        x--;
        T2_wants_to_enter = false;
    return NULL;
}

int main() {
    pthread_t tid1, tid2;

    for(int i = 0; i < 10; i++)
    {
        // Create threads
        pthread_create(&tid1, NULL, increment, NULL);
        pthread_create(&tid2, NULL, decrement, NULL);

        // Wait for threads to complete
        pthread_join(tid1, NULL);
        pthread_join(tid2, NULL);

        // Print the final value of x
        printf("Final value of x: %d\n", x);
    }


    return 0;
}
