#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

int main(void){
    setlocale(LC_ALL, "portuguese_Brazil");
    while (1){

    puts("Obra: O Artes�o");
    puts("Autor(a): Vicente do Rego Monteiro");
    puts("Descri��o da Obra: Contido nas cores e contrastes, as obras do artista nos reportam a um clima m�stico e metaf�sico. A tem�tica religiosa � frequente em sua pintura, chegando a pintar cenas do Novo Testamento, com figuras que, pela densidade e volume, se aproximam da escultura.");

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
       "Como as cores e contrastes na obra do artista contribuem para criar um clima m�stico e metaf�sico?",
       "Por que a tem�tica religiosa � descrita como frequente nas pinturas do artista?",
       "Como as cenas do Novo Testamento s�o representadas pelo artista em rela��o � densidade e volume das figuras?",
       "Que sensa��o as figuras que se aproximam da escultura podem evocar ao observar as obras do artista?",
       "Como voc� acredita que a abordagem escultural das figuras impacta a interpreta��o das cenas religiosas nas pinturas?",
    };
    char alternativas[5] [4] [100] ={
       {"A) Intensificam a realidade",
     "B) Suavizam a atmosfera",
     "C) Refletem a objetividade",
     "D) Criam uma sensa��o et�rea"},

       { "A) Express�o de cr�ticas sociais",
     "B) Explora��o de mitologia",
     "C) Fasc�nio pela espiritualidade",
     "D) Influ�ncia de movimentos contempor�neos"},

       {"A) Leves e esbo�adas",
     "B) Densas e volumosas",
     "C) Abstratas e simb�licas",
     "D) Monocrom�ticas e est�ticas"},

       {"A) Movimento e dinamismo",
     "B) Frieza e dist�ncia",
     "C) Proximidade e tangibilidade",
     "D) Abstra��o e fluidez"},

       {"A) Torna-as mais acess�veis",
     "B) Adiciona profundidade e solemnidade",
     "C) Desconecta-as da realidade",
     "D) Minimiza a import�ncia religiosa"},

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