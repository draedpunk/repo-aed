#include <stdio.h>

struct {
    char nome[50];
    int matricula;
    float nota;
} typedef Aluno;

int main(){
    Aluno alunos[5];

    printf("--- Dados do aluno ---");
    for (int i =0; i <5; i++){
        printf("Informe o nome do aluno %d:\n", i+1);
        scanf(" %s\n", alunos[i].nome);

        printf("Informe a matricula do aluno %d:\n", i+1);
        scanf("%d\n", &alunos[i].matricula);

        printf("Informe a nota do aluno %d\n:", i+1);
        scanf("%f", &alunos[i].nota);
    }
    printf("ok\n");

    return 0;
}