// 2. Contagem de Elementos na Lista
// Modifique o código do exercício 1 e implemente uma função para contar
// quantos elementos existem na lista.
#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int dado;
    struct No* proximo;
} No;

No* inserir_inicio(No* head, int valor){
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->proximo = head;
    return novo;
}

int isEmpty(No* head){
    if (head == NULL) return 1;
}

No* inserir_final(No* head, int valor){
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->proximo = NULL;

    if(isEmpty(head)) return novo;

    No* atual = head;
    while(atual != NULL){
        atual = atual->proximo;
    }
    atual->proximo = novo;
    return head;
}

int size(No* head){
    No* atual = head;
    int cont = 0;
    while(atual != NULL){
        cont++;
        atual = atual->proximo;
    }
    return cont;
}

void imprimir(No* head){
    No* atual = head;
    while(atual !=NULL){
        printf("%d -> ", atual->dado);
        atual = atual->proximo;
    }
    printf("NULL");
}

int main(){
    No* head = NULL;
    head = inserir_inicio(head, 20);
    head = inserir_inicio(head, 50);
    head = inserir_inicio(head, 79);
    head = inserir_inicio(head, 90);
    head = inserir_inicio(head, 4);
    head = inserir_inicio(head, 61);
    imprimir(head);
    printf("\n\nQuantidade de elementos na lista: %d elementos.", size(head));

    return 0;
}