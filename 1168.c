#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void) {
   int N, cont;
   int i, j;
   char S[1110];

   scanf("%d", &N);
   for (i = 0; i < N; i++) {
      cont = 0;
      scanf("%s", S);
      for (j = 0; j < strlen(S); j++) {
         if (S[j] == '1') cont += 2;
         else if (S[j] == '2' || S[j] == '3' || S[j] == '5') cont += 5;
         else if (S[j] == '4') cont += 4;
         else if (S[j] == '6' || S[j] == '9' || S[j] == '0') cont += 6;
         else if (S[j] == '7') cont += 3;
         else if (S[j] == '8') cont += 7;
      }
      printf("%d leds\n", cont);
   }
    return 0;
}
