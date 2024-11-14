#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct {
    char items[MAX];
    int top;
} Pilha;

void inicializarPilha(Pilha *p) { p->top = -1; }
int statusCheio(Pilha *p) { return p->top == MAX - 1; }
int statusVazio(Pilha *p) { return p->top == -1; }
void empilhar(Pilha *p, char value) { if (!statusCheio(p)) p->items[++(p->top)] = value; }
char desempilhar(Pilha *p) { return statusVazio(p) ? '\0' : p->items[(p->top)--]; }
char topoPilha(Pilha *p) { return statusVazio(p) ? '\0' : p->items[p->top]; }

int verificaParenteses(char *expressao) {
    Pilha pilha;
    inicializarPilha(&pilha);

    for (int i = 0; i < strlen(expressao); i++) {
        char c = expressao[i];

        if (c == '(' || c == '{' || c == '[') {
            empilhar(&pilha, c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            if (statusVazio(&pilha)) 
                return 0;

            char topo = topoPilha(&pilha);
            if ((c == ')' && topo == '(') || 
                (c == '}' && topo == '{') || 
                (c == ']' && topo == '[')) {
                desempilhar(&pilha);
            } else {
                return 0;
            }
        }
    }

    return statusVazio(&pilha);
}

int main(void) {
    char expressao[MAX];

    while (fgets(expressao, MAX, stdin)) {
        expressao[strcspn(expressao, "\n")] = '\0';

        if (verificaParenteses(expressao)) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }
    return 0;
}