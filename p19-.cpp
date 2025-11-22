#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock;
int counter = 0;

void *func() {
    pthread_mutex_lock(&lock);
    counter++;
    printf("Counter = %d\n", counter);
    pthread_mutex_unlock(&lock);
}

int main() {
    pthread_t t1, t2;

    pthread_mutex_init(&lock, NULL);

    pthread_create(&t1, NULL, func, NULL);
    pthread_create(&t2, NULL, func, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}

