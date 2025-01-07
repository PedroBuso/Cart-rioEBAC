#include <stdio.h> //biblioteca de comunicação com o usuário.
#include <stdlib.h> //biblioteca de alocação de espaço em memória.
#include <locale.h> //biblioteca de texto por região.
#include <string.h> //biblioteca responsável por cuidar das strings.

int registro() // Função responsável por cadastrar o usuário no sistema.
{
    setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem.

    char arquivo[40]; // Início da criação das variáveis.
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40]; // Fim da criação das variáveis

    printf("Digite o cpf a ser cadastrado: "); // Coletando informação do usuário.
    scanf("%s", cpf); //%s refere-se a string.

    strcpy(arquivo, cpf); // Responsável por copiar os valores das stings.

    FILE *file;
    file = fopen(arquivo, "w"); //Cria o arquivo - "w" = escrever
    fprintf(file,cpf); //Salva o valor da variável.
    fclose(file); //Fecha o arquivo.

    file = fopen(arquivo, "a"); // abre o arquivo - "a" = atualizar
    fprintf(file, ", "); // escreve no arquivo.
    fclose(file); // fecha o arquivo.

    file = fopen(arquivo, "a"); // abre o arquivo - "a" = atualizar
    fprintf(file, "NOME: "); // escreve no arquivo.
    fclose(file); // fecha o arquivo.

    printf("Digite o nome a ser cadastrado: "); // Coletando informação do usuário.
    scanf("%s", nome); //%s refere-se a string.

    file = fopen(arquivo, "a"); // abre o arquivo - "a" = atualizar
    fprintf(file, nome); //Salva o valor da variável.
    fclose(file); // fecha o arquivo.

    file = fopen(arquivo, "a"); // abre o arquivo - "a" = atualizar
    fprintf(file, ", "); // escreve no arquivo.
    fclose(file); // fecha o arquivo.

    file = fopen(arquivo, "a"); // abre o arquivo - "a" = atualizar
    fprintf(file, "SOBRENOME: "); // escreve no arquivo.
    fclose(file); // fecha o arquivo.

    printf("Digite o sobrenome a ser cadastrado: "); // Coletando informação do usuário.
    scanf("%s", sobrenome); //%s refere-se a string.

    file = fopen(arquivo, "a"); // abre o arquivo - "a" = atualizar
    fprintf(file, sobrenome); //Salva o valor da variável.
    fclose(file); // fecha o arquivo.

    file = fopen(arquivo, "a"); // abre o arquivo - "a" = atualizar
    fprintf(file, ", "); // escreve no arquivo.
    fclose(file); // fecha o arquivo.

    file = fopen(arquivo, "a"); // abre o arquivo - "a" = atualizar
    fprintf(file, "CARGO: "); // escreve no arquivo.
    fclose(file); // fecha o arquivo.

    printf("Digite o cargo a ser cadastrado: "); // Coletando informação do usuário.
    scanf("%s", cargo); //%s refere-se a string.

    file = fopen(arquivo, "a"); // abre o arquivo - "a" = atualizar
    fprintf(file, cargo); //Salva o valor da variável.
    fclose(file); // fecha o arquivo.

    system("read -p \"Pressione Enter para continuar...\""); //Finaliza o programa indicando sem alteração.
 
}

int consulta() //Função responsável por consultar os registros.
{
    setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem 

    char cpf[40]; // Início da criação das variáveis.
    char conteudo[200]; // Fim da criação das variáveis.

    printf("Digite o cpf a ser consultado: ");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if(file == NULL)
    {
        printf("Não localizado!.\n");
        system("read -p \"Pressione Enter para continuar...\"");
        return 0;
    }

    while(fgets(conteudo, 200, file) != NULL);
    {
        printf("\nEssas são as informações do usuário: CPF: ");
        printf("%s", conteudo);
    }
    printf("\n\n");
    fclose(file);

    system("read -p \"Pressione Enter para continuar...\"");
}

int deletar()
{
    setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem 

    char cpf[40];

    printf("Digite o CPF do usuário a ser deletado: ");
    scanf("%s", cpf);

    remove(cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if(file == NULL)
    {
        printf("Usuário não encontrado!.\n");
        system("read -p \"Pressione Enter para continuar...\"");
    }


}


int main()
{
    int opcao=0; // Definindo variáveis
    int laco=1;

    for(laco=1;laco==1;)
    {

       system("clear");

       setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem

       printf("### Cartório da EBAC ###\n\n"); // Início do menu
       printf("Escolha uma das opções no menu:\n\n");
       printf("\t1 - Registrar Nomes\n");
       printf("\t2 - Consultar Nomes\n");
       printf("\t3 - Deletar Nomes\n\n");
       printf("\t4 - Sair do Programa.\n\n");
       printf("Opção ");  // Fim do menu

       scanf( "%d", &opcao); //Armazenando a opcao do usuário

       system("clear");

       switch(opcao)
       {
          case 1:
          registro();
          break;

          case 2:
          consulta();
          break;

          case 3:
          deletar();
          break;

          case 4:
          printf("Obrigado por utilizar o sistema.\n");
          return 0;
          break;

          default:
          printf("Opção não disponível!\n");
          system("read -p \"Pressione Enter para continuar...\"");
          break;
        }// Fim da seleção
    }
}