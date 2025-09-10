// Crie uma struct chamada Livro, que contenha:
// Título (string de até 50 caracteres)
// Autor (string de até 50 caracteres)
// Ano de publicação (inteiro)
// Crie uma função que recebe um vetor de Livro e 
// exibe os livros publicados após um determinado ano (definido pelo usuário).

#include <stdio.h>
#include <string.h>

typedef struct {
    char titulo[50];
    char autor[50];
    int ano;
} Livro;

void exibir_livros(Livro l[], int ano){
    int flag = 0;
    printf("Livros publicados apos %d:\n", ano);

    for(int i=0; i < 5; i++){
        if(l[i].ano >= ano){
            printf("%d - %s por %s\n", i+1, l[i].titulo, l[i].autor);
            flag = 1;
        }
    }

    if(!flag){
        printf("Nenhum livro encontrado.\n");
    }

}

int main(){
    int ano_usuario;
    printf("Informe o ano minimo de publicacao de livros:\n");
    scanf("%d", &ano_usuario);

    Livro books[5];

    strcpy(books[0].titulo, "Dracula");
    strcpy(books[0].autor, "Bram Stoker");
    books[0].ano = 1897;

    strcpy(books[1].titulo, "Frankenstein");
    strcpy(books[1].autor, "Mary Shelley");
    books[1].ano = 1818;

    strcpy(books[2].titulo, "The Picture of Dorian Gray");
    strcpy(books[2].autor, "Oscar Wilde");
    books[2].ano = 1890;

    strcpy(books[3].titulo, "Strange Case of Dr. Jekyll and Mr. Hyde"); 
    strcpy(books[3].autor, "Robert Louis Stevenson");
    books[3].ano = 1886;

    strcpy(books[4].titulo, "The Raven");
    strcpy(books[4].autor, "Edgar Allan Poe");
    books[4].ano = 1845;

    exibir_livros(books, ano_usuario);

    return 0;
}