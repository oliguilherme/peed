#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int matriz_a[3][2], matriz_b[2][3], mult[3][3], soma = 0;
    srand(time(NULL));

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            matriz_a[i][j] = rand() % 10;
            printf("%d ", matriz_a[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            matriz_b[i][j] = rand() % 10;
            printf("%d ", matriz_b[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            soma = 0;
            for (int k = 0; k < 2; k++) {
                soma += matriz_a[i][k] * matriz_b[k][j];
            }
            mult[i][j] = soma;
            printf("%d ", mult[i][j]);
        }
        printf("\n");
    }

    return 0;
}
