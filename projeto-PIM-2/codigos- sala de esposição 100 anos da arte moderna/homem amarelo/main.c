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
    puts("Descri��o da Obra: O Homem amarelo representa um imigrante italiano pobre"); puts("que posou para a artista Anita Malfatti na �poca em que ela estudava no");puts("exterior, a artista comenta que o modelo sustentava 'um olhar desesperado' naquele dia.");

    while(1){
        char escolha;
    puts("\n1-Sim (S)");
    printf("Deseja responder um breve question�rio (S)? ");
    scanf("%s", &escolha);
    escolha = tolower(escolha);

    if (escolha == 's'){
        break;
    }else{
        printf("\nOp��o inv�lida\n");
    }
    }

    char perguntas[5][1000] = {
       " Qual palavra melhor descreve as cores predominantes na obra (O Homem Amarelo) de Anita Malfatti?",
       "Que sensa��o voc� associa mais � obra (O Homem Amarelo)?",
       "Qual elemento da pintura (O Homem Amarelo) mais chama a sua aten��o?",
       "Em qual movimento art�stico voc� acredita que esta obra se encaixaria melhor",
       "Qual � a sua interpreta��o pessoal do t�tulo (O Homem Amarelo) em rela��o a obra?",
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
                printf("Op��o inv�lida\n");
            }
            
        }  
    }
    printf("\nObrigado por respoder o question�rio!!");
    puts("\nEncerrando...\n"); sleep(3);

}
    return 0;
}