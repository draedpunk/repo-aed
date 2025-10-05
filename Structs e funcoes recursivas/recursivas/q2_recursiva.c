// 2. Maior Elemento em um Vetor
// Crie uma função recursiva que recebe um vetor de inteiros e seu tamanho n e
// retorna o maior valor presente no vetor.
// Exemplo:
// int maior_elemento(int vet[], int n);

#include <stdio.h>

int maior_elemento(int vetor[], int n){
    if (n == 1) return vetor[0]; // caso base ou condicao de parada

    int sub_vetor = maior_elemento(vetor, n-1);

    if (vetor[n-1]> sub_vetor){
        return vetor[n-1];
    } else{
        return sub_vetor;
    } 
}

int main(){
    int n;
    printf("Informe o tamanho N do vetor:\n");
    scanf("%d", &n);

    int vetor[n];
    for (int i=0; i<n; i++){
        scanf("%d", &vetor[i]);
    }

    // int maior = vetor[0];
    // for(int i=1; i <n; i++){
    //     if(vetor[i] > maior){
    //         maior = vetor[i];
    //     }
    // }

    printf("O maior elemento do vetor eh %d\n", maior_elemento(vetor, n));

    return 0;
}