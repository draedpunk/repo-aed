#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Pilha{
    int valor;
    struct Pilha* proximo;
} Pilha;

Pilha* push(Pilha* topo, int valor){
    Pilha* nova = (Pilha*)malloc(sizeof(Pilha));
    nova->valor = valor;
    nova->proximo = topo;
    return nova;
}

int isEmpty(Pilha* topo){
    return topo == NULL;
}

Pilha* pop(Pilha* topo){
    if (isEmpty(topo)) return NULL; // pilha vazia, ent n tem nada pra remover
    
    Pilha* temporario = topo; // guarda o topo atual
    topo = topo->proximo; // move o valor do topo pro proximo elemento na pilha
    free(temporario); // libera a memoria do antigo topo
    return topo; // retorna o novo topo
}

Pilha* peek(Pilha* topo){ // devolve um ponteiro para o nó que está no topo
    if(isEmpty(topo)) return NULL;
    return topo;
}

int size(Pilha* topo){
    int contador = 0;
    Pilha* atual = topo;

    while(atual != NULL){
        contador++;
        atual= atual->proximo; // loop roda ate isso ser NULL pq aí acabou a pilha
    }
    return contador;
}

void imprimir_pilha(Pilha* topo){
    Pilha* atual = topo;

    printf("TOPO\n");
    while(atual != NULL){
        printf("%d\n", atual->valor);
        atual = atual->proximo; // o loop roda ate isso ser NULL
    }
    printf("BASE\n");
}

int main(){
    Pilha* topo = NULL; // comeca com a pilha vazia

    printf("---- PILHAS ----\n");
    topo = push(topo, 60);
    topo = push(topo, 70);
    topo = push(topo, 80);
    topo = push(topo, 90);
    topo = push(topo, 100);
    
    imprimir_pilha(topo);
    
    int valor_topo = peek(topo)->valor;

    printf("- Valor do topo da pilha: %d\n", valor_topo);
    printf("- Tamanho da pilha: %d elementos\n", size(topo));

    return 0;
}