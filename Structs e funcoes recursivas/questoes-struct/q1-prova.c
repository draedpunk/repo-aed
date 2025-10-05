#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct endereco {
    char rua[30];
    int numero;
} Endereco;

typedef struct pessoa{
    char nome[50];
    Endereco *end;
} Pessoa;

int main(){
    Pessoa *p = (Pessoa*)malloc(sizeof(Pessoa));
    p->end = (Endereco*)malloc(sizeof(Endereco));
    strcpy(p->nome, "Pamela Rodrigues");
    strcpy(p->end->rua, "Rua Sao Gabriel");
    p->end->numero = 63;

    printf("---- Dados do Morador ----\n");
    printf("Nome: %s\n", p->nome);
    printf("Endereco: %s, %d\n", p->end->rua, p->end->numero);

    free(p->end);
    free(p);

    return 0;
}