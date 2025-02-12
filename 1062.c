#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int main(void) {
    int N;

    while (scanf("%d", &N), N) {
        while (1) {
            int sequencia[MAX];
            scanf("%d", &sequencia[0]);
            if (sequencia[0] == 0) {
                printf("\n");
                break;
            }
            for (int i = 1; i < N; i++) {
                scanf("%d", &sequencia[i]);
            }
            int pilha[MAX], topo = -1;
            int prox = 1;
            int id = 0;
            while (prox <= N) {
                pilha[++topo] = prox++;
                while (topo >= 0 && pilha[topo] == sequencia[id]) {
                    topo--;
                    id++;
                }
            }
            if (id == N) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }
    return 0;
}
