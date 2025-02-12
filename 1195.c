#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int val;
    struct No *esq;
    struct No *dir;
} No;

No* criaNo(int);
No* inserir(No*, int);
void prefixo(No*);
void ordenar(No*);
void posfixo(No*);
void liberar(No*);


int main (void) {
    int C;

    scanf("%d", &C);
    for (int i = 1; i <= C; i++) {
        int N;
        scanf("%d", &N);
        No* raiz = NULL;
        for (int j = 0; j < N; j++) {
            int valor;
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
        }
        printf("Case %d:\n", i);
        printf("Pre.:");
        prefixo(raiz);
        printf("\n");
        printf("In..:");
        ordenar(raiz);
        printf("\n");
        printf("Post:");
        posfixo(raiz);
        printf("\n");
        printf("\n");
        liberar(raiz);
    }
    return 0;
}
No* criaNo(int v) {
    No* novo = (No*)malloc(sizeof(No));
    novo->val = v;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}
No* inserir(No* raiz, int v) {
    if (raiz == NULL) {
        return criaNo(v);
    }
    if (v < raiz->val) {
        raiz->esq = inserir(raiz->esq, v);
    } else {
        raiz->dir = inserir(raiz->dir, v);
    }
    return raiz;
}
void prefixo(No* raiz) {
    if (raiz == NULL) {
        return;
    }
    printf(" %d", raiz->val);
    prefixo(raiz->esq);
    prefixo(raiz->dir);
}
void ordenar(No* raiz) {
    if (raiz == NULL) {
        return;
    }
    ordenar(raiz->esq);
    printf(" %d", raiz->val);
    ordenar(raiz->dir);
}
void posfixo(No* raiz) {
    if (raiz == NULL) {
        return;
    }
    posfixo(raiz->esq);
    posfixo(raiz->dir);
    printf(" %d", raiz->val);
}
void liberar(No* raiz) {
    if (raiz == NULL) {
        return;
    }
    liberar(raiz->esq);
    liberar(raiz->dir);
    free(raiz);
}
