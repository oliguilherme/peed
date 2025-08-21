#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No {
    int dado;
    struct No *prox;
} No;

No *topo = NULL;

bool pilha_vazia() {
    return topo == NULL;
}

void push(int dado) {
    No *novo = malloc(sizeof(No));
    novo->dado = dado;
    novo->prox = topo;

    topo = novo;
}

int pop() {
    if (!pilha_vazia()) {
        No *aux = topo;
        topo = aux->prox;
        int valor = aux->dado;
        free(aux);
        return valor;
        
    } else {
        printf("\nFila vazia.\n");
        exit(1);    
    }
}

int main() {
    int opcao, num;

    do {
        printf("\n1 - Inserir\n2 - Remover\n3 - Desempilhar e Somar Tudo\n4 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Numero: ");
                scanf("%d", &num);
                push(num);
                break;
            case 2:
                printf("\nRemovido elemento %d", pop());
                break;
            case 3:
                int soma = 0;
                while(!pilha_vazia()) {
                    soma += pop();
                }
                printf("\nSoma total: %d\n", soma);
                break;
            case 4:
                printf("\nEncerrando o sistema...\n");
                break;
            
            default:
                printf("\nOpção invalida.\n");
        }
    } while (opcao != 3 && opcao != 4);

    return 0;
}