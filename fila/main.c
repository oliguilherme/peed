#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade, senha;
} Pessoa;

typedef struct No {
    Pessoa p;
    struct No *proximo; 
    struct No *ant;
} No;

typedef struct {
    int tam;
    No *ini;
    No *fim;
} Fila;

void criar_fila(Fila *fila);
int fila_vazia(Fila *fila);
void enqueue(Fila *fila, Pessoa p);
void liberar_fila(Fila *fila);
Pessoa dequeue(Fila *fila);


int main() {
    Fila comum, prioritaria;
    criar_fila(&comum);
    criar_fila(&prioritaria);

    int opcao, senha = 1;
    Pessoa p;

    do {
        printf("\n--- BANCO ---\n");
        printf("1 - Chegada de cliente\n");
        printf("2 - Atender próximo\n");
        printf("3 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar(); 

        switch(opcao) {
            case 1:
                p.senha = senha++;
                printf("\nNome: ");
                fgets(p.nome, 50, stdin);
                p.nome[strcspn(p.nome, "\n")] = '\0';
                printf("Idade: ");
                scanf("%d", &p.idade);
                getchar();

                if (p.idade >= 60) {
                    enqueue(&prioritaria, p);
                    printf("\nCliente prioritario %s (senha %d) entrou na fila.\n", p.nome, p.senha);
                } else {
                    enqueue(&comum, p);
                    printf("\nCliente %s (senha %d) entrou na fila.\n", p.nome, p.senha);
                }
                break;
            
            case 2:
                if (!fila_vazia(&prioritaria)) {
                    p = dequeue(&prioritaria);
                    printf("\nAtendendo prioritario %s (senha %d, idade %d).\n", p.nome, p.senha, p.idade);
                } else if (!fila_vazia(&comum)) {
                    p = dequeue(&comum);
                    printf("\nAtendendo %s (senha %d, idade %d).\n", p.nome, p.senha, p.idade);
                } else {
                    printf("\nNenhum cliente na fila.\n");
                }
                break;
            
            case 3:
                printf("\nEncerrando o sistema...\n");
                break;
            
            default:
                printf("\nOpção invalida.\n");
        }
    } while (opcao != 3);

    return 0;
}

void criar_fila(Fila *fila) {
    fila->ini = NULL;
    fila->fim = NULL;
    fila->tam = 0;
}

int fila_vazia(Fila *fila) {
    return (fila->tam == 0);
}

void enqueue(Fila *fila, Pessoa p) {
    No *novo = malloc(sizeof(No));
    novo->p = p;
    novo->proximo = NULL;
    novo->ant = fila->fim;

    if (fila_vazia(fila)) {
        fila->ini = novo;
    } else {
        fila->fim->proximo = novo;
    }
    fila->fim = novo;
    fila->tam++;
}

Pessoa dequeue (Fila *fila) {
    Pessoa p;
    if (fila_vazia(fila)) {
        printf("\nFila vazia.\n");
        p.senha = -1;
        return p;
    }
    No *aux = fila->ini;
    p = aux->p;
    fila->ini = aux->proximo;
    if (fila->ini != NULL) {
        fila->ini->ant = NULL;
    } else {
        fila->fim = NULL;
    }

    free(aux);
    fila->tam--;
    
    return p;
}

void liberar_fila(Fila *fila) {
    while (!fila_vazia(fila)) 
        dequeue(fila);
}