#include <stdio.h>
#include <string.h>

void criaPosfixo (char *prefixo, char *infixo, int tam, char *posfixo, int *idPosfixo) {
    if (tam <= 0) {
        return;
    }
    char raiz = prefixo[0];
    int idRaiz = 0;
    while (infixo[idRaiz] != raiz) {
        idRaiz++;
    }
    criaPosfixo(prefixo + 1, infixo, idRaiz, posfixo, idPosfixo);
    criaPosfixo(prefixo + 1 + idRaiz, infixo + 1 + idRaiz, tam - idRaiz - 1, posfixo, idPosfixo);
    posfixo[*idPosfixo] = raiz;
    (*idPosfixo)++;
}
int main (void) {
    int C;

    scanf("%d", &C);
    while (C--) {
        int N;
        char S1[53], S2[53];
        scanf("%d %s %s", &N, S1, S2);
        char posfixo[53];
        int idPosfixo = 0;
        criaPosfixo(S1, S2, N, posfixo, &idPosfixo);
        posfixo[idPosfixo] = '\0';
        printf("%s\n", posfixo);
    }
    return 0;
}
