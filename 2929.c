#include <stdio.h>

int min[1000000];

int main (void) {
    char op[4];
    int N, V, minimo, p;

    p = -1;
    scanf("%d\n", &N);
    for (int i = 0; i < N; ++i) {
    	scanf("%s", &op);

        if (!memcmp(op, "PUSH", 4)) {
        	scanf("%d\n", &V);
            if (p == -1) {
                minimo = V;
            } else {
                minimo = (min[p] < V ? min[p] : V);
            }
            min[++p] = minimo;
        } else if (!memcmp(op, "POP", 3)) {
            if (p == -1) {
            	printf("EMPTY\n");
            } else {
                --p;
            }
        } else {
            if (p == -1) {
            	printf("EMPTY\n");
            } else {
            	printf("%d\n", min[p]);
            }
        }
    }
    return 0;
}
