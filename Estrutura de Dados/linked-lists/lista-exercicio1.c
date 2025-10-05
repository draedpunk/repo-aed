// 1. Implementação de uma Lista Encadeada Simples
// Crie um programa que implemente uma lista encadeada simples com as
// seguintes operações:
// • Inserir um elemento no início. ok
// • Inserir um elemento no final. ok 
// • Remover um elemento específico. ok
// • Exibir todos os elementos da lista. ok
#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int dado;
    struct No* proximo;
}No;

// inserir elemento no INICIO
No* inserir_inicio(No* head, int valor){
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->proximo = head;

    return novo;
}

// inserir elemento no FINAL
No* inserir_final(No* head, int valor){
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->proximo = NULL;

    if(head == NULL){ 
        return novo;
    }

    No* atual = head;
    while(atual->proximo != NULL){
        atual= atual->proximo;
    }
    atual->proximo = novo;
    return head;
}

// remover elemento especifico
No* remover_valor(No* head, int valor){
    if(head == NULL) return NULL;

    if(head->dado == valor){ // se quisermos remover a cabeca
        No* temporario = head;
        head = head->proximo;
        free(temporario);
        return head;
    }
    No* anterior = head;
    No* atual = head->proximo;
    while(atual !=NULL){
        if(atual->dado== valor){ // valor encontrado
            anterior->proximo = atual->proximo;
            free(atual);
            return head;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    return head;
}

void imprimir(No* head){
    No* atual = head;
    while(atual != NULL){
        printf("%d -> ", atual->dado);
        atual = atual->proximo;
    }
    printf("NULL");
}

int main(){
    No* head = NULL;
    head = inserir_inicio(head, 5);
    head = inserir_inicio(head, 10);
    head = inserir_inicio(head, 15);
    head = inserir_inicio(head, 20);
    imprimir(head);
    printf("\n\n");

    head = inserir_final(head, 45);
    imprimir(head);

    printf("\n\n");
    head = remover_valor(head, 15);
    imprimir(head);
    

    return 0;
}