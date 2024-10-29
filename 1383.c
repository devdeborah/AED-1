//DEBORAH NERI DOS REIS//
//Verifica soluções de Sudoku.//
#include <stdio.h>
#include <stdlib.h>
#define N 9

int verificaLinha (int matriz[N][N]);
int verificaColuna (int matriz[N][N]);
int verificaMatriz (int (*matriz)[N]);

int main(void) {
  int n, m[N][N];

  scanf ("%d", &n);
  if (n > 0) {
    for (int k = 1; k <= n; k++) {
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
        scanf("%d", &m[i][j]);
      }
    }
    printf ("Instancia %d\n", k);
    int l = verificaLinha(m);
    int c = verificaColuna(m);
    int s = verificaMatriz(m);
    if (l == 1 && c == 1 && s == 1) {
      printf ("SIM\n");
    } else {
      printf ("NAO\n");
    }
    printf("\n");
  }
} else {
    return 0;
  }
} 
int verificaLinha(int matriz[N][N]) {

  for (int i = 0; i < N; i++) {
    int flag[N] = {0};
    for (int j = 0; j < N; j++) {
      int n = matriz[i][j];
      if (n < 1 || n > N) {
        return 0;
      } else {
          if (flag[n - 1] == 1) {
            return 0;
          }
          flag[n - 1] = 1;
      }
    }
  }
  return 1;
}
int verificaColuna(int matriz[N][N]) {

  for (int j = 0; j < N; j++) {
    int flag[N] = {0};
    for (int i = 0; i < N; i++) {
      int n = matriz[i][j];
      if (n < 1 || n > N) {
        return 0;
      } else {
          if (flag[n - 1] == 1) {
            return 0;
          }
          flag[n - 1] = 1;
      }
    }
  }
  return 1;
}
int verificaMatriz(int (*matriz)[N]) {
  for (int inicioL = 0; inicioL < N; inicioL += 3) {
    for (int inicioC = 0; inicioC < N; inicioC += 3) {
      int flag[N] = {0};

      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          int n = *(*(matriz + inicioL + i) + inicioC + j);
          if (n < 1 || n > 9 || flag[n - 1] == 1) {
            return 0;
          }
          flag[n - 1] = 1;
        }
      }
    }
  }
  return 1;
}