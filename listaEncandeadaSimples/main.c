#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *proximo;
} No;

typedef struct {
    No *inicio;
    int tam;
} Lista;

void inserir_no_inicio(Lista *lista, int valor);
void inserir_no_final(Lista *lista, int valor);
int inserir_no(Lista *lista, int valor, int posicao);
void exibir(Lista *lista);
int tamanho_no(Lista *lista);
void remover_no_valor(Lista *lista, int valor);
void remover_no_posicao(Lista *lista, int posicao);
void remover_no_todo(Lista *lista);
//void trocar_pos_no(Lista *lista, int pos1, int pos2);

int menu();
void pausar();

int main() {
    int opcao, num, posicao, troca1, troca2;
    Lista lista;
    lista.inicio = NULL;
    lista.tam = 0;
   
    do {
        system("clear");
        opcao = menu();

        switch (opcao) {
            case 1:
                printf("\nInforme o valor: ");
                scanf("%d", &num);
                inserir_no_inicio(&lista, num);
                pausar();
                break;
            case 2:
                printf("\nInforme o valor: ");
                scanf("%d", &num);
                inserir_no_final(&lista, num);
                pausar();
                break;
            case 3:
                exibir(&lista);
                int resultado, tam = lista.tam;
                do {
                    printf("\nInforme o valor e posicao (entre 1 e %d): ", tam + 1);
                    scanf("%d %d", &num, &posicao);
                    while (posicao < 1) {
                        printf("Posicao comecao a partir do 1.\nInforme uma posicao valida: ");
                        scanf("%d", &posicao);
                    }
                    resultado = inserir_no(&lista, num, posicao);
                } while (resultado == 1);
                pausar();
                break;
            case 4:
                exibir(&lista);
                if (lista.tam == 0) {
                    printf("\nLista vazia.\n");
                    pausar();
                } else if (lista.tam == 1) {
                    remover_no_posicao(&lista, 1);
                    printf("\nNo removido. Lista agora vazia.\n");
                    pausar();
                } else {
                    tamanho_no(&lista);
                    do {
                        printf("Informe a posição entre 1 e %d: ", lista.tam);
                        scanf("%d", &posicao);
                    } while (posicao < 1 || posicao > lista.tam);
                    remover_no_posicao(&lista, posicao);
                    pausar();
                }
                break;
            case 5:
                exibir(&lista);
                printf("Informe o valor: ");
                scanf("%d", &num);
                remover_no_valor(&lista, num);
                pausar();
                break;
            case 6:
                remover_no_todo(&lista);
                pausar();
                break;
            case 7:
                tamanho_no(&lista);
                pausar();
                break;
            case 8:
                exibir(&lista);
                pausar();
                break;
            /*case 9:
                exibir(&lista);
                printf("\nInforme a posicao 1 e 2 para serem permutadas: ");
                scanf("%d %d", &troca1, &troca2);
                trocar_pos_no(&lista, troca1, troca2);
                pausar();
                break;*/
            case 10:
                printf("\nSaindo...\n");
            }
    } while (opcao != 10);

    return 0;
}

void inserir_no_inicio(Lista *lista, int valor) {
    No *novo = (No *)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = lista->inicio;
    lista->inicio = novo;
    lista->tam++;
    printf("\nInserido com sucesso!\n");
}

void inserir_no_final(Lista *lista, int valor) {
    No *novo = (No *)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = NULL;

    if (lista->inicio == NULL) {
        inserir_no_inicio(lista, valor);
        return;
    }
    No *inicio = lista->inicio;
    while (inicio->proximo != NULL) inicio = inicio->proximo;
    inicio->proximo = novo;
    lista->tam++;
    printf("\nInserido com sucesso!\n");
}

int inserir_no(Lista *lista, int valor, int posicao) {
    if (posicao == 1) {
        inserir_no_inicio(lista, valor);
        return 0;
    } else if (posicao == lista->tam + 1) {
         inserir_no_final(lista, valor);
         return 0;

    } else if (posicao > lista->tam + 1) {
        printf("Erro.\nPor favor, digite uma posicao entre 1 e %d.\n", lista->tam+1);
        return 1;
    } else {
        int i = 1;
        No *aux = lista->inicio;
        while (i < posicao - 1) {
            aux = aux->proximo;
            i++;
        }
        No *novo = (No *)malloc(sizeof(No));
        novo->valor = valor;
        novo->proximo = aux->proximo;
        aux->proximo = novo;
        lista->tam++;

        printf("\nInserido com sucesso!\n");
    }
    return 0;
}

void exibir(Lista *lista) {
    printf("\n");
    No *inicio = lista->inicio;
    while (inicio != NULL) {
        printf("%d -> ", inicio->valor);
        inicio = inicio->proximo;
    }
    printf("NULL");
    printf("\n");
}

int tamanho_no(Lista *lista) {
    int tam = lista->tam;
    printf("\nTamanho da lista: %d\n", tam);

    return tam;
}

int menu() {
    int opcao;
    printf("\n------------------------\n");
    printf(" 1 - Inserir no inicio\n");
    printf(" 2 - Inserir no final\n");
    printf(" 3 - Inserir arbitrariamente\n");
    printf(" 4 - Remover por posicao (Implementada parcialmente)\n");
    printf(" 5 - Remover por valor\n");
    printf(" 6 - Remover tudo\n");
    printf(" 7 - Ver tamanho\n");
    printf(" 8 - Exibir\n");
    //printf(" 9 - Trocar posicoes\n");
    printf("10 - Sair\n");
    printf("------------------------\n");
    printf("Opcao: ");
    scanf("%d", &opcao);
    return opcao;
}

void pausar() {
    printf("\nPressione Enter para continuar...");
    getchar(); 
    getchar(); 
}

void remover_no_valor(Lista *lista, int valor) {
    if (lista->inicio == NULL) {
        printf("\nLista vazia.\n");
        return;
    }
    
    No *temp = lista->inicio;
    No *tempAnterior = NULL;

    while (temp->valor != valor && temp != NULL) {
        tempAnterior = temp;
        temp = temp->proximo;
    }

    if (temp == NULL) {
        printf("\nValor %d nao encontrado na lista.\n");
        return;
    }

    if (tempAnterior == NULL) { //remocao no inicio
        lista->inicio = temp->proximo;
    } else { //remocao meio ou fim
         tempAnterior->proximo = temp->proximo;
    }

    free(temp);
    lista->tam--;
    printf("Valor %d removido com sucesso.\n", valor);
}

void remover_no_posicao(Lista *lista, int posicao) {
    if (lista->inicio == NULL) {
        printf("\nLista vazia.\n");
        return;
    }
    No *temp = lista->inicio;
    No *tempAnterior = NULL;

    if (posicao == 1) {
        lista->inicio = temp->proximo;
        free(temp);
        lista->tam--;
        return;
    }

    int i = 1;
    while (i < posicao) {
        tempAnterior = temp;
        temp = temp->proximo;
        i++;
    }

    tempAnterior->proximo = temp->proximo;
    free(temp);
    lista->tam--;

    printf("\nNo na posicao %d removido com sucesso.\n", posicao);
    return;
}

void remover_no_todo(Lista *lista) {
    int opcao;
    do {
        printf("Isso removera todo o no. Deseja prosseguir? 1 - Sim | 0 - Nao: ");
        scanf("%d", &opcao);
    } while(opcao < 0 || opcao > 1);
    
    if (opcao == 1) {
        No *temp;
        while (lista->inicio != NULL) {
            temp = lista->inicio;
            lista->inicio = temp->proximo;
            free(temp);
            lista->tam--;
        }
        printf("\nNo removido com sucesso.\n");
    } else {
        return;
    }
}

/*void trocar_pos_no(Lista *lista, int pos1, int pos2) {
    No *tempAnterior = lista->inicio;
    No *aux1, *aux2, *aux3, *aux4;
    aux1 = lista->inicio, aux2 = lista->inicio, aux3 = lista->inicio, aux4 = lista->inicio;
    int i = 1;
    while (i < pos2) {
        tempAnterior = tempAnterior->proximo;
        if (i < pos1 - 1) aux1 = aux1->proximo;
        if (i < pos1) aux2 = aux2->proximo;
        if (i < pos2 - 1) aux3 = aux3->proximo;
        i++;
    }
    aux4 = tempAnterior->proximo;
    aux1->proximo = tempAnterior;
    tempAnterior->proximo = aux2->proximo;
    aux3->proximo = aux2;
    aux2->proximo = aux4;

    printf("Posicoes trocadas com sucesso.\n");
}*/
