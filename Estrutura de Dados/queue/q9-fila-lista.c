// 9. Implementação de uma Fila com Vetor
// Implemente uma fila usando um vetor e forneça as seguintes operações:
// • enqueue: inserir um elemento no final da fila.
// • dequeue: remover um elemento do início da fila.
// • front: exibir o primeiro elemento.
// • isEmpty: verificar se a fila está vazia.
#include <stdio.h>
#include <stdlib.h>

typedef struct Fila{
    int dado;
    struct Fila* proximo;
} Fila;

int isEmpty(Fila* comeco){
    return comeco == NULL;
}

Fila* enqueue(Fila* fim, int valor){
    Fila* nova = (Fila*)malloc(sizeof(Fila));
    nova->dado = valor;
    nova->proximo = NULL;

    while(fim != NULL) fim->proximo = nova;
    return nova;
}

Fila* dequeue(Fila* comeco){
    if(isEmpty(comeco)) return NULL;
    
    Fila* temp = comeco;
    comeco = comeco->proximo;
    free(temp);
    return comeco;
}

Fila* front(Fila* comeco){
    if(isEmpty(comeco)) return NULL;

}

void imprimir(Fila* comeco){
    Fila* atual = comeco;
    while(atual != NULL){
        printf("%d - ", atual->dado);
        atual = atual->proximo;
    }
}


int main(){
    Fila* comeco = NULL;
    comeco = enqueue(comeco, 5);
    comeco = enqueue(comeco, 75);
    comeco = enqueue(comeco, 11);
    comeco = enqueue(comeco, 12);
    comeco = enqueue(comeco, 2);
    imprimir(comeco);

    return 0;
}