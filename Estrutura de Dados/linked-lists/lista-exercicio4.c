// 4. Reverter uma Lista Encadeada
// Implemente uma função que inverte a ordem dos elementos de uma lista
// encadeada sem criar uma nova lista.
#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int dado;
    struct No* proximo;
} No;

No* inserir_inicio(No* head, int valor){
    No* novo = (No*)malloc(sizeof(No*));
    novo->dado = valor;
    novo->proximo = head;
    return novo;
}

No* reverter(No* head){
    No* anterior = NULL;
    No* atual = head;
    No* proximo = NULL;
    while(atual != NULL){
        proximo = atual->proximo;
        atual->proximo = anterior;
        anterior =atual;
        atual=proximo;
    }
    return anterior;
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
    head = inserir_inicio(head, 1);
    head = inserir_inicio(head, 10);
    head = inserir_inicio(head, 2002);
    head = inserir_inicio(head, 61);
    head = inserir_inicio(head, 4);

    head = reverter(head);
    imprimir(head);
    return 0;
}