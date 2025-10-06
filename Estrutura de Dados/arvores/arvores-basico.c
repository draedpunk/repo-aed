#include <stdio.h>
#include <stdlib.h>

typedef struct No{ // estrutura da arvore
    int dado;
    struct No* esquerda;
    struct No* direita;
} No;

No* criar_no(int valor){ // criacao de novo no na arvore
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;

    return novo;
}

No* inserir(No* raiz, int valor){ // inserindos os nos conforme a regra
    if(raiz == NULL) return criar_no(valor);

    // valores MAIORES que a raiz = DIREITA
    // valores MENORES que a raiz = ESQUERDA
    if(valor < raiz->dado)
        raiz->esquerda = inserir(raiz->esquerda, valor);
    else
        raiz->direita = inserir(raiz->direita, valor);

    return raiz;
}


void pre_ordem(No* raiz){ // (raiz, esquerda, direita);
    if(raiz != NULL){
        printf("%d ", raiz->dado);
        pre_ordem(raiz->esquerda);
        pre_ordem(raiz->direita);   
    }
}

// imprime os valores na ordem crescente
void em_ordem(No* raiz){ // (esquerda, raiz, direita)
    if(raiz != NULL){
        em_ordem(raiz->esquerda);
        printf("%d ", raiz->dado);
        em_ordem(raiz->direita);
    }
}

void pos_ordem(No* raiz){ // (esquerda, direita, raiz)
    if(raiz != NULL){
        pos_ordem(raiz->esquerda);
        pos_ordem(raiz->direita);
        printf("%d ", raiz->dado);
    }
}

int main(){
    No* raiz = NULL;
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 69);
    raiz = inserir(raiz, 80);

    printf("Pre-ordem: ");
    pre_ordem(raiz);
    printf("\nEm ordem: ");
    em_ordem(raiz);
    printf("\nPos-ordem: ");
    pos_ordem(raiz);
    printf("\n");

    return 0;
}