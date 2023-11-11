#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

int main(void){
    setlocale(LC_ALL, "portuguese_Brazil");

    
    while (1){

    puts("Inven��o: Demoiselle");
    puts("Inventor: Alberto Santos Dumont");
    puts("Descri��o da Inven��o: A Demoiselle foi o melhor modelo criado por Alberto Santos-Dumont. Primeiro ultraleve da hist�ria da avia��o, ela surgiu como o n�mero 19 do aviador e foi depois aperfei�oada no n�mero 20. Feita de bambu e coberta com seda envernizada, voava com um motor de 25-30 cv e pesava apenas 115 quilos.");

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
        "Qual foi considerado o melhor modelo criado por Alberto Santos-Dumont por especialistas?",
        "O que tornou a Demoiselle a �ltima cria��o do aviador?",
        "Qual era o material principal usado na constru��o da Demoiselle?",
        "Segundo Marcos Villares Filho, por que a Demoiselle foi considerada a obra-prima de Santos-Dumont?",
        "De acordo com o inventor, por que a Demoiselle recebeu o nome de Libelulle ou Demoiselle?",};

    char alternativas[10][4][1000] = {
        {"a) 14-Bisb)", "Demoiselle",
        "c) N�mero 19", "d) N�mero 20"},
        
        { "a) Maior tamanho","b) Motor mais potente",
        "c) Feita de materiais modernos","d) N�mero de s�rie 20"},
        
        {  "a) Metal","b) Bambu",
        "c) Madeira","d) Pl�stico"},
        
        {"a) Por ser o maior avi�o da �poca","b) Por ser a mais cara",
        "c) Por ser a menor e mais barata poss�vel",
        "d) Por ter caracter�sticas militares avan�adas"},
        
        {"a) Por ser uma homenagem a um amigo","b) Por sua superf�cie de asas",
        "c) Por ser transparente e pequenina","d) Por seu motor potente"},};

    char respostas[5];
    int pontuacao = 0; // Vari�vel para rastrear a pontua��o do usu�rio
    char respostas_corretas[5] = {'b', 'd', 'b', 'c', 'c'};
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