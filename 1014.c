#include <stdio.h>

int main (void) {
  int X;
  float Y, T;

  scanf("%d %f", &X, &Y);
  T = X / Y;
  printf("%.3f km/l\n", T);
  return 0;
}
