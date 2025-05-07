#include <stdio.h>

int fib(int n) {
    if (n == 0 || n == 1) {
        return n;
    }

    return fib(n - 1) + fib(n - 2);
}

int main() {
    int num, result;

    printf("Informe o numero: ");
    scanf("%d", &num);

    result = fib(num);

    printf("O fibonnaci de %d eh: %d", num, result);

    return 0;
}