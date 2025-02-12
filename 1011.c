#include <stdio.h>
#include <math.h>

int main (void) {
  double r, e;

  scanf("%lf", &r);
  e = (4.0/3) * 3.14159 * pow(r, 3);
  printf ("VOLUME = %.3lf\n", e);
  return 0;
}
