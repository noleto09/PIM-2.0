#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

int main(void){
    setlocale(LC_ALL, "portuguese_Brazil");

    
    while (1){

    puts("Invenção:");
    puts("Inventor: Alberto Santos Dumont");
    puts("Descrição da Invenção:");

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
        "Quem foi o inventor do 14-Bis?",
        "Em que ano o 14-Bis fez seu primeiro voo p?blico bem-sucedido?",
        "O 14-Bis é famoso por ser o primeiro avião a:",
        "Qual foi a cidade onde Santos Dumont realizou seu voo histórico com o 14-Bis?",
        "Qual foi a distãncia percorrida pelo 14-Bis em seu primeiro voo público bem-sucedido?",};

    char alternativas[10][4][1000] = {
        {"a) Santos Dumont","b) Leonardo da Vinci","c) Thomas Edison"},
        {"a) 1900","b) 1906"," c) 1920"},
        {"a) Voar a uma velocidade supersónica","b) Decolar verticalmente",
        "c) Decolar, voar e pousar por seus próprios meios"},
        { "a) Paris, França","b) Rio de Janeiro, Brasil",
        "c) Nova Iorque, EUA"},
        {"a) 60 metros","b) Entre 100 e 200 metros",
        "c) Mais de 1 quilómetro"},};

    char respostas[5];
    int pontuacao = 0; // Variável para rastrear a pontuação do usuário
    char respostas_corretas[5] = {'a', 'b', 'c', 'a', 'a'};
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