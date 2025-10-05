#include <stdio.h>

struct {
    char nome[50];
    char cargo[30];
    float salario;
} typedef Funcionario;

int main(){
    int quantidade;
    printf("Informe a quantidade de funcionarios a serem cadastrados:\n");
    scanf("%d", &quantidade);

    Funcionario f[quantidade];

    for (int i=0; i< quantidade; i++){
        printf("Insira o nome do funcionario %d:\n", i+1);
        scanf("%s",f[i].nome);

        printf("Insira o cargo do funcionario %d:\n", i+1);
        scanf("%s",f[i].cargo);

        printf("Insira o salario do funcionario %d:\n", i+1);
        scanf("%f", &f[i].salario);
    }

    printf("--- Relatorio Geral dos Funcionarios ---\n");
    for (int i=0; i < quantidade; i++){
        printf("Nome do funcionario %d: %s\n", i+1, f[i].nome);
        printf("Cargo do funcionario %d: %s\n", i+1, f[i].cargo);
        printf("Salario do funcionario %d: %.2f\n", i+1, f[i].salario);
    }
    return 0;
}