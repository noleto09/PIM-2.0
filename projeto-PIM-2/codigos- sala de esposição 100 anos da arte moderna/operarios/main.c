#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

int main(void){
    setlocale(LC_ALL, "portuguese_Brazil");
    while (1){

    puts("Obra: Oper�rios");
    puts("Autor(a): Tarsila do Amaral");
    puts("Descri��o da Obra: Oper�rios, que mostra ao fundo uma f�brica e em primeiro plano um aglomerado de trabalhadores com express�o facial neutra, retrata o per�odo em que teve in�cio a industrializa��o brasileira, em especial a paulistana, com o surgimento da classe oper�ria");

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
       "Qual foi a influ�ncia da experi�ncia de Tarsila do Amaral na Uni�o Sovi�tica na obra Oper�rios?",
       "Como a perda do patrim�nio de Tarsila do Amaral durante a Grande Depress�o pode ter influenciado a tem�tica de Oper�rios",
       "O que a presen�a de uma f�brica ao fundo na pintura sugere sobre o contexto hist�rico da industrializa��o brasileira?",
       "Como voc� acredita que a pintura Oper�rios reflete a transi��o do cen�rio rural para o urbano durante a industrializa��o paulistana?",
    };
    char alternativas[5] [4] [100] ={
       {"A) Reflete elementos surrealistas",
     "B) Destaca aspectos da natureza brasileira",
     "C) Aborda quest�es sociais e pol�ticas",
     "D) Explora temas religiosos"},

       {"A) Express�o de desespero e tristeza",
     "B) Retrato de esperan�a e renova��o",
     "C) Cr�tica � sociedade de consumo",
     "D) Foco em elementos abstratos"},

       {"A) Celebra��o do progresso",
     "B) Cr�tica ao impacto ambiental",
     "C) Representa��o do surgimento da classe oper�ria",
     "D) Abstra��o da realidade urbana"},

       {"A) Elogia a vida rural",
     "B) Lamenta a perda das tradi��es",
     "C) Celebra a modernidade",
     "D) Questiona os efeitos da urbaniza��o"},


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