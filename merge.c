#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int const TAM = 400000;

void merge (int *, int, int, int);
void mergeSort (int *, int, int);

int main (void) {
    clock_t t;
    int vetor[TAM];

    srand((unsigned)time(NULL));

    for(int a = 0; a < TAM; a++)
        vetor[a] = rand() % TAM;
    t = clock();
    mergeSort(vetor, 0, TAM - 1);
    t = clock() - t;
    printf("Tempo de execucao: %lf ms\n", ((double)t / CLOCKS_PER_SEC) * 1000);
    return 0;
}
void merge (int *v, int i, int m, int f) {
    int *aux, p1 = i, p2 = m + 1, t = f - i + 1, x, y, z;
    int f1 = 0, f2 = 0;

    aux = (int *) malloc(t * sizeof(int));
    if (aux != NULL) {
        for (x = 0; x < t; x++) {
            if(!f1 && !f2) {
                if (v[p1] < v[p2])
                    aux[x] = v[p1++];
                else
                    aux[x] = v[p2++];
                if (p1 > m)
                    f1 = 1;
                if (p2 > f)
                    f2 = 1;
            } else {
                if (!f1)
                    aux[x] = v[p1++];
                else
                    aux[x] = v[p2++];
            }
        }
        for (y = 0, z = i; y < t; y++, z++)
            v[z] = aux[y];
    }
    free(aux);
}
void mergeSort (int *v, int i, int f) {
    int m;
    
    if (i < f) {
        m = (i + f) / 2;
        mergeSort(v, i, m);
        mergeSort(v, m + 1, f);
        merge(v, i, m, f);
    }
}
