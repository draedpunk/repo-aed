// 5. Implementação de uma Pilha com Vetor
// Implemente uma pilha usando um vetor e forneça as seguintes operações:
// • push: inserir um elemento no topo.
// • pop: remover o elemento do topo.
// • top: exibir o elemento do topo.
// • isEmpty: verificar se a pilha está vazia.
#include <stdio.h>
#include <stdlib.h>

typedef struct Pilha{
    int dado;
    struct Pilha* proximo;
} Pilha;

Pilha* push(Pilha* topo, int valor){
    Pilha* nova = (Pilha*)malloc(sizeof(Pilha));
    nova->dado = valor;
    nova->proximo = topo;
    return nova;
}

int isEmpty(Pilha* topo){
    return topo==NULL;
}

Pilha* pop(Pilha* topo, int valor){
    if(isEmpty(topo)) return NULL;

    Pilha* temp = topo;
    topo = topo->proximo;
    free(temp);
    return topo;
}

Pilha* top(Pilha* topo){ // ou peek
    if(isEmpty(topo)) return NULL;
    return topo;
}

void imprimir(Pilha* topo){
    Pilha* atual = topo;

    printf("TOPO\n");
    while(atual != NULL){
        printf("%d\n", atual->dado);
        atual = atual->proximo;
    }
    printf("BASE\n");
}

int main(){
    Pilha* topo = NULL;
    topo = push(topo, 20);
    topo = push(topo, 2);
    topo = push(topo, 10);
    topo = push(topo, 4);
    topo = push(topo, 61);

    int valor_no_topo = top(topo)->dado;
    printf("O elemento do topo da pilha eh %d.\n", valor_no_topo);

    imprimir(topo);

    return 0;
}