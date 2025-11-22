#include <stdio.h>
#include <pthread.h>

void* printMessage(void* arg) {
    int thread_id = *(int*)arg;   // Correct way to get the thread number
    printf("Thread %d is running...\n", thread_id);
    return NULL;
}

int main() {
    pthread_t threads[3];
    int thread_ids[3] = {1, 2, 3};

    // Creating 3 threads
    for (int i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, printMessage, &thread_ids[i]);
    }

    // Waiting for all threads to finish
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads have completed execution.\n");
    return 0;
}

