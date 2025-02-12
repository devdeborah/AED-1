#include <stdio.h>
 
int main (void) {
    double A, B, M, N;

    scanf("%lf", &A);
    scanf("%lf", &B);
    M = (3.5*A + 7.5*B) / 2;
    N = (10 * M) / 55;
    printf ("MEDIA = %.5lf\n", N);
    return 0;
}
