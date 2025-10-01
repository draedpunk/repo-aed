//ALUNOS: 
//DIEGO DAVID ALVES XAVIER
// HYNGRID SOUZA E SILVA
// PAMELA TEIXEIRA RODRIGUES

//DISCIPLINA: ALGORITMOS E ESTRUTURAS DE DADOS (2025.2)
//PROFESSOR: JOSÉ MAURICIO DA SILVA JÚNIOR

//TURMA EMBARQUE DIGITAL 

#include <stdio.h>
#include <stdlib.h>

typedef struct Tarefa{
    int id;
    char descricao[50];
    int prioridade;
} Tarefa;

typedef struct Fila {
    Tarefa tarefa;
    struct Fila* prox;
} Fila;

typedef struct Pilha {
    Tarefa tarefa;
    struct Pilha* prox;
} Pilha;


void imprimir_Fila(Fila* fila) {
    
    if(fila == NULL) {
        printf("\n");
        printf("A fila esta vazia.\n");
        return;
    }

    printf("\n---- Tarefas na Fila ----\n");
    while (fila != NULL) {
        printf("ID: %d | Descricao: %s | Prioridade: %d\n", fila->tarefa.id, 
            fila->tarefa.descricao, fila->tarefa.prioridade);
        fila = fila->prox;
    }
}

void imprimir_Pilha(Pilha* pilha) {

    if(pilha == NULL) {
        printf("\n");
        printf("A pilha esta vazia.\n");
        return;
    }

    printf("\n---- Tarefas na Pilha ----\n");
    while (pilha != NULL) {
        printf("ID: %d | Descricao: %s | Prioridade: %d\n", pilha->tarefa.id, 
            pilha->tarefa.descricao, pilha->tarefa.prioridade);
        pilha = pilha->prox;
    }
}

Pilha* inserir_Pilha(Pilha* topo, Tarefa tarefa) {
    Pilha* novo = (Pilha*)malloc(sizeof(Pilha));
    novo->tarefa = tarefa;
    novo->prox = topo;
    return novo;
}

Fila* inserir_Fila(Fila* comeco, Tarefa tarefa) {
    Fila* novo = (Fila*)malloc(sizeof(Fila));
    novo->tarefa = tarefa;
    novo->prox = NULL;
    if (comeco == NULL) {
        return novo;
    } else {
        Fila* temp = comeco;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = novo;
        return comeco;
    }
}

int main (){

    Tarefa tarefas[5];
    Fila* fila = NULL;
    Pilha* pilha = NULL;

    
    for (int i = 0; i < 5; i++) { 
        printf("---- Tarefa %d ----\n", i + 1);
        tarefas[i].id = i + 1; // PARA COLOCAR O ID AUTOMATICO, POIS TAVA MUITO REPETITIVO
        printf("Informe a descricao da tarefa %d: ", i + 1);
        scanf(" %[^\n]", tarefas[i].descricao);
        printf("Informe a prioridade da tarefa %d (1= alta / 2= media / 3= baixa): ", i + 1);
        scanf("%d", &tarefas[i].prioridade);
        printf("\n");        
    }

    for (int i = 0; i < 5; i++) {
        if (tarefas[i].prioridade == 1) { //INSERÇAO NA PILHA
            pilha = inserir_Pilha(pilha, tarefas[i]);
        } else {  //INSERÇAO NA FILA
            fila = inserir_Fila(fila, tarefas[i]);                     
        }
    }
    imprimir_Pilha(pilha);

    imprimir_Fila(fila);

    return 0;
}