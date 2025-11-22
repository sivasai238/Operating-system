#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5

pthread_mutex_t forks[N];

void *philosopher(void *num) {
    int id = *(int *)num;

    while(1) {
        printf("Philosopher %d is thinking\n", id);
        sleep(1);

        // Pick left fork
        pthread_mutex_lock(&forks[id]);
        printf("Philosopher %d picked left fork\n", id);

        // Pick right fork
        pthread_mutex_lock(&forks[(id+1)%N]);
        printf("Philosopher %d picked right fork\n", id);

        // Eat
        printf("Philosopher %d is eating\n", id);
        sleep(1);

        // Put down forks
        pthread_mutex_unlock(&forks[id]);
        pthread_mutex_unlock(&forks[(id+1)%N]);
        printf("Philosopher %d finished eating\n", id);
    }
}

int main() {
    pthread_t tid[N];
    int ids[N];

    for(int i=0; i<N; i++)
        pthread_mutex_init(&forks[i], NULL);

    for(int i=0; i<N; i++) {
        ids[i] = i;
        pthread_create(&tid[i], NULL, philosopher, &ids[i]);
    }

    for(int i=0; i<N; i++)
        pthread_join(tid[i], NULL);

    return 0;
}

