#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

int main(void){
    setlocale(LC_ALL, "portuguese_Brazil");
    while (1){

    puts("Obra: O Homem Amarelo");
    puts("Autor(a): Anita Malfatti");
    puts("Descrição da Obra: O Homem amarelo representa um imigrante italiano pobre"); puts("que posou para a artista Anita Malfatti na época em que ela estudava no");puts("exterior, a artista comenta que o modelo sustentava 'um olhar desesperado' naquele dia.");

    while(1){
        char escolha;
    puts("\n1-Sim (S)");
    printf("Deseja responder um breve questionário (S)? ");
    scanf("%s", &escolha);
    escolha = tolower(escolha);

    if (escolha == 's'){
        break;
    }else{
        printf("\nOpção inválida\n");
    }
    }

    char perguntas[5][1000] = {
       " Qual palavra melhor descreve as cores predominantes na obra (O Homem Amarelo) de Anita Malfatti?",
       "Que sensação você associa mais é obra (O Homem Amarelo)?",
       "Qual elemento da pintura (O Homem Amarelo) mais chama a sua atenção?",
       "Em qual movimento artístico você acredita que esta obra se encaixaria melhor",
       "Qual é a sua interpretação pessoal do título (O Homem Amarelo) em relação a obra?",
    };
    char alternativas[5] [4] [100] ={
       { "a) Vibrantes","b) Sombrias",
        "c) Past?is","d) Variadas"},

       {"a) Felicidade","b) Melancolia",
        "c) Surpresa","d) Confus?o"},

       {"a) O rosto do personagem","b) As cores de fundo",
        "c) As texturas","d) Os objetos ao redor do personagem"},

       {"a) Expressionismo","b) Cubismo",
        "c) Impressionismo","d) Surrealismo"},

       {"a) Representa a alegria do personagem","b) Indica uma atmosfera misteriosa",
        "c) Reflete a influ?ncia do artista","d) N?o tenho certeza do significado"},

    };
    for (int i = 0; i <5; i++){
        printf("\n%d. %s\n", i +1, perguntas[i]);
        for (int j = 0; j < 4; j++){
           printf("%s\n",alternativas[i][j]);
        }
        
         char resposta;
        while(1){
            printf("Sua resposta: "); scanf(" %c", &resposta);
            if (resposta == 'a' || resposta == 'b' || resposta == 'c' || resposta == 'd'){
               break;
            }else{
                printf("Opção inválida\n");
            }
            
        }  
    }
    printf("\nObrigado por respoder o questionário!!");
    puts("\nEncerrando...\n"); sleep(3);

}
    return 0;
}