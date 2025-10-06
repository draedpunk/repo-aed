#include <stdio.h>

struct {
    char nome[30];
    int codigo;
    float preco;
} typedef Produto;

void exibir_produto(Produto x){
    printf("--- Dados do Produto ---\n");
    printf("Nome: %s\n", x.nome);
    printf("Codigo: %d\n", x.codigo);
    printf("Preco: R$ %.2lf\n", x.preco);
}

int main(){
    Produto x;

    printf("--- Insira as informacoes do Produto ---\n");
    printf("Nome do produto:\n");
    scanf(" %s", x.nome);
    printf("Codigo do produto:\n");
    scanf("%d", &x.codigo);
    printf("Preco deste produto:\n");
    scanf("%f", &x.preco);
    
    exibir_produto(x);

    return 0;
}