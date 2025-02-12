#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int const TAM = 400000;

int part (int *, int, int);
void quickSort (int *, int, int);

int main (void) {
    clock_t t;
    int vetor[TAM];

    srand((unsigned)time(NULL));

    for(int a = 0; a < TAM; a++)
        vetor[a] = rand() % TAM;
    t = clock();
    quickSort(vetor, 0, TAM - 1);
    t = clock() - t;
    printf("Tempo de execucao: %lf ms\n", ((double)t / CLOCKS_PER_SEC) * 1000);
    return 0;
}
int part (int *v, int i, int f) {
    int e = i, d = f, p = v[i], aux;

    while (e < d) {
        while (v[e] <= p)
            e++;
        while (v[d] > p)
            d--;
        if (e < d) {
            aux = v[e];
            v[e] = v[d];
            v[d] = aux;
        }
    }
    v[i] = v[d];
    v[d] = p;
    return d;
}
void quickSort (int *v, int i, int f) {
    int p;

    if (f > i) {
        p = part(v, i, f);
        quickSort(v, i, p - 1);
        quickSort(v, p + 1, f);
    }
}
