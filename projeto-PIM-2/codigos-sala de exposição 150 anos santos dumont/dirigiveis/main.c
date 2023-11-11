#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

int main(void){
    setlocale(LC_ALL, "portuguese_Brazil");

    
    while (1){

    puts("Invenção: Balão dirigível nº 2");
    puts("Inventor: Alberto Santos Dumont");
    puts("Descrição da Invenção: Na Quinta-Feira 11 de maio de 1899 aconteceu a primeira experiência de Santos Dumont com o seu balão dirigível nº 2. Tal aeróstato era flexível, com 25 metros de comprimento e 3,8 metros de diâmetro. Esse fato teve como cenário o Jardim da Aclimação, em Paris.");

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
        "O que Santos Dumont experimentou em 11 de maio de 1899?",
        "Qual era o cenário da primeira experiência de Santos Dumont com o balão dirigível nº 2?",
        "Qual foi a principal razão para a breve duração da experiência de Santos Dumont?",
        "Durante o voo teste, o que Santos Dumont fez sobre Paris?",
        "Como Santos Dumont resolveu um pequeno acidente durante a tentativa de descer?",};

    char alternativas[10][4][1000] = {
        {  "a) Avião","b) Balão dirigível nº 2",
        "c) Helicóptero","d) Foguete"},
        {"a) Jardim Botânico","b) Jardim da Aclimação, Paris",
        "c) Praia de Copacabana","d) Parque Nacional"},
        {"a) Combustível insuficiente""b) Colisão com aves"
        "c) Choque contra árvores devido à chuva e temperatura fria"
        "d) Falha mecânica"},
        {"a) Correu no chão","b) Voou contra os pássaros",
        "c) Voou sobre a cidade","d) Fez acrobacias aéreas"},
        {"a) Usou um paraquedas","b) Pediu ajuda a adultos presentes",
        "c) Transformou o cabo do balão em uma pipa com a ajuda de crianças",
        "d) Aguardou o resgate por terra"},};

    char respostas[5];
    int pontuacao = 0; // Variável para rastrear a pontuação do usuário
    char respostas_corretas[5] = {'b', 'b', 'c', 'c', 'c'};
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