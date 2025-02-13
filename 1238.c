#include <stdio.h>
#include <string.h>
#define TAM 51

int main (void) {
    char str1[TAM], str2[TAM], str3[TAM * 2 - 1], strAux[100];
    int i = 0, j = 0, v = 0, flagA = 1, flagB = 1, vzs;

    scanf("%d", &vzs);
    while (v < vzs) {
        fflush(stdin);
        scanf(" %s %s", str1, str2);
        while (flagA || flagB){
            if (str1[i] != '\0' && flagA) {
                str3[j] = str1[i];
                j++;
            } else {
                flagA = 0;
            }
            if (str2[i] != '\0' && flagB){
                str3[j] = str2[i];
                j++;
            } else {
                flagB = 0;
            }
            i++;
        }
        str3[j] = '\0';
        printf("%s\n", str3);
        v++;
        i = 0;
        j = 0;
        flagA = 1;
        flagB = 1;
    }
    return 0;
}
