#include <stdio.h>

int main (void) {
  int id, t;
  float v, s;

  scanf("%d", &id);
  scanf("%d", &t);
  scanf("%f", &v);
  s = v * t;
  printf("NUMBER = %d\nSALARY = U$ %.2f\n", id, s);
  return 0;
}
