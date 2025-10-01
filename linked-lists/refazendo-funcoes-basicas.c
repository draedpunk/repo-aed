#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int dado;
    struct No* proximo;
}No;

int isEmpty(No* head){
    return head == NULL;
}

No* inserir_inicio(No* head, int valor){
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->proximo = head;
    return novo;
}

No* inserir_final(No* head, int valor){
    No* novo = (No*)malloc(sizeof(No));
    novo->dado =valor;
    novo->proximo = NULL;

    if(isEmpty(head)) return novo;

    No* atual = head;
    while(atual->proximo != NULL){
        atual = atual->proximo;
    }
    atual->proximo = novo;
    return head;
}

No* remover(No* head, int valor){
    if(isEmpty(head)) return NULL; //lista vazia e nao tem nad apra remover
    if(head->dado == valor){ // se o valor a ser removido ta na cabeca
        No* temp = head;
        head = head->proximo;
        free(temp);
        return head;
    }
    No* anterior = head;
    No* atual = head->proximo;
    while(atual != NULL){
        if(atual->dado == valor){
            anterior->proximo = atual->proximo;
            free(atual);
            return head;
        }
        anterior = atual;
        atual = atual->proximo;  
    }
    return head;
}

No* removeAt(No* head, int posicao){
    if(isEmpty(head) || posicao < 0) return head;
    if(posicao == 0){
        No* temp =head;
        head = head->proximo;
        free(temp);
        return head;
    }
    No* anterior = head;
    No* atual = head->proximo;
    int i =1;
    while(atual != NULL && i < posicao){
        anterior = atual;
        atual = atual->proximo;
        i++;
    }
    if(atual != NULL){
        anterior->proximo = atual->proximo;
        free(atual);
    }
    return head;
}

int size(No* head){
    int contador = 0;
    No* atual = head;
    while(atual != NULL){
        contador++;
        atual = atual->proximo;
    }
    return contador;
}

void imprimir(No* head){
    No* atual = head;
    while(atual != NULL){
        printf("%d ->", atual->dado);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

int main(){
    No* head = NULL;
    head = inserir_inicio(head, 1);
    head = inserir_inicio(head, 3);
    head = inserir_inicio(head, 2);
    head = inserir_final(head, 5);
    head = inserir_final(head, 69);
    imprimir(head);
    printf("Quantidade de elementos na lista: %d elementos.\n", size(head));
    return 0;
}