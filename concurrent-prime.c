#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <time.h>

long long int N;
long long int next_num = 1;
long long int prime_count = 0;
pthread_mutex_t mutex;

// Uncomment if you want to when threads end
// #define PRINT_THREAD_END

int ehPrimo(long long int n) {
    int i;
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    for (i = 3; i < sqrt(n) + 1; i += 2)
        if (n % i == 0) return 0;
    return 1;
}


void *check_next(void *tid) {
    long int id = (long int) tid;
    long long int i;
    while (1) {
        pthread_mutex_lock(&mutex);
        i = next_num++;
        pthread_mutex_unlock(&mutex);

        if (i > N) break;

        if (ehPrimo(i)) {
            pthread_mutex_lock(&mutex);
            prime_count++;
            pthread_mutex_unlock(&mutex);
        }
    }

    #ifdef PRINT_THREAD_END
    printf("Thread %ld encerrada\n", id);
    #endif

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    double start;
    double end;
    int T;
    long int i;
    if (argc < 3) {
        fprintf(stderr, "Digite: %s <valor de N> <numero de threads> \n", argv[0]);
        return 1;
    }
    N = atoll(argv[1]);
    T = atoi(argv[2]);

    pthread_t *ths = malloc(sizeof(pthread_t)*T);
    pthread_mutex_init(&mutex, NULL);

    start = clock();

    for (i = 0; i < T; i++)
        if (pthread_create(&ths[i], NULL, check_next, (void *)i)) {
            printf("--ERRO: pthread_join() \n"); exit(-1); 
        } 
    for (i = 0; i < T; i++)
        if (pthread_join(ths[i], NULL)) {
            printf("--ERRO: pthread_join() \n"); exit(-1); 
        } 

    end = clock();

    printf("N = %lld, threads = %d\n", N, T);
    printf("Quantidade de primos encontrados = %lld\n", prime_count);
    printf("Tempo: %.10f s\n", (end - start) / CLOCKS_PER_SEC);

    pthread_mutex_destroy(&mutex);
    free(ths);
    return 0;
}
