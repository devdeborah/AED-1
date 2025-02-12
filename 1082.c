#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 26

typedef struct No {
  int vert;
  struct No* prox;
} No;

No* grafo[MAX];
int visitado[MAX];

void adiciona(int, int);
void buscaProf(int, char*);
void libera(int);

int main (void) {
  int N;

  scanf("%d", &N);
  for (int caso = 1; caso <= N; caso++) {
    int V, E;
    scanf ("%d %d", &V, &E);
    for (int i = 0; i < MAX; i++) {
      grafo[i] = NULL;
      visitado[i] = 0;
    }
    for (int i = 0; i < E; i++) {
      char u, v;
      scanf(" %c %c", &u, &v);
      adiciona(u -  'a', v - 'a');
    }
    printf("Case #%d:\n", caso);
    int comps = 0;
    for (int i = 0; i < V; i++) {
      if (!visitado[i]) {
        char comp[MAX + 1] = "";
        buscaProf(i, comp);
        for (int j = 0; j < strlen(comp) - 1; j++) {
          for (int k = j + 1; k < strlen(comp); k++) {
            if (comp[j] > comp[k]) {
              char temp = comp[j];
              comp[j] = comp[k];
              comp[k] = temp;
            }
          }
        }
        for (int j = 0; j < strlen(comp); j++) {
          printf ("%c,", comp[j]);
        }
        printf ("\n");
        comps++;
      }
    }
    printf ("%d connected components\n\n", comps);
    libera(V);
  }
  return 0;
}
void adiciona (int u, int v) {
  No* novo = (No*)malloc(sizeof(No));
  novo->vert = v;
  novo->prox = grafo[u];
  grafo[u] = novo;
  novo =(No*)malloc(sizeof(No));
  novo->vert = u;
  novo->prox = grafo[v];
  grafo[v] = novo;
}
void buscaProf (int v, char* c) {
  visitado[v] = 1;
  c[strlen(c)] = v + 'a';
  No* temp = grafo[v];
  while (temp != NULL) {
    if (!visitado[temp->vert]) {
      buscaProf(temp->vert, c);
    }
    temp = temp->prox;
  }
}
void libera (int V) {
  for (int i = 0; i < V; i++) {
    No* temp = grafo[i];
    while (temp != NULL) {
      No* aux = temp;
      temp = temp->prox;
      free(aux);
    }
    grafo[i] = NULL;
  }
}
