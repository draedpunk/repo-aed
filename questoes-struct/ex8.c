#include <stdio.h>

typedef struct{
    float largura;
    float altura;

} Retangulo;

float area(Retangulo r){
    return r.largura * r.altura;
}

float perimetro(Retangulo r){
    return 2*(r.largura + r.altura);
}

int main(){
    Retangulo rzinho;
    printf("--- Dados do Retangulo ---\n");
    printf("Informe a largura: ");
    scanf("%f", &rzinho.largura);
    printf("Informe a altura: ");
    scanf("%f", &rzinho.altura);

    printf("\n--- Resultados ---\n");
    printf("Area: %.2fm²\n", area(rzinho));
    printf("Perimetro: %.2fm\n", perimetro(rzinho));

    return 0;
}