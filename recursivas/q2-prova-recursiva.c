#include <stdio.h>
#include <stdlib.h>

int soma_vetor(int vetor[], int n){
    if(n == 0) return 0;
    
    return vetor[n-1]+ soma_vetor(vetor, n-1);

}

int main(){
    int vetor[] = {1, 2,3, 4, 5};
    int resultado = soma_vetor(vetor,5);

    // for (int i=0; i<5; i++){
    //     resultado += vetor[i];
    // }
    printf("%d\n", resultado);
    return 0;
}