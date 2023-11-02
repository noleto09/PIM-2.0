#include <stdio.h>
#include <locale.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

int main(void){
    setlocale(LC_ALL, "portuguese_Brazil");
    
    // variaveis
    int escolha;
    char nome[50];
    int tema;
    int quantidade;
    int inteira = 50;
    int meia = 25;
    int inse = 0;
    int bilhete = 1;
    int contador = 0;
    char entrada;
    char dataHoraFormatada[80];
    float soma = 0;
    

    // Arrays de strings para os nomes dos eventos e tipos de entrada
    char eventos[3][50] = {
        "100 anos da semana de arte moderna",
        "150 anos de Santos Dumont",
        "Duas seções"};
    char tiposEntrada[3][15] = {
        "Inteira",
        "Meia Entrada",
        "Isen??o"};

    FILE *arquivo;
    char databusca[50];
    char tipobusca[50];
    char temabusca[50];
    char nomebusca[50];
    int numerobusca;
    int numero;
    int encontrado = 0;
    arquivo = fopen("dados.csv", "a");
    if (arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Inicializei o gerador de números aleatários.
    srand(time(NULL));

    // Gera um número aleatário entre 0 e RAND_MAX
    int numeroaleatorio = rand();

    // Op??es de entrada
    printf("Opções:\n");
    printf("1 - Colaborador\n");
    printf("2 - Visitante\n");
    printf("Escolha uma das opções: ");
    scanf("%d", &escolha);

    if (escolha == 2){

        printf("\nDigite seu nome: ");
        scanf("%s", &nome);

        char texto[1000]; /* Aumentei o tamanho do buffer
       para acomodar a string formatada. */
        // Formate a string com o nome do usu?rio.
        sprintf(texto, "\nOlá tudo bem!! %s, seja bem-vindo ao nosso museu multitemático!\nEste ano celebramos dois marcos incriveis na hist?ria cultural e cientifica do Brasil:\n"
                       "Os 100 anos da Semana de Arte Moderna e os 150 anos de Santos Dumont.\nVenha explorar como esses eventos influenciaram nossa cultura\n"
                       "e tecnologia. Junte-se a nós nesta jornada fascinante!\n#ArteModerna #SantosDumont #CulturaBrasileira\n",
                nome);

        struct timespec atra;
        atra.tv_sec = 0;
        atra.tv_nsec = 30000000; // 30 milhões de nanossegundos (50 ms)

        // Imprime o texto letra por letra com pausa entre cada letra
        for (int i = 0; i < strlen(texto); i++){
            putchar(texto[i]);
            fflush(stdout);
            nanosleep(&atra, NULL);
        }

        // Faz o programa esperar um pouco até ir para próxima interação.
        printf("\nCarregando...\n\n");
        sleep(4);

        // escolhas pra o usuário
        puts("1 - 100 anos da semana de arte moderna");
        puts("2 - 150 anos de Santos Dumont");
        puts("3 - Duas seções\n");

        while (1){

            // pergunta para o usuário
            printf("Qual tema voçê gostaria de visitar? ");
            scanf("%d", &tema);

            // Verifica si o usuário digitou a opções certa
            if (tema == 1 || tema == 2 || tema == 3){
                break;
            }else{
                printf("Opção inválida\n");
                printf("Tente novamente.\n");
            }
        }

        // Pergunta qual o tipo de entrada.
        puts("\na - Inteira R$ 50,00 (valor)");
        puts("b - Meia entrada R$ 25,00 (valor)");
        puts("c - insenção R$ 00,00 (valor)\n");

        while (1){

            printf("Tipo de entrada? ");
            scanf(" %c", &entrada);

            // Verifica si o usuário digitou a opção certa.
            if (entrada == 'a' || entrada == 'b' || entrada == 'c'){
                break;
            }
            else{
                printf("Opção inválida!!\n");
                printf("Tente novamente.\n");
            }
        }

        while (1){

            // pergunta quantos ingressos o usuário deseja.
            printf("\nDigite a quantidade de ingressos? ");
            scanf("%d", &quantidade);
            
            if (quantidade == 0){
                printf("Escolha um valor diferente de (0).");
            }else{
                break;
            }
        }

        
        // Faz a somátoria do ingresso para o usuário.
        if (entrada == 'a'){
            soma = quantidade * inteira;
        }else if (entrada == 'b'){
            soma = quantidade * meia;
        }else if (entrada == 'c'){
            soma = quantidade * inse;
        }else{
            printf("Entrada Inválida");
            return 1;
        }

        // Escreve os dados no arquivo CSV

        printf("\nO valor total a pagar? R$%.2f\n\n", soma);

        printf("\nPreparando o Bilhete...\n");
        sleep(2);

        printf("\nPague no caixa\n\n");
        sleep(3);

        time_t tempoAtual;
        struct tm *infoTempo;
        // char dataHoraFormatada[80];

        time(&tempoAtual);
        infoTempo = localtime(&tempoAtual);

        // Formatar a data e hora
        strftime(dataHoraFormatada, sizeof(dataHoraFormatada), "%d/%m/%Y %H:%M:%S", infoTempo);

        // Ao salvar no arquivo, utilize os arrays para obter o nome do evento e o tipo de entrada correspondentes:
        fprintf(arquivo, "%d,%s,%s,%s,%s,%.2f\n", numeroaleatorio, nome, eventos[tema - 1], tiposEntrada[entrada - 'a'], dataHoraFormatada, soma);

        puts("Bilhete:");
        // Mostrar a data e hora
        printf("Data e Hora Local: %s\n", dataHoraFormatada);

        if (entrada == 'a'){
            printf("Tipo de Ingresso: Inteira ");
        
        }else if (entrada == 'b'){
            printf("Tipo de Ingresso: Meia Entrada");
        }
        
        else if (entrada == 'c'){
            printf("Tipo de Ingresso: Isenção");
        }

        if (tema == 1){
            puts("\nTema: 100 anos da semana de arte moderna");
        }
        
        else if (tema == 2){
            puts("\nTema: 150 anos de Santos Dumont");
        
        }else if (tema == 3){
            puts("\nTema: Duas seções");
        }

        // Armazena os dados do bilhete em uma string
        char num1[2000];
        sprintf(num1, "Número do Bilhete:%d\nNome do visitante: %s\nValor do Ingresso: %.2f\n", numeroaleatorio, nome, soma);

        // Mostra o bilhete ao usu?rio
        printf("%s", num1);

    }else if (escolha == 1){

        // Abre o arquivo no modo de leitura
        arquivo = fopen("dados.csv", "r");
        if (arquivo == NULL){
            printf("Erro ao abrir o arquivo.\n");
            return 1;
        }

        char login[10];
        printf("\nDigite o login: ");
        scanf("%s", login);

        if (strcmp(login, "admin") == 0){
            // Se o login estiver correto o programa deixa ir para parte de validação dos bilhetes.

            while (1){
                printf("\n\nDigite o número que deseja buscar (ou 0 para sair): ");
                scanf("%d", &numerobusca);

                if (numerobusca == 0){
                    break; // Saia do loop se o usuário inserir 0
                }

                encontrado = 0; // Redefina a flag para cada nova busca

                // Lé o arquivo linha por linha e verifica se o n?mero corresponde
                while (fscanf(arquivo, "%d,%49[^,],%49[^,],%49[^,],%49[^,],%f,", &numero, nomebusca, temabusca, tipobusca, dataHoraFormatada, &soma) != EOF){
                    
                    if (numero == numerobusca){
                        encontrado = 1;
                        printf("\nN?mero do Bilhete: %d\nNome: %s\nTema: %s\nTipo de Ingresso: %s\nData e Hora: %s\nValor do Ingresso: R$%.2f \n", numero, nomebusca, temabusca, tipobusca, dataHoraFormatada, soma);
                        break;
                    }
                
                }if (!encontrado){
                    printf("N?mero n?o encontrado no arquivo CSV.\n");
                }

                rewind(arquivo); // Volta ao início do arquivo para a pr?xima busca
            }

            // Fecha o arquivo
            fclose(arquivo);
        }

    }

    return 0;
}