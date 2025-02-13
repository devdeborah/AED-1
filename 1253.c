#include <stdio.h>
#include <string.h>

void decodifica (char f[], int desloc, char decodificada[]) {
    char c;
    char alfabeto[27] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int tam = strlen(f), id, pos, i, j;

    for (i = 0; i < tam; i++) {
        c = f[i];
        for (j = 0; j < 27; j++) {
            if (c == alfabeto[j]){
                id = j;
                break;
            }
        }
        pos = id - desloc;
        if (pos < 0) {
            pos = 27 - (desloc - id + 1);
        } 
        decodificada[i] = alfabeto[pos];
    }
    decodificada[i] = '\0';
}

int main (void) {
    int n, d = 0;
    char frase[51], fDecodificada[51];
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        fflush(stdin);
        scanf("%s", frase);
        scanf("%d", &d);
        decodifica(frase, d, fDecodificada);
        printf ("%s\n", fDecodificada);
    }
    return 0;
}
