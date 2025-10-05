#include <stdio.h>
#include <stdlib.h>

int contar_digitos_recursivo(long long num) {
    // 1. Caso base (condição de parada)
    // Se o número for 0, não tem mais dígitos para contar.
    if (num == 0) {
        return 0;
    }
    
    // 2. Passo recursivo
    // Retorna 1 (pelo dígito atual) + a chamada da própria função com o número dividido por 10
    return 1 + contar_digitos_recursivo(num / 10);
}

int main() {
    long long num;
    printf("Informe um numero inteiro:\n");
    scanf("%lld", &num);
    
    // Tratando os casos especiais (número 0 e negativos)
    int resultado;
    if (num == 0) {
        resultado = 1; // O número 0 tem um dígito
    } else if (num < 0) {
        // Se for negativo, pegamos o valor absoluto e contamos
        resultado = contar_digitos_recursivo(-num);
    } else {
        resultado = contar_digitos_recursivo(num);
    }

    printf("O numero de digitos eh: %d\n", resultado);
    
    return 0;
}