#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

int main(void){
    setlocale(LC_ALL, "portuguese_Brazil");
    
    while (1){

    puts("Obra: Abaporu");
    puts("Autor(a): Tarsila do Amaral");
    puts("Descri��o da Obra: Abaporu � um s�mbolo do movimento antrop�fago e tamb�m � um s�mbolo da arte modernista brasileira como um todo. A obra ainda gera reflex�o sobre a identidade nacional, tem�tica t�o cara aos modernistas. Ela mostra que, por tr�s do verde e amarelo, existem tamb�m outras cores (influ�ncias) na cultura nacional.");

    
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
        "Qual � a sua primeira impress�o ao observar a obra ?",
        "Como voc� interpreta o significado dessa obra? ",
        "Qual elemento da obra Abaporu mais chama a sua aten��o?",
        "Qual emo��o ou sentimento essa obra desperta em vo��?",
        "Vo�� acredita que Abaporu de Tarsila do Amaral � uma obra de arte importante na hist�ria da arte brasileira, Por qu�?",
    };
    char alternativas[5] [4] [100] ={
        {"a) Alegre e colorida","b) Misteriosa e intrigante",
        "c) Simples e direta","d) Outra" },
        {"a) Uma representa??o da cultura indigena brasileira","b) Uma express�o do nacionalismo art�stico","c) Uma cr�tica social ou pol�tica","d) Outra"},
        {"a) As cores vibrantes","b) A figura humana estilizada",
        "c) A paisagem de fundo","d) Outro"},
        {"a) Felicidade","b) Curiosidade",
        "c) Reflex�o","d) Outro "},
        {"a) Sim, devido ao seu impacto cultural e hist�rico","b) N�o, porque n�o entendo o seu valor","c) N�o tenho certeza, gostaria de aprender mais sobre ela"},
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