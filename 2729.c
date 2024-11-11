#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITENS 1000
#define MAX_LEN 21

int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    int N;
    scanf("%d", &N);

    getchar();

    for (int i = 0; i < N; i++) {
        char linha[MAX_ITENS * MAX_LEN];
        char *itens[MAX_ITENS];
        int contador = 0;

        fgets(linha, sizeof(linha), stdin);

        char *palavra = strtok(linha, " \n");
        while (palavra != NULL) {
            int ja_existe = 0;
            for (int j = 0; j < contador; j++) {
                if (strcmp(itens[j], palavra) == 0) {
                    ja_existe = 1;
                    break;
                }
            }
            if (!ja_existe) {
                itens[contador] = palavra;
                contador++;
            }
            palavra = strtok(NULL, " \n");
        }
        qsort(itens, contador, sizeof(char *), compare);

        for (int j = 0; j < contador; j++) {
            if (j > 0) {
                printf(" ");
            }
            printf("%s", itens[j]);
        }
        printf("\n");
    }
    return 0;
}
