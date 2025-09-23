// Online C compiler to run C program online
// 1. Número de Dígitos de um Inteiro
// Implemente uma função recursiva que recebe um número inteiro n e retorna a
// quantidade de dígitos que ele possui.
// Exemplo:
// • contar_digitos(12345) → 5
// • contar_digitos(7) → 1
#include <stdio.h>
#include <stdlib.h>

int contar_numero(long long int num){
    int cont_tamanho = 0;
    if(num == 0){
        cont_tamanho = 1;
    } else{
        if (num < 0){
            num = -num; // isso aqui transforma pra psotivo
        }
        while (num > 0){
            num /= 10; // as casas decimais sao truncadas, ent 12345/10 fica 1234 (.5 vai embora)
            cont_tamanho++; // e o contador so contando quantas vezes esse loop acontece ate ser 0
        }
    }
    return cont_tamanho;

}

int main() {
    // Write C code here
    long long num;
    int cont_tamanho = 0;
    printf("Informe um numero inteiro:\n");
    scanf("%lld", &num);

    printf("O numero de digitos eh: %d\n", contar_numero(num));
    
    
    return 0;
}