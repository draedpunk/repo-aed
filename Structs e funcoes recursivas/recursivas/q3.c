// 3. Soma dos Dígitos de um Número
// Implemente uma função recursiva que recebe um número inteiro n e retorna a
// soma de seus dígitos.
// Exemplo: soma_digitos(1234) → 1 + 2 + 3 + 4 = 10.
#include <stdio.h>

int soma_digitos(int num){
    if(num == 0) return 0;// condicao de parada

    int ultimo_digito = num %10;
    return ultimo_digito + soma_digitos(num/10);
}

int main(){
    int num;
    printf("Informe um numero inteiro\n");
    scanf("%d", &num);
    // int acumulador =0;
    // int ultimo_digito;
    // while(num >0){
    //     ultimo_digito = num % 10;
    //     acumulador += ultimo_digito;
    //     num /= 10;
    // }
    printf("soma do digitos: %d\n", soma_digitos(num));

    
    return 0;
}