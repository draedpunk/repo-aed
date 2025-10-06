#include <stdio.h>
#include <stdlib.h>

typedef struct Fila {
    int dado;
    struct Fila* proximo;
} Fila;

typedef struct Pilha {
    int dado;
    struct Pilha* proximo;
} Pilha;

// funcoes FILA
int isEmptyFila(Fila* comeco) {
    return comeco == NULL;
}

Fila* enqueue(Fila* comeco, int valor) {
    Fila* nova = (Fila*)malloc(sizeof(Fila));
    nova->dado = valor;
    nova->proximo = NULL;

    if (comeco == NULL) {
        return nova;
    } else {
        Fila* atual = comeco;
        while (atual->proximo != NULL)
            atual = atual->proximo;
        atual->proximo = nova;
        return comeco;
    }
}

Fila* dequeue(Fila* comeco) {
    if (isEmptyFila(comeco)) return NULL;
    Fila* temp = comeco;
    comeco = comeco->proximo;
    free(temp);
    return comeco;
}

void imprimirFila(Fila* comeco) {
    Fila* atual = comeco;
    printf("Fila: ");
    while (atual != NULL) {
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }
    printf("\n");
}

// funcoes PILHA
int isEmptyPilha(Pilha* topo) {
    return topo == NULL;
}

Pilha* push(Pilha* topo, int valor) {
    Pilha* nova = (Pilha*)malloc(sizeof(Pilha));
    nova->dado = valor;
    nova->proximo = topo;
    return nova;
}

Pilha* pop(Pilha* topo) {
    if (isEmptyPilha(topo)) return NULL;
    Pilha* temp = topo;
    topo = topo->proximo;
    free(temp);
    return topo;
}

int top(Pilha* topo) {
    if (isEmptyPilha(topo)) return -1;
    return topo->dado;
}

Fila* inverterFila(Fila* comeco) {
    Pilha* pilha = NULL;
    Fila* aux = comeco;

    while (aux != NULL) {
        pilha = push(pilha, aux->dado);
        aux = aux->proximo;
    }

    while (!isEmptyFila(comeco)) {
        comeco = dequeue(comeco);
    }

    while (!isEmptyPilha(pilha)) {
        comeco = enqueue(comeco, top(pilha));
        pilha = pop(pilha);
    }
    return comeco;
}

int main() {
    Fila* fila = NULL;

    fila = enqueue(fila, 10);
    fila = enqueue(fila, 20);
    fila = enqueue(fila, 30);
    fila = enqueue(fila, 40);

    printf("Fila original:\n");
    imprimirFila(fila);

    fila = inverterFila(fila);

    printf("\nFila invertida:\n");
    imprimirFila(fila);

    while (!isEmptyFila(fila))
        fila = dequeue(fila);

    return 0;
}