#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

int main(void){
    setlocale(LC_ALL, "portuguese_Brazil");
    while (1){

    puts("Obra: O Artesão");
    puts("Autor(a): Vicente do Rego Monteiro");
    puts("Descrição da Obra: Contido nas cores e contrastes, as obras do artista nos reportam a um clima místico e metafísico. A temática religiosa é frequente em sua pintura, chegando a pintar cenas do Novo Testamento, com figuras que, pela densidade e volume, se aproximam da escultura.");

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
       "Como as cores e contrastes na obra do artista contribuem para criar um clima místico e metafísico?",
       "Por que a temática religiosa é descrita como frequente nas pinturas do artista?",
       "Como as cenas do Novo Testamento são representadas pelo artista em relação à densidade e volume das figuras?",
       "Que sensação as figuras que se aproximam da escultura podem evocar ao observar as obras do artista?",
       "Como você acredita que a abordagem escultural das figuras impacta a interpretação das cenas religiosas nas pinturas?",
    };
    char alternativas[5] [4] [100] ={
       {"A) Intensificam a realidade",
     "B) Suavizam a atmosfera",
     "C) Refletem a objetividade",
     "D) Criam uma sensação etérea"},

       { "A) Expressão de críticas sociais",
     "B) Exploração de mitologia",
     "C) Fascínio pela espiritualidade",
     "D) Influência de movimentos contemporâneos"},

       {"A) Leves e esboçadas",
     "B) Densas e volumosas",
     "C) Abstratas e simbólicas",
     "D) Monocromáticas e estáticas"},

       {"A) Movimento e dinamismo",
     "B) Frieza e distância",
     "C) Proximidade e tangibilidade",
     "D) Abstração e fluidez"},

       {"A) Torna-as mais acessíveis",
     "B) Adiciona profundidade e solemnidade",
     "C) Desconecta-as da realidade",
     "D) Minimiza a importância religiosa"},

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