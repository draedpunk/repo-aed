#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int dado;
    struct No* proximo;
} No;

int isEmpty(No* head){
    return head ==NULL;
}

No* inserir_final(No* head, int valor){
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->proximo = NULL;

    if(isEmpty(head)) return novo;

    No* atual = head;
    while(atual->proximo != NULL){
        atual =atual->proximo;
    }
    atual->proximo = novo;
    return head;
}

int contar_ocorrencias(No* head, int valor){
    int contador = 0;
    No* atual = head;
    while(atual !=NULL){
        if(atual->dado == valor) {
            contador++;
        }
        atual=atual->proximo;
    }
    return contador;
}

void imprimir(No* head){
    No* atual =head;
    while(atual != NULL){
        printf("%d -> ", atual->dado);
        atual =atual->proximo;
    }
    printf("NULL\n");
}

int main(){
    No* head =NULL;

    //Teste com os valores: 5, 8, 5, 10, 8, 12, 5.
    for(int i=0; i <7; i++){
        int v;
        printf("Informe o %d elemento da lista:\n", i+1);
        scanf("%d", &v);
        head = inserir_final(head, v);
    }
    printf("---------- LISTA ----------\n");
    imprimir(head);

    printf("\n-------- CONTAR OCORRENCIAS --------\n");
    int num;
    printf("Informe um numero:\n");
    scanf("%d", &num);
    printf("O valor %d aparece %d vez(es) na lista\n", num, contar_ocorrencias(head, num));
    return 0;
}
