#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char val;
    struct No *esq;
    struct No *dir;
} No;

No* criaNo(char v);
No* inserir(No* raiz, char v);
void infixa(No* raiz, int* primeiro);
void prefixa(No* raiz, int* primeiro);
void posfixa(No* raiz, int* primeiro);
int pesquisar(No* raiz, char v);
void liberar(No* raiz);

int main (void) {
    No* raiz = NULL;
    char op[10], valor;

    while (scanf("%s", op) != EOF) {
        if (strcmp(op, "I") == 0) {
            scanf(" %c", &valor);
            raiz = inserir(raiz, valor);
        } else {
            if (strcmp(op, "INFIXA") == 0) {
                int primeiro = 1;
                infixa(raiz, &primeiro);
                printf("\n");
            } else { 
                if (strcmp(op, "PREFIXA") == 0) {
                    int primeiro = 1;
                    prefixa(raiz, &primeiro);
                    printf("\n");
                } else { 
                    if (strcmp(op, "POSFIXA") == 0) {
                        int primeiro = 1;
                        posfixa(raiz, &primeiro);
                        printf("\n");
                    } else {
                        if (strcmp(op, "P") == 0) {
                            scanf(" %c", &valor);
                            if (pesquisar(raiz, valor)) {
                                printf("%c existe\n", valor);
                            } else {
                                printf("%c nao existe\n", valor);
                            }
                        }
                    }
                }
            }
        }
    }
    liberar(raiz);
    return 0;
}
No* criaNo(char v) {
    No* novo = (No*)malloc(sizeof(No));
    novo->val = v;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}
No* inserir(No* raiz, char v) {
    if (raiz == NULL) {
        return criaNo(v);
    }
    if (v < raiz->val) {
        raiz->esq = inserir(raiz->esq, v);
    } else if (v > raiz->val) {
        raiz->dir = inserir(raiz->dir, v);
    }
    return raiz;
}
void infixa(No* raiz, int* primeiro) {
    if (raiz == NULL) {
        return;
    }
    infixa(raiz->esq, primeiro);
    if (*primeiro) {
        printf("%c", raiz->val);
        *primeiro = 0;
    } else {
        printf(" %c", raiz->val);
    }
    infixa(raiz->dir, primeiro);
}
void prefixa(No* raiz, int* primeiro) {
    if (raiz == NULL) {
        return;
    }
    if (*primeiro) {
        printf("%c", raiz->val);
        *primeiro = 0;
    } else {
        printf(" %c", raiz->val);
    }
    prefixa(raiz->esq, primeiro);
    prefixa(raiz->dir, primeiro);
}
void posfixa(No* raiz, int* primeiro) {
    if (raiz == NULL) {
        return;
    }
    posfixa(raiz->esq, primeiro);
    posfixa(raiz->dir, primeiro);
    if (*primeiro) {
        printf("%c", raiz->val);
        *primeiro = 0;
    } else {
        printf(" %c", raiz->val);
    }
}
int pesquisar(No* raiz, char v) {
    if (raiz == NULL) {
        return 0;
    }
    if (v == raiz->val) {
        return 1;
    }
    if (v < raiz->val) {
        return pesquisar(raiz->esq, v);
    } else {
        return pesquisar(raiz->dir, v);
    }
}
void liberar(No* raiz) {
    if (raiz == NULL) {
        return;
    }
    liberar(raiz->esq);
    liberar(raiz->dir);
    free(raiz);
}
