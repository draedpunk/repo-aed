// 2. Maior Elemento em um Vetor
// Crie uma função recursiva que recebe um vetor de inteiros e seu tamanho n e
// retorna o maior valor presente no vetor.
// Exemplo:
// int maior_elemento(int vet[], int n);

#include <stdio.h>

int maior_elemento(int vet[], int n){
    // caso de parada: qd nao tiver mais elementos no vetor pra comparar
    if(n ==1) return vet[0];
    int maior_menos_ultimo = maior_elemento(vet, n-1);
    return (vet[n-1] > maior_menos_ultimo ? vet[n-1] : maior_menos_ultimo);


}

int main(){
    int n;
    printf("Informe o tamanho N do vetor:\n");
    scanf("%d", &n);

    int vetor[n];
    for (int i=0; i<n; i++){
        scanf("%d", &vetor[i]);
    }
    int maior = maior_elemento(vetor, n);
    // int maior = vetor[0];
    // for(int i=1; i <n; i++){
    //     if(vetor[i] > maior){
    //         maior = vetor[i];
    //     }
    // }

    printf("O maior elemento do vetor eh %d\n", maior);

    return 0;
}