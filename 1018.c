#include <stdio.h>
#include <stdlib.h>

int decomp (int, int *);

int main (void) {
  int n, not[7] = {0};

  scanf("%d", &n);
  if (n > 0 && n < 1000000) {
    printf ("%d\n", n);
    decomp(n, not);
  }
  return 0;
}
int decomp (int x, int *q) {
  int ced[7] = {100, 50, 20, 10, 5, 2, 1};

  for (int i = 0; i < 7; i++) {
    q[i] = x / ced[i];
    x %= ced[i];
    printf ("%d nota(s) de R$ %d,00\n", q[i], ced[i]);
  }
}
