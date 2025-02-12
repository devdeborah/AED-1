#include <stdio.h>
#include <string.h>

int main (void) {
    int q, d;
    char a[1002], b[1002];
    int encaixe;

    scanf("%d", &q);
    getchar();
    for (int i = 0; i < q; ++i) {
        scanf("%s %s", &a, &b);
        encaixe = 1;
        d = strlen(a) - strlen(b);
        if (d >= 0) {
            for (int j = 0; j < strlen(b); ++j)
                if (a[j + d] != b[j])
                    encaixe = 0;
        }
        else encaixe = 0;
        if (encaixe) 
            printf ("encaixa\n");
        else 
            printf ("nao encaixa\n");
    }
    return 0;
}
