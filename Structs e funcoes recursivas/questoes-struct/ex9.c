#include <stdio.h>

typedef struct {
    char nome[50];
    int idade;
    char diagnostico[100];
} Paciente;

void exibir_acima_sessenta(Paciente p[], int tam){
    int flag =0;
    
    printf("\n--- Pacientes Acima de 60 anos ---\n");

    for (int i =0; i < tam; i++){
        if(p[i].idade >= 60){
            printf("%d. Nome: %s | %d anos | Diagnostico: %s\n", i+1, p[i].nome, p[i].idade, p[i].diagnostico);
            flag = 1;
        }
    }
    if (!flag){
        printf("Nao ha pacientes maiores que 60 anos registrados.\n");
    }
}

int main() {
    // Write C code here
    Paciente pacientes[4];
    
    printf("\n--- Dados dos Pacientes ---\n");
    for (int i=0; i < 4; i++){
        printf("Nome do paciente %d: ", i+1);
        scanf(" %[^\n]", pacientes[i].nome);

        printf("Idade do paciente %d: ", i+1);
        scanf("%d", &pacientes[i].idade);

        printf("Diagnostico do paciente %d: ", i+1);
        scanf(" %[^\n]", pacientes[i].diagnostico);
    }
    printf("\n");
    printf("Pacientes registrados!\n\n");
    
    exibir_acima_sessenta(pacientes, 4);

    return 0;
}