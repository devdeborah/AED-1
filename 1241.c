#include <stdio.h>
#include <string.h>
#define TAM 1000

int main (void) {
    char a[TAM], b[TAM];
    int N, tamA, tamB, i, j = 0, verif = 1, vzs = 0; 

    scanf("%d", &N);
    fflush(stdin);
    while (vzs < N) {
        scanf(" %s %s", a, b);
        tamA = strlen(a);
        tamB = strlen(b);
        for (i = (tamA - tamB); i < tamA; i++) {
            if (a[i] != b[j]) {
                verif = 0;
                break;
            }
            j++;
        }
        if (verif == 1) {
            printf("encaixa\n");
        } else {
            printf("nao encaixa\n");
        }
        j = 0;
        vzs++;
        verif = 1;
    }
    return 0;
}
