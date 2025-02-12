#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int contNum(int [], int, int);
void selectionSort(int [], int);
void copiaVetor(int [], int [], int, int);

int main (void) {
    int tamVet, rodadas;
    
    scanf("%d %d", &tamVet, &rodadas);
    int vet[tamVet];
    for (int i = 0; i < tamVet; i++) {
        scanf("%d", &vet[i]);
    }
    for (int r = 0; r < rodadas; r++) {
        int limInf, limSup, kMenor, guga, dabriel;
        scanf("%d %d %d %d %d", &limInf, &limSup, &kMenor, &guga, &dabriel);
        int tamIntervalo = limSup - limInf + 1;
        int intervalo[tamIntervalo];
        copiaVetor(vet, intervalo, limInf - 1, limSup - 1);
        selectionSort(intervalo, tamIntervalo);
        int menor = intervalo[kMenor - 1];
        int contKEsimo = contNum(intervalo, tamIntervalo, menor);
        int difGuga = abs(contKEsimo - guga);
        int difDabriel = abs(contKEsimo - dabriel);
        char result = 'E';
        if (difGuga < difDabriel) {
            result = 'G';
        } else if (difDabriel < difGuga) {
            result = 'D';
        }
        printf("%d %d %c\n", menor, contKEsimo, result);
    }
    return 0;
}
int contNum(int vet[], int tam, int num) {
    int cont = 0;
    
    for (int i = 0; i < tam; i++) {
        if (vet[i] == num) {
            cont++;
        }
    }
    return cont;
}
void selectionSort(int vet[], int tam) {
    for (int i = 0; i < tam - 1; i++) {
        int min = i;
        for (int j = i + 1; j < tam; j++) {
            if (vet[j] < vet[min]) {
                min = j;
            }
        }
        int aux = vet[i];
        vet[i] = vet[min];
        vet[min] = aux;
    }
}
void copiaVetor(int ori[], int dest[], int limInf, int limSup) {
    for (int i = limInf, j = 0; i <= limSup; i++, j++) {
        dest[j] = ori[i];
    }
}
