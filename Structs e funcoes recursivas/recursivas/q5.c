// 5. Contagem Regressiva
// Crie uma função recursiva que recebe um número n e imprime uma contagem
// regressiva até 0.
// Exemplo: contagem_regressiva(5) → 5, 4, 3, 2, 1, 0
#include <stdio.h>

void contagem_regressiva(int n){
    if (n < 0) return 0;
    printf("%d\n", n);
    contagem_regressiva(n-1);
}

int main(){
    int n;
    printf("Informe um numero inteiro positivo:\n");
    scanf("%d", &n);
    printf("\n");

    // for(int i= n; i >= 0; i--){
    //     printf("%d\n", i);
    // }
    contagem_regressiva(n);
    return 0;
}