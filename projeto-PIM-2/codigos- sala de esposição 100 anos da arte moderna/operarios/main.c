#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

int main(void){
    setlocale(LC_ALL, "portuguese_Brazil");
    while (1){

    puts("Obra: Operários");
    puts("Autor(a): Tarsila do Amaral");
    puts("Descrição da Obra: Operários, que mostra ao fundo uma fábrica e em primeiro plano um aglomerado de trabalhadores com expressão facial neutra, retrata o período em que teve início a industrialização brasileira, em especial a paulistana, com o surgimento da classe operária");

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
       "Qual foi a influência da experiência de Tarsila do Amaral na União Soviética na obra Operários?",
       "Como a perda do patrimônio de Tarsila do Amaral durante a Grande Depressão pode ter influenciado a temática de Operários",
       "O que a presença de uma fábrica ao fundo na pintura sugere sobre o contexto histórico da industrialização brasileira?",
       "Como você acredita que a pintura Operários reflete a transição do cenário rural para o urbano durante a industrialização paulistana?",
    };
    char alternativas[5] [4] [100] ={
       {"A) Reflete elementos surrealistas",
     "B) Destaca aspectos da natureza brasileira",
     "C) Aborda questões sociais e políticas",
     "D) Explora temas religiosos"},

       {"A) Expressão de desespero e tristeza",
     "B) Retrato de esperança e renovação",
     "C) Crítica à sociedade de consumo",
     "D) Foco em elementos abstratos"},

       {"A) Celebração do progresso",
     "B) Crítica ao impacto ambiental",
     "C) Representação do surgimento da classe operária",
     "D) Abstração da realidade urbana"},

       {"A) Elogia a vida rural",
     "B) Lamenta a perda das tradições",
     "C) Celebra a modernidade",
     "D) Questiona os efeitos da urbanização"},


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