#include <stdio.h>
#include <string.h>
#define MAX 1000

int N, M;
long long moto[MAX + 2][MAX + 2];
long long carro[MAX + 2][MAX + 2];

void precalMoto();
void precalCarro();
long long sumMoto(int x1, int y1, int x2, int y2);
long long sumCarro(int x1, int y1, int x2, int y2);

int main (void) {
    scanf("%d %d", &N, &M);
    memset(carro, 0, sizeof(carro));
    memset(moto, 0, sizeof(moto));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char ch;
            scanf(" %c", &ch);
            if (ch == 'M')
                moto[i][j] = 1;
            else if (ch == 'C')
                carro[i][j] = 1;
        }
    }
    precalMoto();
    precalCarro();
    int L;
    scanf("%d", &L);
    long long resp = -1;
    for (int i = 0; i <= N - L; i++) {
        for (int j = 0; j <= M - L; j++) {
            int x1 = i, y1 = j;
            int x2 = i + L - 1, y2 = j + L - 1;
            long long motos = sumMoto(x1, y1, x2, y2);
            long long carros = sumCarro(x1, y1, x2, y2);
            long long valor = motos * 12 + carros * 25;
            if (valor > resp && motos > 0 && carros > 0) {
                resp = valor;
            }
        }
    }
    printf("%lld\n", resp);
    return 0;
}
void precalMoto() {
    for (int x = 0; x < N; x++)
        for (int y = 0; y < M; y++) {
            if (x > 0)
                moto[x][y] += moto[x - 1][y];
            if (y > 0)
                moto[x][y] += moto[x][y - 1];
            if (x > 0 && y > 0)
                moto[x][y] -= moto[x - 1][y - 1];
        }
}
void precalCarro() {
    for (int x = 0; x < N; x++)
        for (int y = 0; y < M; y++) {
            if (x > 0)
                carro[x][y] += carro[x - 1][y];
            if (y > 0)
                carro[x][y] += carro[x][y - 1];
            if (x > 0 && y > 0)
                carro[x][y] -= carro[x - 1][y - 1];
        }
}
long long sumMoto(int x1, int y1, int x2, int y2) {
    long long soma = moto[x2][y2];
    if (x1 > 0)
        soma -= moto[x1 - 1][y2];
    if (y1 > 0)
        soma -= moto[x2][y1 - 1];
    if (x1 > 0 && y1 > 0)
        soma += moto[x1 - 1][y1 - 1];
    return soma;
}
long long sumCarro(int x1, int y1, int x2, int y2) {
    long long soma = carro[x2][y2];
    if (x1 > 0)
        soma -= carro[x1 - 1][y2];
    if (y1 > 0)
        soma -= carro[x2][y1 - 1];
    if (x1 > 0 && y1 > 0)
        soma += carro[x1 - 1][y1 - 1];
    return soma;
}
