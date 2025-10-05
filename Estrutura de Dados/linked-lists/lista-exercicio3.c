// 3. Inserção Ordenada na Lista Encadeada
// Altere a implementação da lista encadeada para que os elementos sejam
// inseridos em ordem crescente automaticamente.
#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int dado;
    struct No* proximo;
} No;

No* inserir_inicio(No* head, int valor){
    No* novo = (No*)malloc(sizeof(No));
    novo->dado= valor;
    novo->proximo = head;
    return novo;
}

int isEmpty(No* head){
    if(head == NULL) return 1;
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

No* inserir_ordenado(No* head, int valor){
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->proximo =NULL;
    //inserir no inicio ou em uma lista vazia
    if(head == NULL || valor < head->dado){
        novo->proximo =head;
        return novo;
    }

    No* atual =head;
    while(atual->proximo != NULL && atual->proximo->dado < valor){
        atual = atual->proximo;
    }
    novo->proximo = atual->proximo;
    atual->proximo = novo;
    return head;
}

void imprimir(No* head){
    No* atual = head;
    while (atual != NULL){
        printf("%d -> ", atual->dado);
        atual = atual->proximo;
    }
    printf("NULL");
}
int main(){
    No* head = NULL;
    printf("Lista desordenada:\n");
    head = inserir_inicio(head, 20);
    head = inserir_inicio(head, 50);
    head = inserir_inicio(head, 79);
    head = inserir_inicio(head, 90);
    head = inserir_inicio(head, 4);
    head = inserir_inicio(head, 61);
    imprimir(head);

    No* h = NULL;
    printf("\n\nLista ordenada:\n");
    h = inserir_ordenado(h, 20);
    h = inserir_ordenado(h, 50);
    h = inserir_ordenado(h, 79);
    h = inserir_ordenado(h, 90);
    h = inserir_ordenado(h, 4);
    h = inserir_ordenado(h, 61);
    imprimir(h);

    return 0;
}