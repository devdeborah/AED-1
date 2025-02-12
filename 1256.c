#include <stdio.h>
#include <stdlib.h>

typedef struct No {
  int chave;
  struct No* prox;
} No;

No* criar(int);
void inserir(No**, int, int);
void imprimir(No**, int);
void liberar(No**, int);

int main (void) {
  int N;

  scanf("%d", &N);
  for (int caso = 0; caso < N; caso++) {
    int M, C;
    scanf("%d %d", &M, &C);
    No** tab = (No**)malloc(M * sizeof(No*));
    if (tab == NULL) {
      exit(1);
    }
    for (int i = 0; i < M; i++)
      tab[i] = NULL;
    for (int j = 0; j < C; j++) {
      int chave;
      scanf("%d", &chave);
      inserir(tab, chave, M);
    }
    imprimir(tab, M);
    liberar(tab, M);
    if (caso < N - 1) {
      printf ("\n");
    }
  }
  return 0;
}
No* criar (int chave) {
  No* novo = (No*)malloc(sizeof(No));
  if (novo == NULL)
    exit(1);
  novo->chave = chave;
  novo->prox = NULL;
  return novo;
}
void inserir (No** tab, int chave, int M) {
  int i = chave % M;
  No* novo = criar(chave);

  if (tab[i] == NULL) {
    tab[i] = novo;
  } else {
    No* temp = tab[i];
    while (temp->prox != NULL) {
      temp = temp->prox;
    }
    temp->prox = novo;
  }
}
void imprimir (No** tab, int M) {
  for (int i = 0; i < M; i++) {
    printf ("%d ->", i);
    No* temp = tab[i];
    while (temp != NULL) {
      printf (" %d ->", temp->chave);
      temp = temp->prox;
    }
    printf(" \\\n");
  }
}
void liberar (No** tab, int M) {
  for (int i = 0; i < M; i++) {
    No* temp = tab[i];
    while (temp != NULL) {
      No* aux = temp;
      temp = temp->prox;
      free(aux);
    }
  }
  free(tab);
}
