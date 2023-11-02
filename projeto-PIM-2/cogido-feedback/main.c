#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <unistd.h>

// Estrutura para armazenar um feedback
struct Feedback {
    char nome[50];
    char opcao[2];
};

int main(void) {
    setlocale(LC_ALL,"portuguese_Brazil");
    
    int continuar = 0;
    while (continuar < 4000){
    
    FILE *arquivo;
    // Abre o arquivo CSV em modo de adição (append)
    arquivo = fopen("feedbacks.csv", "a"); 

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
     long tamanho;
    fseek(arquivo, 0, SEEK_END);
    tamanho = ftell(arquivo);
    fseek(arquivo, 0, SEEK_SET);

    if (tamanho == 0) {
    // Adicionar uma linha de cabeçalho ao arquivo CSV apenas se estiver vazio

    fprintf(arquivo,"Nomes:,Respostas:\n");
    }

    struct Feedback feedback;
    
    printf("\nDigite seu nome: ");
    scanf("%s", feedback.nome);

    printf("\n1. Qual é a sua opinião sobre o evento comemorativo dos 100 anos da Semana de Arte Moderna?\n");
    printf("   a) Adorei! Foi incrível e informativo.\n");
    printf("   b) Foi bom, mas poderia ter sido melhor.\n");
    printf("   c) Não gostei muito, esperava mais.\n");
    printf("   d) Não tive uma boa experiência no evento.\n");
    
    while(1){
    printf("Sua resposta: ");
    scanf("%s", feedback.opcao);
    if (feedback.opcao[0] == 'a' || feedback.opcao[0] == 'b' || feedback.opcao[0] == 'c' || feedback.opcao[0] == 'd'){
        break;
    }else{
        printf("Opção Inválida!!\n");
        printf("Tente novamente");
    }
}

    // Escreve o feedback no arquivo CSV, separando o nome e a opção com uma vírgula
    fprintf(arquivo, "%s,%s\n", feedback.nome, feedback.opcao);

    printf("\nFeedback registrado com sucesso!\n");
    printf("\nEncerrando...\n");
    sleep(3);

    fclose(arquivo);
    }

    return 0;
}
