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
    puts("Descrição da Obra: Pierrete (1922), de Di Cavalcanti.Abordou temas tipicamente brasileiros como, por exemplo, o samba. Em suas obras são comuns também os temas sociais do Brasil, como festas populares, operários, as favelas, protestos sociais");

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
       "Como você interpretaria a expressão lânguida da figura feminina na pintura Pierrete?",
       "Qual é a atmosfera geral que você percebe na obra, considerando a presença da moça, pássaros e elementos poéticos?",
       "O que os pássaros voando em direção à figura feminina podem simbolizar para você?",
       "Como a presença da grade espiralada em primeiro plano afeta a sensação geral da pintura?",
       "Que emoções ou ideias você acredita que Di Cavalcanti quis transmitir por meio da combinação de elementos na pintura Pierrete?",
    };
    char alternativas[5] [4] [100] ={
       {"A) Melancolia",
    "B) Alegria",
    "C) Surpresa",
    "D) Indiferença"},

       {"A) Agitada",
    "B) Sombria",
    "C) Lírica e delicada",
    "D) Atemporal"},

       { "A) Liberdade",
     "B) Perigo",
     "C) Mistério",
     "D) Solidão"},

       {"A) Adiciona complexidade",
     "B) Sugere simplicidade",
     "C) Cria claustrofobia",
     "D) Não tem impacto significativo"},

       {"A) Celebração e leveza",
     "B) Tristeza e isolamento",
     "C) Caos e confusão",
     "D) Serenidade e contemplação"},

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