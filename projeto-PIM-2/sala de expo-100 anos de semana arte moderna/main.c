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
    puts("Descrição da Obra: Abaporu é um símbolo do movimento antropófago e também é um símbolo da arte modernista brasileira como um todo. A obra ainda gera reflexão sobre a identidade nacional, temática tão cara aos modernistas. Ela mostra que, por trás do verde e amarelo, existem também outras cores (influências) na cultura nacional.");

    
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
        "Qual é a sua primeira impressão ao observar a obra ?",
        "Como você interpreta o significado dessa obra? ",
        "Qual elemento da obra Abaporu mais chama a sua atenção?",
        "Qual emoção ou sentimento essa obra desperta em voçê?",
        "Voçê acredita que Abaporu de Tarsila do Amaral é uma obra de arte importante na história da arte brasileira, Por quê?",
    };
    char alternativas[5] [4] [100] ={
        {"a) Alegre e colorida","b) Misteriosa e intrigante",
        "c) Simples e direta","d) Outra" },
        {"a) Uma representa??o da cultura indigena brasileira","b) Uma expressão do nacionalismo artístico","c) Uma crítica social ou política","d) Outra"},
        {"a) As cores vibrantes","b) A figura humana estilizada",
        "c) A paisagem de fundo","d) Outro"},
        {"a) Felicidade","b) Curiosidade",
        "c) Reflexão","d) Outro "},
        {"a) Sim, devido ao seu impacto cultural e histórico","b) Não, porque não entendo o seu valor","c) Não tenho certeza, gostaria de aprender mais sobre ela"},
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