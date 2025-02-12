#include <stdio.h>
#include <stdlib.h>

int compara (int, int, int, int);
int verificaSoma (int, int, int, int);

int main (void) {
  int a = 0, b = 0, c = 0, d = 0;

  scanf("%d %d %d %d", &a, &b, &c, &d);
  if (compara(a, b, c, d) && verificaSoma(a, b, c, d))
    printf("Valores aceitos\n");
  else
    printf("Valores nao aceitos\n");
  return 0;
}
int compara (int A, int B, int C, int D) {
  if (A %2 == 0 && B > C && D > A)
    return 1;
  else
    return 0;
}
int verificaSoma (int A, int B, int C , int D) {
  int s1 = A + B, s2 = C + D;
  if ((s2 > s1) && (C > 0 && D > 0))
    return 1;
  else
    return 0;
}
