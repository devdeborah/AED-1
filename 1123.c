#include <stdio.h>
#define MAX 250
#define INF 1000000000

typedef struct {
  int destino, custo;
} Aresta;

typedef struct {
  int cidade, custo, estado;
} No;

typedef struct {
  No heap[MAX * 2 * MAX];
  int tam;
} FilaP;

Aresta grafo[MAX][MAX];
int grau[MAX];
int dist[MAX][2];
int vis[MAX][2];

void troca(No *, No *);
void push(FilaP *, int, int, int);
No pop (FilaP *);
void dijkstra(int, int, int);

int main (void) {
  int N, M, C, K;

  while (1) {
    scanf("%d %d %d %d", &N, &M, &C, &K);
    if(N == 0 && M == 0 && C == 0 && K == 0)
      break;
    for (int i = 0; i < N; i++) {
      grau[i] = 0;
    }
    for (int i = 0; i < M; i++) {
      int u, v, p;
      scanf("%d %d %d", &u, &v, &p);
      grafo[u][grau[u]].destino = v;
      grafo[u][grau[u]].custo = p;
      grau[u]++;
      grafo[v][grau[v]].destino = u;
      grafo[v][grau[v]].custo = p;
      grau[v]++;
    }
    dijkstra(N, C, K);
    int result = dist[C - 1][1] < dist[C - 1][0] ? dist[C - 1][1] : dist[C - 1][0];
    printf("%d\n", result);
  }
  return 0;
}
void troca (No *a, No *b) {
  No temp = *a;
  *a = *b;
  *b = temp;
}
void push (FilaP *fp, int cid, int c, int est) {
  int i = fp->tam++;
  
  fp->heap[i].cidade = cid;
  fp->heap[i].custo = c;
  fp->heap[i].estado = est;
  while (i > 0) {
    int pai = (i - 1) / 2;
    if (fp->heap[pai].custo <= fp->heap[i].custo)
      break;
    troca(&fp->heap[pai], &fp->heap[i]);
    i = pai;
  }
}
No pop (FilaP *fp) {
  No min = fp->heap[0];
  
  fp->heap[0] = fp->heap[--fp->tam];
  int i = 0;
  while (1) {
    int menor = i, esq = 2 * i + 1, dir = 2 * i + 2;
    if (esq < fp->tam && fp->heap[esq].custo < fp->heap[menor].custo)
      menor = esq;
    if (dir < fp->tam && fp->heap[dir].custo < fp->heap[menor].custo)
      menor = dir;
    if (menor == i)
      break;
    troca(&fp->heap[i], &fp->heap[menor]);
    i = menor;
  }
  return min;
}
void dijkstra (int N, int C, int K) {
  FilaP fila;
  fila.tam = 0;

  for (int i = 0; i < N; i++) {
    dist[i][0] = INF;
    dist[i][1] = INF;
    vis[i][0] = 0;
    vis[i][1] = 0;
  }
  dist[K][0] = 0;
  push(&fila, K, 0, 0);
  while (fila.tam > 0) {
    No atual = pop(&fila);
    int u = atual.cidade;
    int cAtual = atual.custo;
    int est = atual.estado;
    if (vis[u][est])
      continue;
    vis[u][est] = 1;
    if (est == 0) {
      for (int i = 0; i < grau[u]; i++) {
        int v = grafo[u][i].destino;
        int custo = grafo[u][i].custo;
        if (v >= C) {
          if (dist[v][0] > cAtual + custo) {
            dist[v][0] = cAtual + custo;
            push(&fila, v, dist[v][0], 0);
          }
        } else {
          if (dist[v][1] > cAtual + custo) {
            dist[v][1] = cAtual + custo;
            push(&fila, v, dist[v][1], 1);
          }
        }
      }
    } else {
      if (u < C - 1) {
        for (int i = 0; i < grau[u]; i++) {
          int v = grafo[u][i].destino;
          int custo = grafo[u][i].custo;
          if (v == u + 1) {
            if (dist[v][1] > cAtual + custo) {
              dist[v][1] = cAtual + custo;
              push(&fila, v, dist[v][1], 1);
            }
          }
        }
      }
    }
  }
}
