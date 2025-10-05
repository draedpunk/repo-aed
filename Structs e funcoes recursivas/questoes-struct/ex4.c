#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char modelo[30];
    int ano;
    float preco;
} Carro;

int main(){
    Carro *car = (Carro*) malloc(sizeof(Carro));
    
    Carro temp = {"Dodge 69", 1969, 94.400};
    *car = temp;

    printf("--- Dados do Carro ---\n");
    printf("Modelo: %s\n", car->modelo);
    printf("Ano de lancamento: %d\n", car->ano);
    printf("Preco: %.3f\n", car->preco);

    free(car);
    return 0;
}