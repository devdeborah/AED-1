#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int const TAM = 400000;

void insertionSort (int *v, int n);

int main (void) {
    clock_t t;
    int vetor[TAM];

    srand((unsigned)time(NULL));

    for(int a = 0; a < TAM; a++)
        vetor[a] = rand() % TAM;
    t = clock();
    insertionSort(vetor, TAM);
    t = clock() - t;
    printf("Tempo de execucao: %lf ms\n", ((double)t / CLOCKS_PER_SEC) * 1000);
    return 0;
}
void insertionSort (int *v, int n) {
    int i, j, aux;
    
    for (i = 1; i < n; i++) {
        aux = v[i];
        for (j = i; (j > 0) && (aux < v[j - 1]); j--)
            v[j] = v[j - 1];
        v[j] = aux;
    }
}
