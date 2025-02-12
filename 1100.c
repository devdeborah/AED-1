#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 8

typedef struct {
    int x, y;
} Posicao;

int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

int valida (int x, int y) {
    return x >= 0 && x < TAM && y >= 0 && y < TAM;
}

int bfs (Posicao ini, Posicao fim) {
    int dist[TAM][TAM];
    Posicao fila[TAM * TAM];
    int frente = 0, tras = 0;

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            dist[i][j] = -1;
        }
    }
    fila[tras++] = ini;
    dist[ini.x][ini.y] = 0;
    while (frente < tras) {
        Posicao atual = fila[frente++];
        if (atual.x == fim.x && atual.y == fim.y) {
            return dist[atual.x][atual.y];
        }
        for (int i = 0; i < 8; i++) {
            int novoX = atual.x + dx[i];
            int novoY = atual.y + dy[i];
            if (valida(novoX, novoY) && dist[novoX][novoY] == -1) {
                dist[novoX][novoY] = dist[atual.x][atual.y] + 1;
                fila[tras++] = (Posicao){novoX, novoY};
            }
        }
    }
    return -1;
}

Posicao analisaPosicao (char* str) {
    Posicao pos;
    pos.x = str[0] - 'a';
    pos.y = str[1] - '1';
    return pos;
}

int main (void) {
    char inicio[3], final[3];

    while (scanf("%s %s", inicio, final) == 2) {
        Posicao ini = analisaPosicao(inicio);
        Posicao fim = analisaPosicao(final);
        int mov = bfs(ini, fim);
        printf("To get from %s to %s takes %d knight moves.\n", inicio, final, mov);
    }
    return 0;
}
