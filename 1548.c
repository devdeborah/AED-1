#include <stdio.h>
#include <stdlib.h>

int comparar(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main (void) {
    int N;
    
    scanf("%d", &N);
    while (N--) {
        int M;
        scanf("%d", &M);
        int notas[M], notasOrd[M];
        for (int i = 0; i < M; i++) {
            scanf("%d", &notas[i]);
            notasOrd[i] = notas[i];
        }
        qsort(notasOrd, M, sizeof(int), comparar);
        int cont = 0;
        for (int i = 0; i < M; i++) {
            if (notas[i] == notasOrd[i]) {
                cont++;
            }
        }
        printf("%d\n", cont);
    }
    return 0;
}
