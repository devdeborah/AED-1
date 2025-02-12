#include <stdio.h>
#include <string.h>

void tiraEnter (char a[10]);

int main (void) {
  char n[10];
  double sal, t, f;

  fgets(n, sizeof(n), stdin);
  tiraEnter(n);
  scanf ("%lf", &sal);
  scanf ("%lf", &t);
  f = sal + 0.15 * t;
  printf ("TOTAL = R$ %.2lf\n", f);
  return 0;
}
void tiraEnter (char a[10]) {
  int t = strlen(a);
  if (a[t] == '\n')
    a[t] = '\0';
}
