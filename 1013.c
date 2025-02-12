#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main (void) {
  int x, y, z, c1, c2, m;

  scanf("%d %d %d", &x, &y, &z);
  c1 = (x + y + abs(x - y)) / 2;
  c2 = (c1 + z + abs(c1 - z)) / 2;
  printf("%d eh o maior\n", c2);
  return 0;
}
