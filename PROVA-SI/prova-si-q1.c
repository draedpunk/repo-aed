// Implemente uma lista simplesmente encadeada que armazene números inteiros. O programa deve conter:

// a) Uma função para inserir elementos no final da lista.
// b) Uma função recursiva que percorra a lista e conte quantos elementos pares ela possui.
// c) Uma função que remova todos os elementos ímpares da lista.
#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int dado;
    struct No* proximo;
} No;

No* inserir_final(No* head, int valor){
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->proximo = NULL;

    if(head == NULL) return novo;
    No* atual = head;
    while(atual->proximo != NULL){
        atual = atual->proximo;
    }
    atual->proximo = novo;
    return head;
}

int contar_pares_recursiva(No* head){
    No* atual = head;
    if(atual == NULL) return 0;
    if(atual->dado % 2==0){
        return 1 + contar_pares_recursiva(head->proximo);
    } else{
        return 0 + contar_pares_recursiva(head->proximo);
    }
}

// int contar_pares(No* head){
//     int contador_pares = 0;
//     No* atual = head;
//     while(atual != NULL){
//         if(atual->dado % 2 == 0){
//             contador_pares++;
            
//         }
//         atual = atual->proximo;
//     }
//     return contador_pares;
// }

No* remover_impares(No* head){
    // 1. Remover ímpares do início da lista
    while(head != NULL && head->dado % 2 != 0){
        No* temp = head;
        head = head->proximo;
        free(temp);
    }
    if(head == NULL) return NULL;

    // 2. Remover ímpares do resto da lista
    No* anterior = head;
    No* atual = head->proximo;
    while(atual != NULL){
        if(atual->dado % 2 != 0){
            anterior->proximo = atual->proximo;
            free(atual);
            atual = anterior->proximo; // continua do próximo nó
        } else {
            anterior = atual;
            atual = atual->proximo;
        }
    }
    return head;
}

void imprimir(No* head){
    No* atual = head;
    while(atual != NULL){
        printf("%d -> ", atual->dado);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

int main(){
    ////Teste seu programa inserindo os números: 10, 3, 7, 8, 12, 15, 20.
    No* head = NULL;
    head = inserir_final(head, 10);
    head = inserir_final(head, 3);
    head = inserir_final(head, 7);
    head = inserir_final(head, 8);
    head = inserir_final(head, 12);
    head = inserir_final(head, 15);
    head = inserir_final(head, 20);
    imprimir(head);
    printf("Quantidade de elementos pares na lista: %d\n\n",contar_pares_recursiva(head));
    head = remover_impares(head);
    printf("Lista com remocao dos impares:\n");
    imprimir(head);

    return 0;
}