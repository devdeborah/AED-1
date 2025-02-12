#include <stdio.h>
#include <math.h>

int main (void) {
  double A, B, C, tri, c, tra, q, r;

  scanf ("%lf %lf %lf", &A, &B, &C);
  tri = (A * C) / 2;
  c = 3.14159 * pow(C, 2);
  tra = (A + B) * C/ 2;
  q = pow(B, 2);
  r = A * B;
  printf ("TRIANGULO: %.3lf\nCIRCULO: %.3lf\nTRAPEZIO: %.3lf\nQUADRADO: %.3lf\nRETANGULO: %.3lf\n", tri, c, tra, q, r);
  return 0;
}
