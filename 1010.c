#include <stdio.h>

int main (void) {
  int c1, n1, c2, n2;
  float v1, v2, f1, f2, t;

  scanf("%d %d %f", &c1, &n1, &v1);
  scanf("%d %d %f", &c2, &n2, &v2);
  f1 = n1 * v1;
  f2 = n2 * v2;
  t = f1 + f2;
  printf ("VALOR A PAGAR: R$ %.2f\n", t);
  return 0;
}
