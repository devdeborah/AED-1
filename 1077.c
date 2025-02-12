#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct pilhaNo {
    char val;
    struct pilhaNo* baixo;
};

struct pilha {
    int tam;
    struct pilhaNo* topo;
};

void push (struct pilha* p, char valor) {
    struct pilhaNo* novoTopo = (struct pilhaNo*)malloc(sizeof(struct pilhaNo));
    if (!novoTopo) exit(1);
    novoTopo->val = valor;
    novoTopo->baixo = p->topo;
    p->topo = novoTopo;
    p->tam++;
}

void pop (struct pilha* p) {
    if (p->tam > 0) {
        struct pilhaNo* velhoTopo = p->topo;
        p->topo = p->topo->baixo;
        free(velhoTopo);
        p->tam--;
    }
}

char topo (struct pilha* p) {
    return p->topo ? p->topo->val : '\0';
}

int vazio (struct pilha* p) {
    return p->tam == 0;
}

void inicializa (struct pilha* p) {
    p->tam = 0;
    p->topo = NULL;
}

void destroi (struct pilha* p) {
    while (!vazio(p)) pop(p);
}

int precedencia (char operador) {
    switch (operador) {
        case '^':   return 3;
        case '*':
        case '/':   return 2;
        case '+':
        case '-':   return 1;
        default:    return 0;
    }
}

int main (void) {
    int N;
    struct pilha p;
    char expressao[301];

    scanf("%d", &N);
    while (getchar() != '\n');

    for (int k = 0; k < N; ++k) {
        scanf("%s", expressao);

        inicializa(&p);
        int tam = strlen(expressao);

        for (int i = 0; i < tam; ++i) {
            if (isalpha(expressao[i]) || isdigit(expressao[i])) {
                printf("%c", expressao[i]);
            } else if (expressao[i] == '(') {
                push(&p, expressao[i]);
            } else if (expressao[i] == ')') {
                while (!vazio(&p) && topo(&p) != '(') {
                    printf("%c", topo(&p));
                    pop(&p);
                }
                if (!vazio(&p)) pop(&p);
            } else {
                while (!vazio(&p) && topo(&p) != '(' && 
                       (precedencia(expressao[i]) < precedencia(topo(&p)) || 
                       (expressao[i] != '^' && precedencia(expressao[i]) == precedencia(topo(&p))))) {
                    printf("%c", topo(&p));
                    pop(&p);
                }
                push(&p, expressao[i]);
            }
        }

        while (!vazio(&p)) {
            printf("%c", topo(&p));
            pop(&p);
        }
        printf("\n");
        destroi(&p); 
    }
    return 0;
}
