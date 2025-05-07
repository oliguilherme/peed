#include <stdio.h>

void dobrarArray(int n[], int tam);
void inverterArray(int n[], int ini, int fim);
void imprimirArray(int n[], int tam);

int main() {
    int num[5] = {1, 2, 3, 4, 5};
    int tam = sizeof(num) / sizeof(num[0]);
    int ini = 0, fim = tam - 1;
    
    printf("\nArray dobrado:");
    dobrarArray(num, tam);
    imprimirArray(num, tam);

    printf("\nArray invertido:");
    inverterArray(num, ini, fim);
    imprimirArray(num, tam);

    return 0;
}

void dobrarArray(int n[], int tam) {
    int i = 0;

    for (i; i < tam; i++) {
        n[i] *= 2;
    }

    for (i; i < tam; i++) {
        printf("%d ", n[i]);
    }
}

void inverterArray(int n[], int ini, int fim) {
    int aux;

    if (ini < fim) {
        aux = n[ini];
        n[ini] = n[fim];
        n[fim] = aux;

        inverterArray(n, ini + 1, fim - 1);
    }
}

void imprimirArray(int n[], int tam) {
     int i = 0;

      for (i; i < tam; i++) {
        printf(" %d", n[i]);
    }
}
