#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    char telefone[15];
} Contato;

void adicionar_contato(Contato agenda[], int *i){
    printf("\n--- Adicionar Novo Contato ---\n");
    printf("Nome: ");
    scanf(" %[^\n]", agenda[*i].nome);
    
    printf("Telefone: ");
    scanf(" %[^\n]", agenda[*i].telefone);
    (*i)++;

}

void buscar_contato(Contato agenda[]){
    char nome_busca[50];

    printf("\n--- Buscar Contato ---\n");
    printf("Informe o nome do contato: ");
    scanf(" %[^\n]", nome_busca);

    for (int i =0; i < 20; i++){
        if(strcmp(agenda[i].nome, nome_busca) == 0){
            printf("Contato encontrado:\n");
            printf("Nome: %s\n", agenda[i].nome);
            printf("Telefone: %s\n", agenda[i].telefone);
            return;
        } else {
            printf("Contato nao encontrado.\n");
            return;
        }

    }
}

int main(){
    Contato agenda[20];
    int opcao, i = 0;

    do {
        printf("\n--- Agenda Telefonica ---\n");
        printf("1. Adicionar Contato\n");
        printf("2. Buscar Contato\n");
        printf("3. Sair\n\n");
        printf("- Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                adicionar_contato(agenda, &i);
                break;
            case 2:
                buscar_contato(agenda);
                break;
            case 3:
                printf("Saindo da agenda...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

    } while(opcao != 3);

    return 0;
}