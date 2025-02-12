#include <stdio.h> 
#include <stdlib.h> 
#define MAX 10000 

typedef struct pilha { 
    int topo; 
    int chegada[MAX]; 
    int saida[MAX]; 
} Pilha; 

Pilha* cria(); 
void libera(Pilha*); 
int verificaVazia(Pilha*); 
int verificaCheia(Pilha*, int); 
int push(Pilha*, int, int, int); 
int pop(Pilha*); 

int main (void) { 
    int n, k, ci, si; 
    int i;
    
    while (1) { 
        scanf("%d %d", &n, &k); 
        if (k == 0 && n == 0) 
            break; 
        Pilha* p = cria(); 
        int possivel = 1; 
        for (i = 0; i < n; i++) { 
            scanf("%d %d", &ci, &si); 
            if (possivel) { 
                if (verificaVazia(p)) { 
                    push(p, ci, si, k); 
                    possivel = 1; 
                } else { 
                    while (ci >= p->saida[p->topo-1]) { 
                        pop(p); 
                        if (verificaVazia(p)) 
                            break; 
                    } 
                    if (verificaCheia(p, k)) { 
                        possivel = 0; 
                    } else { 
                        push(p, ci, si, k); 
                        if (p->topo > 1) { 
                            if (p->chegada[p->topo-1] > p->chegada[p->topo -2] && p->saida[p->topo -1] < p->saida[p->topo -2]) { 
                                possivel = 1; 
                            } else { 
                                possivel = 0; 
                            } 
                        } else { 
                            possivel = 1; 
                        } 
                    } 
                } 
            } 
        } 
        if (possivel) 
            printf("Sim\n"); 
        else 
            printf("Nao\n"); 
        libera(p); 
    } 
} 
Pilha* cria () { 
    Pilha* p = (Pilha*)malloc(sizeof(Pilha)); 
    p->topo = 0; 
    return p; 
} 
void libera (Pilha* p) { 
    free(p); 
} 
int verificaVazia (Pilha* p) { 
    if (p->topo == 0) return 1; 
    else return 0; 
} 
int verificaCheia (Pilha* p, int vagas) { 
    if (p->topo == vagas) 
        return 1; 
    else return 0; 
} 
int push (Pilha* p, int c, int s, int vagas) { 
    if (!verificaCheia(p, vagas)) { 
        p->chegada[p->topo] = c; 
        p->saida[p->topo] = s; 
        p->topo++; 
        return 1; 
    } else { 
        return 0; 
    } 
} 
int pop (Pilha* p){ 
    if (!verificaVazia(p)) { 
        p->topo--; 
        return 1; 
    } else { 
        return 0; 
    } 
} 
