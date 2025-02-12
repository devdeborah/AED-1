#include <stdio.h>

int main (void) {
  int t, v;
  float g;

  scanf("%d %d", &t, &v);
  g = (v * t) / 12.0;
  printf("%.3f\n", g);
  return 0;
}
