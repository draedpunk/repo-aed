#include <stdio.h>

typedef struct{
    char nome[50];
    int idade;
    float altura;
} Pessoa;

int main(){
    Pessoa p = {"Pamela", 23, 1.49};
    printf("Nome: %s\nIdade: %d\nAltura: %.2f\n", p.nome, p.idade, p.altura);

    return 0;
}