#include <stdio.h>
#include <string.h>

int contador (char *str) {
    int diamantes = 0;
    int pilha = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '<') {
            pilha++; 
        } else if (str[i] == '>' && pilha > 0) {
            diamantes++;
            pilha--;
        }
    }
    return diamantes;
}
int main (void) {
    int N;
    
    scanf("%d", &N);
    getchar();
    for (int i = 0; i < N; i++) {
        char str[1001];
        fgets(str, 1001, stdin);
        str[strcspn(str, "\n")] = '\0';
        int diamantes = contador(str);
        printf("%d\n", diamantes);
    }
    return 0;
}
