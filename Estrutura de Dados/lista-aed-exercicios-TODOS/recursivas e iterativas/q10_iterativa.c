#include <stdio.h>

//iterativa da questao 4
int main(){
    int a, b;
    printf("Informe o multiplicando (A):\n");
    scanf("%d", &a);
    printf("Informe o multiplicador (B):\n");
    scanf("%d", &b);

    int produto = 0;
    for (int i=0; i < b; i++){
        produto += a;
    }
    printf("O produto da operacao eh: %d", produto);
    return 0;
}