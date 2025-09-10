#include <stdio.h>
#include <stdlib.h>

typedef struct No {// formato de um nó da lista: ele tem o espaço pro dado e o ponteiro pro PROXIMO nó
    int dado; 
    struct No* proximo;
} No;

No* criar_no(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->proximo = NULL;
    return novo;
}

void inserir_no_inicio(No** cabeca, int valor) {
    No* novo = criar_no(valor);
    novo->proximo = *cabeca;
    *cabeca = novo;
}

void inserir_no_fim(No** cabeca, int valor) {
    No* novo = criar_no(valor);
    if (*cabeca == NULL) {
        *cabeca = novo;
        return;
    }
    No* temp = *cabeca;
    while (temp->proximo != NULL) {
        temp = temp->proximo;
    }
    temp->proximo = novo;
}

void exibir_lista(No* cabeca) {
    No* temp = cabeca;
    while (temp != NULL) {
        printf("%d -> ", temp->dado);
        temp = temp->proximo;
    }
    printf("NULL\n");
}

void deletar(No** cabeca, int valor) {
    No* temp = *cabeca, *anterior = NULL;

    // Se o nó a ser deletado é o primeiro
    if (temp != NULL && temp->dado == valor) {
        *cabeca = temp->proximo; // Muda a cabeça
        free(temp); // Libera a memória do nó antigo
        return;
    }

    // Procura pelo nó a ser deletado, mantendo o controle do nó anterior
    while (temp != NULL && temp->dado != valor) {
        anterior = temp;
        temp = temp->proximo;
    }

    // Se o valor não foi encontrado na lista
    if (temp == NULL) return;

    // Desconecta o nó da lista e libera a memória
    anterior->proximo = temp->proximo;
    free(temp);
}

int main() {
    No* lista = NULL;

    inserir_no_fim(&lista, 10);
    inserir_no_fim(&lista, 20);
    inserir_no_inicio(&lista, 5);
    exibir_lista(lista); // Deve mostrar: 5 -> 10 -> 20 -> NULL

    deletar(&lista, 10);
    exibir_lista(lista); // Deve mostrar: 5 -> 20 -> NULL

    // Libera a memória restante
    while (lista != NULL) {
        No* temp = lista;
        lista = lista->proximo;
        free(temp);
    }

    return 0;
}
