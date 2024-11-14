//Aluna: DEBORAH NERI DOS REIS
#include <stdio.h>
#include <stdlib.h>
#define M 50000

int compara(const void *a, const void *b);
int busca(int *v, int tam, int chave);

int main(void) {
    int A, B;
    int filaInicial[M], saidas[M];
    int i, prim = 1;

    scanf("%d", &A);
    for (i = 0; i < A; i++) {
        scanf("%d", &filaInicial[i]);
    }
    scanf("%d", &B);
    for (i = 0; i < B; i++) {
        scanf("%d", &saidas[i]);
    }
    qsort(saidas, B, sizeof(int), compara);
    for (i = 0; i < A; i++) {
        if (!busca(saidas, B, filaInicial[i])) {
            if (!prim) {
                printf(" ");
            }
            printf("%d", filaInicial[i]);
            prim = 0;
        }
    }
    printf("\n");
    return 0;
}
int compara(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
int busca(int *v, int tam, int chave) {
    int inicio = 0, fim = tam - 1, meio;

    while(inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (v[meio] == chave)
            return 1;
        else if (v[meio] < chave)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }
    return 0;
}