// 4. Produto de Dois Números Usando Somas Sucessivas
// Implemente uma função recursiva que calcula o produto de dois números
// inteiros a e b apenas usando somas sucessivas (sem usar *).
// Exemplo:
// • produto(5, 3) → 5 + 5 + 5 = 15
// • produto(7, 2) → 7 + 7 = 14
#include <stdio.h>

int produto(int a, int b){
    if (b == 0) return 0;
    if (b > 0){
        return a + produto(a, b - 1);
    }

}

int main(){
    int a, b;
    printf("Informe o multiplicando (A):\n");
    scanf("%d", &a);
    printf("Informe o multiplicador (B):\n");
    scanf("%d", &b);

    // int produto = 0;
    // for (int i=0; i < b; i++){
    //     produto += a;
    // }
    printf("O produto da operacao eh: %d", produto(a, b));
    return 0;
}