//**
	* Aluna: DEBORAH NERI DOS REIS Turma: IA
	* Retorna o n-ésimo termo fornecido na entrada da lista.//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void minuscula (char []);
void quickSort (char V[][21], int, int);
int part (char V[][21], int i, int f);

int main (void) {
  int n, k;
  
  scanf("%d %d", &n, &k);
  char nomes[n][21];
  for (int i = 0; i < n; i++) {
    scanf("%s", nomes[i]);
    minuscula(nomes[i]);
  }
  quickSort(nomes, 0, n - 1);
  printf("%s\n", nomes[k - 1]);
  return 0;
}
void minuscula (char p[]) {
  int i = 0;
  while (p[i] != '\0') {
    p[i] = tolower(p[i]);
    i++;
  }
}
void quickSort (char V[][21], int i, int f) {
  if (i < f) {
    int pivo = part(V, i, f);
    quickSort(V, i, pivo - 1);
    quickSort(V, pivo + 1, f);
  }
}
int part (char V[][21], int i, int f) {
  char pivo[21];
  strcpy(pivo, V[i]);
  int e = i, d = f;
  char aux[21];
  while (e < d) {
    while (strcmp(V[e], pivo) <= 0 && e < f)
      e++;
    while (strcmp(V[d], pivo) > 0)
      d--;
    if (e < d) {
      strcpy(aux, V[e]);
      strcpy(V[e], V[d]);
      strcpy(V[d], aux);
    }
  }
  strcpy(V[i], V[d]);
  strcpy(V[d], pivo);
  return d;
}