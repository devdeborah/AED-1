#include <stdio.h>
#define M 100

int ax[] = {0, 0, 1, -1};
int ay[] = {1, -1, 0, 0};
char direcoes[] = {'>', '<', 'v', '^'};

int direciona(char c);

int main(void) {
    int x, y;
    char mapa[M][M];
    int flag[M][M] = {0};

    scanf("%d %d", &x, &y);
    for (int i = 0; i < y; i++) {
        scanf("%s", mapa[i]);
    }

    int px = 0, py = 0;
    int d = -1;

    while (1) {
        if (px < 0 || px >= y || py < 0 || py >= x) {
            printf("!\n");
            return 0;
        }
        if (mapa[px][py] == '*') {
            printf("*\n");
            return 0;
        }
        if (flag[px][py] == 1) {
            printf("!\n");
            return 0;
        }
        flag[px][py] = 1;
        int nova = direciona(mapa[px][py]);
        if (nova != -1) {
            d = nova;
        } else if (mapa[px][py] == '.') {
            if (d == -1) {
                printf("!\n");
                return 0;
            }
        } else {
            printf("!\n");
            return 0;
        }
        px += ax[d];
        py += ay[d];
    }
}
int direciona(char c) {
    for (int i = 0; i < 4; i++) {
        if (direcoes[i] == c) {
            return i;
        }
    }
    return -1;
}
