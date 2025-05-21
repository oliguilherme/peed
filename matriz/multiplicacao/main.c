#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int m, n, p, q;

    printf("Entre com os numeros de linhas e de colunas da primeira matriz: ");
    scanf("%d %d", &m, &n);

    printf("\nEntre com os numeros de linhas e de coluncas da segunda matriz: ");
    scanf("%d %d", &p, &q);

    printf("\n");
    if (n == p) {
        int matriz_a[m][n], matriz_b[p][q], mult[m][q], soma = 0;
        srand(time(NULL));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                matriz_a[i][j] = rand() % 10;
                printf("%d ", matriz_a[i][j]);
            }
            printf("\n");
        }

        printf("\n");

        for (int i = 0; i < p; i++) {
            for (int j = 0; j < q; j++) {
                matriz_b[i][j] = rand() % 10;
                printf("%d ", matriz_b[i][j]);
            }
            printf("\n");
        }

        printf("\n");

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < q; j++) {
                soma = 0;
                for (int k = 0; k < n; k++) {
                    soma += matriz_a[i][k] * matriz_b[k][j];
                }
                mult[i][j] = soma;
                printf("%d ", mult[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Nao eh possivel calcular a multiplicacao entre essas matrizes");
    }

    return 0;
}
