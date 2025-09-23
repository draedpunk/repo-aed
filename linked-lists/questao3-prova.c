#include <stdio.h>
#include <stdlib.h>

typedef struct no{ // primeiro eu crio a struct do no
    int dado;
    struct no *proximo;
} No;

No* inserir_inicio(No* head, int valor){
    No* novo = (No*)malloc(sizeof(No)); // primeiro eu aloco a memoria pro novo no que sera inserido
    novo->dado = valor; //atrbuo o dado ao valor do parametro da funcao
    novo->proximo = head; // o proximo no vai ser o head atual

    return novo; // retorno o novo no que agr é o head
}

void exibir(No* head){
    No* atual = head; // crio o ´ponteiro atual q vai me ajudar a percorrer todos os nós da lista

    printf("HEAD -> ");
    while(atual != NULL){ // enquanto o atual n for nulo, ou seja, n chegar no final da lista..
        printf("%d -> ", atual->dado); // vou printando todos os valores em dado
        atual = atual->proximo; // isso aq serve tipo um contatdor ou um i++ em um loop for
    }
    printf("NULL\n");
}

int main(){
    No* head = NULL; // PRECISO inicira  a lista vazia atribuindo NULL ao head
    head = inserir_inicio(head, 10);
    head = inserir_inicio(head, 20);
    head = inserir_inicio(head, 40);
    head = inserir_inicio(head, 80);
    exibir(head);
    return 0;
}