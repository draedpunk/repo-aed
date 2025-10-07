#include <stdio.h>
#include <stdlib.h>

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

No* inserir(No* raiz, int valor){
    if(raiz == NULL) return criar_no(valor);

    if(valor < raiz->dado){
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else{
        raiz->direita = inserir(raiz->direita, valor);
    }
    return raiz;
}

No* buscar_menor_sucessor(No* no){
    while(no->esquerda != NULL){
        no = no->esquerda;
    }
    return no;
}

No* remover(No* raiz, int valor){
    if(raiz == NULL) return raiz;

    if(valor < raiz->dado) raiz->esquerda = remover(raiz->esquerda, valor); 
    else if(valor > raiz->dado) raiz->direita= remover(raiz->direita, valor);
    else{
        if(raiz->esquerda == NULL && raiz->direita == NULL){ // no sem filhos
            free(raiz);
            return NULL;
        } else if(raiz->esquerda == NULL){ // no com 1 filho
            No* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if(raiz->direita == NULL){ // no com 1 filho
            No* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }
        // no com 2 filhos
        No* temp = buscar_menor_sucessor(raiz->direita); // pega o menor sucessor (sub-arvore direita)
        raiz->dado = temp->dado;
        raiz->direita = remover(raiz->direita, temp->dado);
        return raiz;
    }
}

void pre_ordem(No* raiz){
    if(raiz !=NULL){
        printf("%d ", raiz->dado);
        pre_ordem(raiz->esquerda);
        pre_ordem(raiz->direita);
    }
}

void em_ordem(No* raiz){
    if (raiz != NULL){
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
    //Insira os seguintes valores em uma árvore binária de busca: 50, 30, 70, 20, 40, 60, 80
    No* raiz = NULL;
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 60);
    raiz = inserir(raiz, 80);

    em_ordem(raiz); // output -> 20 30 40 50 60 70 80

    printf("Remocao do 20:\n");
    raiz = remover(raiz, 20);
    em_ordem(raiz);
    printf("\n");

    printf("Remocao do 30:\n");
    raiz = remover(raiz, 30);
    em_ordem(raiz);
    printf("\n");

    printf("Remocao do 50:\n");
    raiz = remover(raiz, 50);
    em_ordem(raiz);


    return 0;
}