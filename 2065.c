#include <stdio.h>
#define MAX 20000

typedef struct Caixa {
  int tempo;
  int id;
  int vi;
} Caixa;

typedef struct FilaP {
  int qte;
  struct Caixa caixa[MAX];
} FilaP;

void rebaixar(FilaP*, int);
void inserir(FilaP*, Caixa);
int comparar(Caixa, Caixa);
int remover(FilaP*);

int main (void) {
  int N, M, r;
  FilaP fila;
  fila.qte = 0;

  scanf("%d %d", &N, &M);
  int v[MAX], c[MAX];
  for (int i = 0; i < N; i++) {
    scanf("%d", &v[i]);
  }
  for (int j = 0; j < M; j++) {
    scanf("%d", &c[j]);
  }
  for (int i = 0; i < N; i++) {
    Caixa novo = {0, i, v[i]};
    inserir(&fila, novo);
  }
  for (int j = 0; j < M; j++) {
    Caixa caixaAtual = fila.caixa[0];
    remover(&fila);
    caixaAtual.tempo += caixaAtual.vi * c[j];
    inserir(&fila, caixaAtual);
  }
  int tempoTotal = 0;
  while (fila.qte > 0) {
    if (fila.caixa[0].tempo > tempoTotal)
      tempoTotal = fila.caixa[0].tempo;
    remover(&fila);
  }
  printf("%d\n", tempoTotal);
  return 0;
}
void rebaixar (FilaP* fp, int i) {
  int menor = i;
  int esq = 2 * i + 1;
  int dir = 2 * i + 2;
  if (esq < fp->qte && comparar(fp->caixa[esq], fp->caixa[menor]) < 0)
    menor = esq;
  if (dir < fp->qte && comparar(fp->caixa[dir], fp->caixa[menor]) < 0)
    menor = dir;
  if (menor != i) {
    Caixa temp = fp->caixa[i];
    fp->caixa[i] = fp->caixa[menor];
    fp->caixa[menor] = temp;
    rebaixar(fp, menor);
  }
}
void inserir (FilaP* fp, Caixa novo) {
  int i = fp->qte++;

  fp->caixa[i] = novo;
  while (i > 0) {
    int pai = (i - 1) / 2;
    if (comparar(fp->caixa[i], fp->caixa[pai]) >= 0)
      break;
    Caixa temp = fp->caixa[i];
    fp->caixa[i] = fp->caixa[pai];
    fp->caixa[pai] = temp;
    i = pai;
  }
}
int comparar (Caixa a, Caixa b) {
  if (a.tempo < b.tempo)
    return -1;
  if (a.tempo > b.tempo)
    return 1;
  return a.id - b.id;
}
int remover (FilaP* fp) {
  if (fp == NULL || fp->qte == 0)
    return 0;
  fp->qte--;
  fp->caixa[0] = fp->caixa[fp->qte];
  rebaixar(fp, 0);
  return 1;
}
