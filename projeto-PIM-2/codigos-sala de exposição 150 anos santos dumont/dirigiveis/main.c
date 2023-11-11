#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

int main(void){
    setlocale(LC_ALL, "portuguese_Brazil");

    
    while (1){

    puts("Inven��o: Bal�o dirig�vel n� 2");
    puts("Inventor: Alberto Santos Dumont");
    puts("Descri��o da Inven��o: Na Quinta-Feira 11 de maio de 1899 aconteceu a primeira experi�ncia de Santos Dumont com o seu bal�o dirig�vel n� 2. Tal aer�stato era flex�vel, com 25 metros de comprimento e 3,8 metros de di�metro. Esse fato teve como cen�rio o Jardim da Aclima��o, em Paris.");

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
        "O que Santos Dumont experimentou em 11 de maio de 1899?",
        "Qual era o cen�rio da primeira experi�ncia de Santos Dumont com o bal�o dirig�vel n� 2?",
        "Qual foi a principal raz�o para a breve dura��o da experi�ncia de Santos Dumont?",
        "Durante o voo teste, o que Santos Dumont fez sobre Paris?",
        "Como Santos Dumont resolveu um pequeno acidente durante a tentativa de descer?",};

    char alternativas[10][4][1000] = {
        {  "a) Avi�o","b) Bal�o dirig�vel n� 2",
        "c) Helic�ptero","d) Foguete"},
        {"a) Jardim Bot�nico","b) Jardim da Aclima��o, Paris",
        "c) Praia de Copacabana","d) Parque Nacional"},
        {"a) Combust�vel insuficiente""b) Colis�o com aves"
        "c) Choque contra �rvores devido � chuva e temperatura fria"
        "d) Falha mec�nica"},
        {"a) Correu no ch�o","b) Voou contra os p�ssaros",
        "c) Voou sobre a cidade","d) Fez acrobacias a�reas"},
        {"a) Usou um paraquedas","b) Pediu ajuda a adultos presentes",
        "c) Transformou o cabo do bal�o em uma pipa com a ajuda de crian�as",
        "d) Aguardou o resgate por terra"},};

    char respostas[5];
    int pontuacao = 0; // Vari�vel para rastrear a pontua��o do usu�rio
    char respostas_corretas[5] = {'b', 'b', 'c', 'c', 'c'};
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