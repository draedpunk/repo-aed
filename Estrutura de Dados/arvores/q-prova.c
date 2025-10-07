#include <stdio.h>
#include <stdlib.h>

// 1- Contar nós totais - ok
// 2- Somar todos os valores dos nós - ok
// 3- Contar folhas (nós sem filhos) - OK
// 4- Contar nós com filhos - OK
// 5- Altura da árvore
// 6- Contar nós maiores que X
// 7 - Encontrar valor máximo e mínimo

typedef struct No{
    int dado;
    struct No* esquerda;
    struct No* direita;
} No;

No* criar_no(int valor){
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;

    return novo;
}

No* inserir_no(No* raiz, int valor){
    if(raiz == NULL) return criar_no(valor);

    if(valor < raiz->dado) raiz->esquerda = inserir_no(raiz->esquerda, valor);
    else 
        raiz->direita = inserir_no(raiz->direita, valor);
    return raiz;
}

No* buscar_menor_sucesso(No* no){
    while(no->esquerda != NULL){
        no = no->esquerda;
    }
    return no;
}

void nos_com_filhos(No* no){
    if(no == NULL) return;

    if(no->esquerda != NULL || no->direita != NULL){
        printf("%d ", no->dado);
    }
    nos_com_filhos(no->esquerda);
    nos_com_filhos(no->direita);
}

int contar_folhas(No* no){
    if(no == NULL) return 0;

    if(no->esquerda == NULL && no->direita == NULL)
        return 1;

    return contar_folhas(no->esquerda) + contar_folhas(no->direita);
}

int contar_nos_totais(No* no){
    if(no == NULL) return 0;
    return 1 +contar_nos_totais(no->esquerda) + contar_nos_totais(no->direita);
}

int somar_valores_nos(No* no) {
    if (no == NULL)
        return 0;
    return no->dado + somar_valores_nos(no->esquerda) + somar_valores_nos(no->direita);
}

No* remover(No* raiz, int valor){
    if(raiz == NULL) return raiz; // se so tem a raiz, ent remove ela

    if(valor < raiz->dado) raiz->esquerda = remover(raiz->esquerda, valor);
    else if(valor > raiz->dado) raiz->direita = remover(raiz->direita, valor);
    else{
        if(raiz->esquerda == NULL || raiz->direita == NULL){
            free(raiz);
            return NULL;
        } else if(raiz->esquerda == NULL){
            No* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if(raiz->direita == NULL){
            No* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }
        No* temp = buscar_menor_sucesso(raiz->direita);
        raiz->dado = temp->dado;
        raiz->direita = remover(raiz->direita, temp->dado);
        return raiz;
    }
}

void pre_ordem(No* raiz){
    if(raiz != NULL){
        printf("%d ", raiz->dado);
        pre_ordem(raiz->esquerda);
        pre_ordem(raiz->direita);
    }
}

void em_ordem(No* raiz){
    if(raiz !=NULL){
        em_ordem(raiz->esquerda);
        printf("%d ", raiz->dado);
        em_ordem(raiz->direita);
    }
}

void pos_ordem(No* raiz){
    if(raiz != NULL){
        pos_ordem(raiz->esquerda);
        pos_ordem(raiz->direita);
        printf("%d ", raiz->dado);
    }
}

int main(){
    No* raiz = NULL;
    raiz = inserir_no(raiz, 15);
    raiz = inserir_no(raiz, 10);
    raiz = inserir_no(raiz, 50);
    raiz = inserir_no(raiz, 20);
    raiz = inserir_no(raiz, 69);
    raiz = inserir_no(raiz, 80);

    printf("Pre-ordem: ");
    pre_ordem(raiz);
    printf("\nEm ordem: ");
    em_ordem(raiz);
    printf("\nPos-ordem: ");
    pos_ordem(raiz);
    printf("\n");

    return 0;
}