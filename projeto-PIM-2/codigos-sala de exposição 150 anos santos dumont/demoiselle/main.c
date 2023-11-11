#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

int main(void){
    setlocale(LC_ALL, "portuguese_Brazil");

    
    while (1){

    puts("Invenção: Demoiselle");
    puts("Inventor: Alberto Santos Dumont");
    puts("Descrição da Invenção: A Demoiselle foi o melhor modelo criado por Alberto Santos-Dumont. Primeiro ultraleve da história da aviação, ela surgiu como o número 19 do aviador e foi depois aperfeiçoada no número 20. Feita de bambu e coberta com seda envernizada, voava com um motor de 25-30 cv e pesava apenas 115 quilos.");

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

    char perguntas[10][1000] = {
        "Qual foi considerado o melhor modelo criado por Alberto Santos-Dumont por especialistas?",
        "O que tornou a Demoiselle a última criação do aviador?",
        "Qual era o material principal usado na construção da Demoiselle?",
        "Segundo Marcos Villares Filho, por que a Demoiselle foi considerada a obra-prima de Santos-Dumont?",
        "De acordo com o inventor, por que a Demoiselle recebeu o nome de Libelulle ou Demoiselle?",};

    char alternativas[10][4][1000] = {
        {"a) 14-Bisb)", "Demoiselle",
        "c) Número 19", "d) Número 20"},
        
        { "a) Maior tamanho","b) Motor mais potente",
        "c) Feita de materiais modernos","d) Número de série 20"},
        
        {  "a) Metal","b) Bambu",
        "c) Madeira","d) Plástico"},
        
        {"a) Por ser o maior avião da época","b) Por ser a mais cara",
        "c) Por ser a menor e mais barata possível",
        "d) Por ter características militares avançadas"},
        
        {"a) Por ser uma homenagem a um amigo","b) Por sua superfície de asas",
        "c) Por ser transparente e pequenina","d) Por seu motor potente"},};

    char respostas[5];
    int pontuacao = 0; // Variável para rastrear a pontuação do usuário
    char respostas_corretas[5] = {'b', 'd', 'b', 'c', 'c'};
    char resposta;

    for (int i = 0; i < 5; i++) {
    
        printf("\n%d. %s\n", i + 1, perguntas[i]);
        for (int j = 0; j < 4; j++) {
            printf("%s\n", alternativas[i][j]);
        }

        printf("Sua resposta: "); scanf(" %c", &resposta);

        // Converte a resposta do usuário e a resposta correta para letras minúsculas
        resposta = tolower(resposta);


        if (resposta == respostas_corretas[i]){
            pontuacao++;
            respostas[i] = resposta;
        }else {
            respostas[i] = 'X'; // Marcar como errada
        }
    }

    // Mostrar a pontuação final e as perguntas corretas
    printf("\nSua pontuação final: %d/5\n", pontuacao);
    printf("Perguntas que você acertou: ");
    for (int i = 0; i < 5; i++) {
        if (respostas[i] == respostas_corretas[i]) {
            printf("%d ", i + 1);
        }
         
    }
    printf("\nObrigado por respoder o questionário!!");
    puts("\nEncerrando...\n"); sleep(3);

}
    return 0;
}