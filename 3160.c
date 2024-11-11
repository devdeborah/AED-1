#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char listaL[100 * 50];
    char listaN[100 * 50];
    char listaS[50];

    fgets(listaL, sizeof(listaL), stdin);
    listaL[strcspn(listaL, "\n")] = '\0';

    fgets(listaN, sizeof(listaN), stdin);
    listaN[strcspn(listaN, "\n")] = '\0';

    fgets(listaS, sizeof(listaS), stdin);
    listaS[strcspn(listaS, "\n")] = '\0';

    char *amigos_atual[100];
    int quantidade_atual = 0;
    char *token = strtok(listaL, " ");
    while (token != NULL) {
        amigos_atual[quantidade_atual++] = token;
        token = strtok(NULL, " ");
    }

    char *novos_amigos[100];
    int quantidade_nova = 0;
    token = strtok(listaN, " ");
    while (token != NULL) {
        novos_amigos[quantidade_nova++] = token;
        token = strtok(NULL, " ");
    }

    int primeiro = 1;

    if (strcmp(listaS, "nao") == 0) {
        for (int i = 0; i < quantidade_atual; i++) {
            if (!primeiro) printf(" ");
            printf("%s", amigos_atual[i]);
            primeiro = 0;
        }
        for (int i = 0; i < quantidade_nova; i++) {
            printf(" %s", novos_amigos[i]);
        }
    } else {
        for (int i = 0; i < quantidade_atual; i++) {
            if (strcmp(amigos_atual[i], listaS) == 0) {
                for (int j = 0; j < quantidade_nova; j++) {
                    if (!primeiro) printf(" ");
                    printf("%s", novos_amigos[j]);
                    primeiro = 0;
                }
            }
            if (!primeiro) printf(" ");
            printf("%s", amigos_atual[i]);
            primeiro = 0;
        }
    }

    printf("\n");
    return 0;
}
