#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

int main(void){
    setlocale(LC_ALL, "portuguese_Brazil");

    
    while (1){

    puts("Inven��o:");
    puts("Inventor: Alberto Santos Dumont");
    puts("Descri��o da Inven��o:");

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

    char perguntas[10][1000] = {
        "Quem foi o inventor do 14-Bis?",
        "Em que ano o 14-Bis fez seu primeiro voo p?blico bem-sucedido?",
        "O 14-Bis � famoso por ser o primeiro avi�o a:",
        "Qual foi a cidade onde Santos Dumont realizou seu voo hist�rico com o 14-Bis?",
        "Qual foi a dist�ncia percorrida pelo 14-Bis em seu primeiro voo p�blico bem-sucedido?",};

    char alternativas[10][4][1000] = {
        {"a) Santos Dumont","b) Leonardo da Vinci","c) Thomas Edison"},
        {"a) 1900","b) 1906"," c) 1920"},
        {"a) Voar a uma velocidade supers�nica","b) Decolar verticalmente",
        "c) Decolar, voar e pousar por seus pr�prios meios"},
        { "a) Paris, Fran�a","b) Rio de Janeiro, Brasil",
        "c) Nova Iorque, EUA"},
        {"a) 60 metros","b) Entre 100 e 200 metros",
        "c) Mais de 1 quil�metro"},};

    char respostas[5];
    int pontuacao = 0; // Vari�vel para rastrear a pontua��o do usu�rio
    char respostas_corretas[5] = {'a', 'b', 'c', 'a', 'a'};
    char resposta;

    for (int i = 0; i < 5; i++) {
    
        printf("\n%d. %s\n", i + 1, perguntas[i]);
        for (int j = 0; j < 4; j++) {
            printf("%s\n", alternativas[i][j]);
        }

        printf("Sua resposta: "); scanf(" %c", &resposta);

        // Converte a resposta do usu�rio e a resposta correta para letras min�sculas
        resposta = tolower(resposta);


        if (resposta == respostas_corretas[i]){
            pontuacao++;
            respostas[i] = resposta;
        }else {
            respostas[i] = 'X'; // Marcar como errada
        }
    }

    // Mostrar a pontua��o final e as perguntas corretas
    printf("\nSua pontua��o final: %d/5\n", pontuacao);
    printf("Perguntas que voc� acertou: ");
    for (int i = 0; i < 5; i++) {
        if (respostas[i] == respostas_corretas[i]) {
            printf("%d ", i + 1);
        }
         
    }
    printf("\nObrigado por respoder o question�rio!!");
    puts("\nEncerrando...\n"); sleep(3);

}
    return 0;
}