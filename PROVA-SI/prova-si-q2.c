// Implemente uma lista simplesmente encadeada que armazene números inteiros.

// Crie funções para:
// a) Inserir elementos no início da lista.
// b) Exibir todos os elementos da lista.
// c) Uma função recursiva que calcule a soma de todos os elementos.

// Teste o programa inserindo os valores 10, 5, 8, 20, 15.
#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int dado;
    struct No* proximo;
} No;

No* inserir_inicio(No* head, int valor){
    No* novo = (No*)malloc(sizeof(No));
    novo->dado=valor;
    novo->proximo=head;
    return novo;
}

void imprimir(No* head){
    No* atual = head;
    while(atual != NULL){
        printf("%d -> ", atual->dado);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

int soma_recursiva(No* head){
    if(head == NULL) return 0;
    return head->dado + soma_recursiva(head->proximo);
}

int soma(No* head){
    int contador = 0;
    No* atual = head;
    while(atual != NULL){
        contador += atual->dado;
        atual = atual->proximo;
    }
    return contador;
}

int main(){
    No* head = NULL;
    head=inserir_inicio(head, 10);
    head=inserir_inicio(head, 5);
    head=inserir_inicio(head, 8);
    head=inserir_inicio(head, 20);
    head=inserir_inicio(head, 15);
    imprimir(head);
    printf("Soma de todos os elementos da lista: %d\n.", soma_recursiva(head));
    return 0;
}