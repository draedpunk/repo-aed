#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Fila{
    int dado;
    struct Fila *proximo;
} Fila;

Fila* enqueue(Fila* fim, int valor){ // adicionar na fila, ai entra no fim
    Fila* novo = (Fila*)malloc(sizeof(Fila));
    novo->dado = valor;
    novo->proximo = NULL;

    if (fim != NULL) fim->proximo = novo;
    return novo;
}

Fila* dequeue (Fila* comeco){ // remover da fila, sai do começo
    if (comeco == NULL) return NULL;
    Fila* temporario = comeco;
    comeco = comeco->proximo;
    free(temporario);
    return comeco;
}

void imprimir_fila(Fila* comeco){
    Fila* atual = comeco;

    printf("COMECO - ");
    while(atual !=NULL){
        printf("%d - ", atual->dado);
        atual = atual->proximo;
    }
    printf("FIM\n");
}

int main(){
    Fila* comeco = NULL;
    Fila* fim = NULL;

    printf("---- FILAS ----\n");
    comeco = enqueue(comeco, 10);
    comeco = enqueue(comeco, 20);
    comeco = enqueue(comeco, 30);   
    imprimir_fila(comeco);
    // comeco = dequeue(comeco);
    // imprimir_fila(comeco);
    return 0;
}