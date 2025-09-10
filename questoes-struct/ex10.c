#include <stdio.h>

typedef struct {
    char nome[50];
    int numero_conta;
    float saldo;
} ContaBancaria;

void depositar(ContaBancaria *conta, float deposito){
    conta->saldo += deposito;

    printf("Deposito de R$ %.2f realizado com sucesso!\n", deposito);
}

void sacar(ContaBancaria *conta, float saque){
    // verificar se o saldon nao é maior q o valor na conta
    if (saque > conta->saldo){
        printf("Saldo insuficiente para saque de R$ %.2f\n", saque);
    } else {
        conta->saldo -= saque;
        printf("Saque de R$ %.2f realizado com sucesso!\n", saque);
    }
}

void exibir_saldo(ContaBancaria conta){
    printf("Saldo atual: R$ %.2f\n", conta.saldo);
}

int main(){
    ContaBancaria c;
    int opcao;
    float valor;

    printf("--- Criacao de Conta Bancaria ---\n");
    printf("Nome do titular: ");
    scanf(" %[^\n]", c.nome);
    printf("Numero da conta: ");
    scanf("%d", &c.numero_conta);
    c.saldo = 0.0;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Depositar\n");
        printf("2. Sacar\n");
        printf("3. Exibir Saldo\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Valor do deposito: ");
                scanf("%f", &valor);
                depositar(&c, valor);
                break;
            case 2:
                printf("Valor do saque: ");
                scanf("%f", &valor);
                sacar(&c, valor);
                break;
            case 3:
                exibir_saldo(c);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 4);

    return 0;
}