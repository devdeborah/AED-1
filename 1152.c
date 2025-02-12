#include <stdio.h>
#include <stdlib.h>
#define MAX 200000

typedef struct {
  int u, v, peso;
} Aresta;

Aresta arestas[MAX];
int pai[MAX], rank[MAX];

int compara(const void *, const void *);
void inicializa(int);
int encontra(int);
void uniao(int, int);

int main (void) {
  int m, n;

  while (1) {
    scanf("%d %d", &m, &n);
    if (m == 0 && n == 0)
      break;
    int cTotal = 0, cMST = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d %d %d", &arestas[i].u, &arestas[i].v, &arestas[i].peso);
      cTotal += arestas[i].peso;
    }
    qsort(arestas, n, sizeof(Aresta), compara);
    inicializa(m);
    for (int i = 0; i < n; i++) {
      int u = arestas[i].u;
      int v = arestas[i].v;
      int peso = arestas[i].peso;
      if (encontra(u) != encontra(v)) {
        uniao(u, v);
        cMST += peso;
      }
    }
    printf("%d\n", cTotal - cMST);
  }
  return 0;
}
int compara (const void *a, const void *b) {
  return ((Aresta *)a)->peso - ((Aresta *)b)->peso;
}
void inicializa (int n) {
  for (int i = 0; i < n; i++) {
    pai[i] = i;
    rank[i] = 0;
  }
}
int encontra (int x) {
  if (pai[x] != x)
    pai[x] = encontra(pai[x]);
  return pai[x];
}
void uniao (int x, int y) {
  int ox = encontra(x);
  int oy = encontra(y);

  if (ox != oy) {
    if (rank[ox] < rank[oy]) {
      pai[ox] = oy;
    } else {
      if (rank[ox] > rank[oy]) {
        pai[oy] = ox;
      } else {
        pai[oy] = ox;
        rank[ox]++;
      }
    }
  }
}
