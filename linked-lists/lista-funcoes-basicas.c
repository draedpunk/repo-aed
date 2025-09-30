#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No {//formato de um nó da lista: espaço pro dado e ponteiro pro PROXIMO nó
    int dado; 
    struct No* proximo;
} No;

No* inserir_inicio(No* cabeca, int valor){
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->proximo = cabeca;
    return novo;
}

int isEmpty(No* cabeca){
    return cabeca == NULL;
}

No* inserir_final(No* cabeca, int valor){
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->proximo = NULL; //DIFERENÇA COMECA AQUI: ja define que será o último nó

    if (isEmpty(cabeca)){
        return novo; //novo nó vira a cabeça qd a lista for vazia
    }

    No* atual = cabeca; // percorre até o último nó, valor temporario
    while(atual->proximo != NULL){
        atual = atual->proximo;
    }
    atual->proximo = novo; // liga o novo nó no final
    return cabeca; // cabeça não mudou
}

No* remover(No* cabeca, int valor) {
    if (isEmpty(cabeca)) return NULL; 
    if (cabeca->dado == valor) {
        No* temp = cabeca;
        cabeca = cabeca->proximo; 
        free(temp);             
        return cabeca;
    }
    No* anterior = cabeca;        
    No* atual = cabeca->proximo;  
    while (atual != NULL) {
        if (atual->dado == valor) {
            anterior->proximo = atual->proximo; 
            free(atual);                        
            return cabeca;                      
        }
        anterior = atual;
        atual = atual->proximo;
    }
    return cabeca;
}

No* removeAt(No* cabeca, int posicao) {
    if (isEmpty(cabeca) || posicao < 0) return cabeca; // lista vazia ou posição inválida

    // CASO ESPECIAL: remover a cabeça (posição 0)
    // Exemplo: lista [10 -> 20 -> 30 -> 40], posicao = 0
    // A cabeça é 10, vamos removê-la
    if (posicao == 0) {
        No* temp = cabeca;
        cabeca = cabeca->proximo; // nova cabeça = 20
        free(temp);               // libera memória do antigo nó 10
        return cabeca;
    }

    // Para posições maiores que 0, usamos dois ponteiros:
    No* anterior = cabeca;        // nó antes do que será removido
    No* atual = cabeca->proximo;  // nó que vamos analisar
    int i = 1;                    // começamos a contar da posição 1 (já passamos da cabeça)
    // Exemplo: lista [10 -> 20 -> 30 -> 40], posicao = 2
    // inicial: anterior = 10, atual = 20, i = 1

    while (atual != NULL && i < posicao) {
        anterior = atual;
        atual = atual->proximo;
        i++;
        // Passo 1: anterior = 20, atual = 30, i = 2
        // Paramos aqui porque i == posicao
    }

    if (atual != NULL) {
        // Encontramos a posição desejada
        // Antes: anterior->proximo = atual, atual->proximo = próximo nó
        // Queremos "pular" o atual
        // Exemplo: remover posição 2 (30)
        // Antes: 10 -> 20 -> 30 -> 40
        // Depois: 10 -> 20 -> 40
        anterior->proximo = atual->proximo; // nó anterior aponta pro próximo
        free(atual);                        // libera memória do nó removido
    }

    return cabeca; // retorna cabeça (lista possivelmente alterada)
}

int size(No* cabeca){
    int contador = 0;
    No* atual = cabeca;

    while( atual != NULL){
        contador++;
        atual = atual->proximo;
    }
    return contador;
}

void imprimir_lista(No* cabeca){ // descrescente
    No* atual = cabeca;
    while(atual !=NULL){
        printf("%d -> ", atual->dado);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

int main(){
    No* head = NULL;

    printf("---- LISTA ----\n");
    head = inserir_inicio(head, 10);
    head = inserir_inicio(head, 20);
    head = inserir_inicio(head, 30);
    head = inserir_final(head, 40);
    head = inserir_inicio(head, 5);

    imprimir_lista(head);
    printf(" - Tamanho da lista: %d elementos.\n", size(head));
    

    return 0;
}