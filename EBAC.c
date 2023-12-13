#include <stdio.h>    // Biblioteca padr�o de entrada/sa�da
#include <stdlib.h>   // Biblioteca padr�o que inclui fun��es envolvendo aloca��o de mem�ria, controle de processos, etc.
#include <locale.h>   // Biblioteca para configura��o de localidade (necess�ria para caracteres especiais em portugu�s)
#include <string.h>   // Biblioteca das strings

int registro() // Fun��o para o menu de registro de nomes
{
    setlocale(LC_ALL, "Portuguese");  // Configura a localidade para aceitar caracteres especiais

    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);

    strcpy(arquivo, cpf); // Copia o valor das strings

    FILE *file; // Cria o arquivo
    file = fopen(arquivo, "w"); // Cria o arquivo, "w" de write
    fprintf(file, cpf); // Salva o valor da vari�vel
    fclose(file); // Fecha o arquivo

    file = fopen(arquivo, "a"); // 'a' para atualizar o arquivo
    fprintf(file, "\nNome do usu�rio: ");
    fclose(file);

    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);

    file = fopen(arquivo, "a"); // Usa o "a" pois n�o � um novo arquivo, j� que ele j� est� criado. Precisamos apenas de atualizar (adicionando o nome)
    fprintf(file, nome); // Salvando a vari�vel "nome" no arquivo
    fclose(file);

    file = fopen(arquivo, "a"); // 'a' para atualizar o arquivo
    fprintf(file, "\nSobrenome do usu�rio: ");
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);

    file = fopen(arquivo, "a"); // 'a' para atualizar o arquivo
    fprintf(file, "\nCargo do usu�rio: ");
    fclose(file);

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);

    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);

    system("pause");
}

int consulta() // Fun��o para o menu de consulta de nomes
{
    setlocale(LC_ALL, "Portuguese");  // Configura a localidade para aceitar caracteres especiais

    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    printf("CPF do usu�rio: ");

    FILE *file;
    file = fopen(cpf, "r"); // "r" de ready

    if (file == NULL)
    {
        printf("Usu�rio n�o encontrado\n");
    }

    while (fgets(conteudo, 200, file) != NULL)
    {
        printf("%s", conteudo);
        printf("\n");
    }
    system("pause");
}

int deletar() // Fun��o para o menu de deletar nomes
{
    char cpf[40];

    printf("Digite o CPF a ser deletado: ");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if (file == NULL) // verifica se o arquivo n�o foi encontrado (CPF n�o existe)
    {
        printf("Usu�rio n�o encontrado, volte ao menu.\n");
        system("pause");
    }
    else
    {
        fclose(file); // Fecha o arquivo antes de remover

        if (remove(cpf) == 0) // tenta remover o arquivo correspondente ao CPF
        {
            printf("Os dados do usu�rio foram deletados.\n");
            system("pause");
        }
        else
        {
            perror("Erro ao deletar os dados do usu�rio");
            system("pause");
        }
    }
}




int erro() // Fun��o para lidar com op��es inv�lidas
{
    printf("A op��o escolhida est� indispon�vel\n");
    system("pause");
}

int main()
{
    int opcao = 0;
    int x = 1;

    while (x == 1) // Loop principal
    {
        setlocale(LC_ALL, "Portuguese");  // Configura a localidade para aceitar caracteres especiais

        // Exibi��o do menu principal
        printf("###Cart�rio da EBAC###\n\n");
        printf("\t\t\t\t\t\t\t\t\t\tESCOLHA A OP��O DESEJADA DO MENU\n");
        printf("1 - Registrar nomes");
        printf("\t\t\t\t\t\t\t\t2 - Consultar nomes");
        printf("\t\t\t\t\t\t\t\t\t3 - Deletar nomes\n");
        printf("\n\n\n\nEste Software foi criado por Ryan Vasconcelos para uso privado");
        printf("\nAperte 'F11' para melhor usabilidade.");
		printf("\nOp��o:");

        scanf("%d", &opcao); // Leitura da op��o escolhida pelo usu�rio

        system("cls"); // Limpa a tela do console

        switch (opcao) // Switch para lidar com as op��es escolhidas
        {
        case 1:
            // Chama a fun��o de registro
            registro();
            break;

        case 2:
            // Chama a fun��o de consulta
            consulta();
            break;

        case 3:
            // Chama a fun��o de deletar
            deletar();
            break;

        default:
            // Chama a fun��o de erro para op��es inv�lidas
            erro();
            break;
        }

        // Limpa a tela do console para a pr�xima itera��o
        system("cls");
    }
    return 0;
}
