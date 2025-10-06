#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pilha{
    int dado;
    struct Pilha* proximo;
} Pilha;

Pilha* push(Pilha* topo, int valor){
    Pilha* nova = (Pilha*)malloc(sizeof(Pilha));
    nova->dado = valor;
    nova->proximo = topo;
    return nova;
}

int isEmpty(Pilha* topo){
    return topo==NULL;
}

Pilha* pop(Pilha* topo){
    if(isEmpty(topo)) return NULL;
    Pilha* temp = topo;
    topo = topo->proximo;
    free(temp);
    return topo;
}

int verificacao_parenteses(char *expr){
    Pilha* pilha = NULL;
    for(int i = 0; i < strlen(expr); i++){
        if(expr[i] == '('){
            pilha = push(pilha, '(');
        } else if(expr[i] == ')'){
            if(isEmpty(pilha)){
                return 0; 
            } else {
                pilha = pop(pilha);
            }
        }
    }
    int valido = isEmpty(pilha);
    while(!isEmpty(pilha)) pilha = pop(pilha);

    return valido;
}

int main(){
    char teste1[] = "(())()";
    char teste2[] = "(()";

    printf("Expressao: %s -> %s\n", teste1, verificacao_parenteses(teste1) ? "valido" : "invalido");
    printf("Expressao: %s -> %s\n", teste2, verificacao_parenteses(teste2) ? "valido" : "invalido");

    return 0;
}