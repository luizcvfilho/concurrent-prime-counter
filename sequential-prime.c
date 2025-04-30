#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <time.h>

int ehPrimo(long long int n) {
    int i;
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    for (i = 3; i < sqrt(n) + 1; i += 2)
        if (n % i == 0) return 0;
    return 1;
}

int main(int argc, char *argv[]) {
    long long int N;
    long long int prime_count = 0;
    double start;
    double end;
    int c;
    if (argc != 2) {
        fprintf(stderr, "Digite: %s <valor de N> \n", argv[0]);
        return 1;
    }
    N = atoll(argv[1]);

    start = clock();

    for (c = 0; c <= N; c++){
        if (ehPrimo(c)){
            prime_count++;
        }
    }

    end = clock();

    printf("N = %lld \n", N);
    printf("Quantidade de primos encontrados = %lld\n", prime_count);
    printf("Tempo: %.10f s\n", (end - start) / CLOCKS_PER_SEC);

    return 0;
}
