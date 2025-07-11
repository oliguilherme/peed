#include <stdio.h>
#include <stdlib.h>


typedef struct No {
    int dado;
    struct No *proximo;
    struct No *anterior;
} No;

typedef struct {
    int tam;
    No *inicio;
} Lista;

void inserir_inicio(Lista *lista, int valor);
void inserir_fim(Lista *lista, int valor);
void inserir_meio(Lista *lista, int valor, int posicao);
void inverter_no(Lista *lista);
void inserir_ordenado(Lista *lista, int valor);
void remover_impares(Lista *lista);
void removerDuplicatas(Lista *lista);
void exibir_no(Lista lista);



int main() {
    Lista lista;
    lista.tam = 0; lista.inicio = NULL;
    
    inserir_inicio(&lista, 2);
    inserir_inicio(&lista, 1);
    inserir_fim(&lista, 4);
    inserir_fim(&lista, 8);
    inserir_fim(&lista, 8);
    inserir_ordenado(&lista, 6);
    inserir_ordenado(&lista, 7);
    inserir_ordenado(&lista, 3);
    //inserir_meio(&lista, 12, 2);
    exibir_no(lista);
    //inverter_no(&lista);
    //exibir_no(lista);

    inverter_no(&lista);
    exibir_no(lista);

    remover_impares(&lista);
    exibir_no(lista);

    removerDuplicatas(&lista);
    exibir_no(lista);



    return 0;
}

void inserir_inicio(Lista *lista, int valor) {
    No *novo = (No *)malloc(sizeof(No));
    novo->dado = valor;
    novo->proximo = lista->inicio;
    novo->anterior = NULL;

    if (lista->inicio != NULL) lista->inicio->anterior = novo;

    lista->inicio = novo;
    lista->tam++;

    printf("\nInserido com sucesso!\n");
}


void inserir_fim(Lista *lista, int valor) {
    No *novo = (No *)malloc(sizeof(No));
    novo->dado = valor;
    novo->proximo = NULL;

    if (lista->inicio == NULL) {
        inserir_inicio(lista, valor);
        return;
    }

    No *inicio = lista->inicio;
    while (inicio->proximo != NULL) inicio = inicio->proximo;

    inicio->proximo = novo;
    novo->anterior = inicio;
    lista->tam++;

    
    printf("\nInserido com sucesso!\n");
}

void exibir_no(Lista lista) {
    printf("\n");
    while (lista.inicio != NULL) {
        printf("%d -> ", lista.inicio->dado);
        lista.inicio = lista.inicio->proximo;
    }
    printf("Null\n");
}

void inserir_meio(Lista *lista, int valor, int posicao) {
    if (lista->inicio == NULL) {
        printf("\nLista vazia.\n");
        return;
    }

    //fazer verificação da validez da posicao no main

    if (posicao == 1) {
        inserir_inicio(lista, valor);
        return;
    } else if (posicao == lista->tam + 1) {
        inserir_fim(lista, valor);
        return;
    } else {
        No *novo = (No *)malloc(sizeof(No));
        novo->dado = valor;

        int i = 1;
        No *temp = lista->inicio;
        while (i < posicao - 1) {
            temp = temp->proximo;
            i++;
        }

        novo->anterior = temp;
        novo->proximo = temp->proximo;
        novo->proximo->anterior = novo;
        temp->proximo = novo;

        lista->tam++;
    }

    printf("\nInserido com sucesso!\n");
}

void inverter_no(Lista *lista) {
    if (lista->inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    No *atual = lista->inicio;
    No *temp = NULL;

    while (atual != NULL) {
        // Troca proximo e anterior
        temp = atual->anterior;
        atual->anterior = atual->proximo;
        atual->proximo = temp;

        atual = atual->anterior;
    }

    if (temp != NULL) {
        lista->inicio = temp->anterior;
    }

    printf("Lista invertida com sucesso!\n");
}

void inserir_ordenado(Lista *lista, int valor) {
    int count = 0;
    No *temp = lista->inicio;

    while (temp != NULL ) {
        if (valor > temp->dado) {
            count++;
        } else {
            break;
        }
        temp = temp->proximo;
    }

    if (count == 0) {
        inserir_inicio(lista, valor);
        return;
    }

    if (temp == NULL) {
        inserir_fim(lista, valor);
        return;
    }

    inserir_meio(lista, valor, count + 1);

    
}

void remover_impares(Lista *lista) {
    if (lista->inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    No *atual = lista->inicio;

    while (atual != NULL) {
        No *prox = atual->proximo;

        if (atual->dado % 2 != 0) {
            if (atual->anterior != NULL) atual->anterior->proximo = atual->proximo;
            else lista->inicio = atual->proximo; 

            if (atual->proximo != NULL) atual->proximo->anterior = atual->anterior;
            free(atual);
            lista->tam--;
        }
        atual = prox;
    }
    printf("Todos os elementos ímpares foram removidos.\n");
}

void removerDuplicatas(Lista *lista) {
    if (lista->inicio == NULL) return;

    No *atual = lista->inicio;

    while (atual != NULL) {
        No *comparador = atual->proximo;

        while (comparador != NULL) {
            No *proximo = comparador->proximo;

            if (comparador->dado == atual->dado) {
                if (comparador->anterior) comparador->anterior->proximo = comparador->proximo;
                if (comparador->proximo) comparador->proximo->anterior = comparador->anterior;
                if (comparador == lista->inicio) lista->inicio = comparador->proximo;

                free(comparador);
                lista->tam--;
            }
            comparador = proximo;
        }
        atual = atual->proximo;
    }
    printf("Duplicatas removidas com sucesso.\n");
}

