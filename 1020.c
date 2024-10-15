//DEBORAH NERI DOS REIS
//Retorna o cálculo simples de uma idade (recebida em dias inteiros) subdividido em anos, meses e dias.
#include <stdio.h>

int main(void) {
    int id, a, m, d;
    scanf("%d", &id);
    a = id/365;
    int ra = id % 365;
    m = ra/30;
    int rm = ra % 30;
    d = rm;
    printf ("%d ano(s)\n%d mes(es)\n%d dia(s)\n", a, m, d);
    return 0;
}
