#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* proximo;
    struct No* anterior;
} No;

typedef struct{
    int tam;
    No* inicio;
} Lista;

void inserir_inicio(Lista *lista, int dado);
void inserir_final(Lista *lista, int dado);

void exibir(Lista lista);

int main() {
    Lista lista;
    lista.tam = 0, lista.inicio = NULL;
    inserir_inicio(&lista, 30);
    inserir_inicio(&lista, 20);
    inserir_inicio(&lista, 10);
    inserir_final(&lista, 40);
    exibir(lista);
    

    return 0;
}

void inserir_inicio(Lista *lista, int dado) {
    No *novo = (No *)malloc(sizeof(No));
    novo->dado = dado;

    if (lista->inicio == NULL) {
        novo->proximo = novo;
        novo->anterior = novo;
        lista->inicio = novo; 
        return;
    }

    No *ultimo = lista->inicio->anterior;
    
    novo->proximo = lista->inicio;
    novo->anterior = ultimo;
    ultimo->proximo = novo;

    lista->inicio = novo;
    lista->tam++;
}

void inserir_final(Lista *lista, int dado) {
    if (lista->inicio == NULL) {
        inserir_inicio(lista, dado);
        return;
    }
    
    No* novo = (No *)malloc(sizeof(No));
    novo->dado = dado;

    No *penultimo = lista->inicio->anterior;


    novo->anterior = penultimo;
    novo->proximo = lista->inicio;
    penultimo->proximo = novo;
    lista->inicio->anterior = novo;

    lista->tam++;
}

void exibir(Lista lista) {
    No *temp = lista.inicio;

    do {
        printf("%d -> ", temp->dado);
        temp = temp->proximo;
    } while (temp != lista.inicio);
}