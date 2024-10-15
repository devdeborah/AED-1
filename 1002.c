//DEBORAH NERI DOS REIS
//Calcula a área de uma circunferência a partir de um raio R.
#include <stdio.h>
#include <math.h>
 
int main() {
    double R;
    scanf("%lf", &R);
    double A = 3.14159 * (R*R);
    printf("A=%.4lf\n", A);
    return 0;
}
