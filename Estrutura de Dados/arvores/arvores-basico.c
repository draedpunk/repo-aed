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

No* encontrar_minimo(struct No* no) {
    // O menor valor está na extrema esquerda
    while (no->esquerda != NULL)
    no = no->esquerda;
    return no;
}

No* remover(struct No* raiz, int valor) {
    if (raiz == NULL) return raiz; // Caso base: árvore vazia

    // Se o valor for menor, busca na sub-árvore esquerda
    if (valor < raiz->dado) raiz->esquerda = remover(raiz->esquerda, valor);
    // Se o valor for maior, busca na sub-árvore direita
    else if (valor > raiz->dado) raiz->direita = remover(raiz->direita, valor);
    else {
        if (raiz->esquerda == NULL && raiz->direita == NULL) { // Caso 1: Nó sem filhos
            free(raiz);
            return NULL;
        } else if (raiz->esquerda == NULL) { // Caso 2: Nó com um filho
            struct No* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) { // ainda caso 2
            struct No* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }
        // Caso 3: Nó com DOIS filhos
        // Encontra o sucessor
        No* temp = encontrar_minimo(raiz->direita);
        // Substitui o valor
        raiz->dado = temp->dado;
        // Remove o sucessor
        raiz->direita = remover(raiz->direita, temp->dado);
    }
        // Retorna a raiz atualizada
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
    raiz = inserir(raiz, 15);
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 20);
    // raiz = inserir(raiz, 69);
    // raiz = inserir(raiz, 80);

    printf("Pre-ordem: ");
    pre_ordem(raiz);
    printf("\nEm ordem: ");
    em_ordem(raiz);
    printf("\nPos-ordem: ");
    pos_ordem(raiz);
    printf("\n");

    return 0;
}