// 6. Verificar se uma String é Palíndromo
// Implemente uma função recursiva que recebe uma string e retorna 1 se for um
// palíndromo e 0 caso contrário.
// Exemplo:
// • palindromo("arara") → 1
// • palindromo("casa") → 0
#include <stdio.h>
#include <string.h>

int eh_palindromo_rec(char palavra[], int i, int j){
    if(i >= j) return 1;                  // chegou no meio → palíndromo
    if(palavra[i] != palavra[j]) return 0; // caracteres diferentes → não é palíndromo
    return eh_palindromo_rec(palavra, i+1, j-1); // continua recursão
}

// Função principal que o usuário chama
int eh_palindromo(char palavra[]){
    int tamanho = strlen(palavra);
    return eh_palindromo_rec(palavra, 0, tamanho-1);
}

int main(){
    char palavra[10];
    printf("Informe uma palavra:\n");
    scanf(" %s", palavra);

    if(eh_palindromo(palavra)){
        printf("Eh palindromo\n");
    } else{
        printf("Nao eh palindromo\n");
    }

    // int tamanho = strlen(palavra);
    // for(int i =0; i < tamanho/2;i++){
    //     int j = tamanho - 1 - i;
    //     if(palavra[i] != palavra[j]){
    //         printf("nao eh palindrormo");
    //         return 0;
    //     }
    // }
    // printf("eh palindrormo");
    return 1;
}