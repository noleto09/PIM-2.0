#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

int main(void){
    setlocale(LC_ALL, "portuguese_Brazil");
    while (1){

    puts("Obra: Pierrete");
    puts("Autor(a): Di cavalcanti");
    puts("Descri��o da Obra: Pierrete (1922), de Di Cavalcanti.Abordou temas tipicamente brasileiros como, por exemplo, o samba. Em suas obras s�o comuns tamb�m os temas sociais do Brasil, como festas populares, oper�rios, as favelas, protestos sociais");

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
       "Como voc� interpretaria a express�o l�nguida da figura feminina na pintura Pierrete?",
       "Qual � a atmosfera geral que voc� percebe na obra, considerando a presen�a da mo�a, p�ssaros e elementos po�ticos?",
       "O que os p�ssaros voando em dire��o � figura feminina podem simbolizar para voc�?",
       "Como a presen�a da grade espiralada em primeiro plano afeta a sensa��o geral da pintura?",
       "Que emo��es ou ideias voc� acredita que Di Cavalcanti quis transmitir por meio da combina��o de elementos na pintura Pierrete?",
    };
    char alternativas[5] [4] [100] ={
       {"A) Melancolia",
    "B) Alegria",
    "C) Surpresa",
    "D) Indiferen�a"},

       {"A) Agitada",
    "B) Sombria",
    "C) L�rica e delicada",
    "D) Atemporal"},

       { "A) Liberdade",
     "B) Perigo",
     "C) Mist�rio",
     "D) Solid�o"},

       {"A) Adiciona complexidade",
     "B) Sugere simplicidade",
     "C) Cria claustrofobia",
     "D) N�o tem impacto significativo"},

       {"A) Celebra��o e leveza",
     "B) Tristeza e isolamento",
     "C) Caos e confus�o",
     "D) Serenidade e contempla��o"},

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