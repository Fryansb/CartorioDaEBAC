#include <stdio.h>    // Biblioteca padrão de entrada/saída
#include <stdlib.h>   // Biblioteca padrão que inclui funções envolvendo alocação de memória, controle de processos, etc.
#include <locale.h>   // Biblioteca para configuração de localidade (necessária para caracteres especiais em português)
#include <string.h>   // Biblioteca das strings

int registro() // Função para o menu de registro de nomes
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
    fprintf(file, cpf); // Salva o valor da variável
    fclose(file); // Fecha o arquivo

    file = fopen(arquivo, "a"); // 'a' para atualizar o arquivo
    fprintf(file, "\nNome do usuário: ");
    fclose(file);

    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);

    file = fopen(arquivo, "a"); // Usa o "a" pois não é um novo arquivo, já que ele já está criado. Precisamos apenas de atualizar (adicionando o nome)
    fprintf(file, nome); // Salvando a variável "nome" no arquivo
    fclose(file);

    file = fopen(arquivo, "a"); // 'a' para atualizar o arquivo
    fprintf(file, "\nSobrenome do usuário: ");
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);

    file = fopen(arquivo, "a"); // 'a' para atualizar o arquivo
    fprintf(file, "\nCargo do usuário: ");
    fclose(file);

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);

    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);

    system("pause");
}

int consulta() // Função para o menu de consulta de nomes
{
    setlocale(LC_ALL, "Portuguese");  // Configura a localidade para aceitar caracteres especiais

    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    printf("CPF do usuário: ");

    FILE *file;
    file = fopen(cpf, "r"); // "r" de ready

    if (file == NULL)
    {
        printf("Usuário não encontrado\n");
    }

    while (fgets(conteudo, 200, file) != NULL)
    {
        printf("%s", conteudo);
        printf("\n");
    }
    system("pause");
}

int deletar() // Função para o menu de deletar nomes
{
    char cpf[40];

    printf("Digite o CPF a ser deletado: ");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if (file == NULL) // verifica se o arquivo não foi encontrado (CPF não existe)
    {
        printf("Usuário não encontrado, volte ao menu.\n");
        system("pause");
    }
    else
    {
        fclose(file); // Fecha o arquivo antes de remover

        if (remove(cpf) == 0) // tenta remover o arquivo correspondente ao CPF
        {
            printf("Os dados do usuário foram deletados.\n");
            system("pause");
        }
        else
        {
            perror("Erro ao deletar os dados do usuário");
            system("pause");
        }
    }
}




int erro() // Função para lidar com opções inválidas
{
    printf("A opção escolhida está indisponível\n");
    system("pause");
}

int main()
{
    int opcao = 0;
    int x = 1;

    while (x == 1) // Loop principal
    {
        setlocale(LC_ALL, "Portuguese");  // Configura a localidade para aceitar caracteres especiais

        // Exibição do menu principal
        printf("###Cartório da EBAC###\n\n");
        printf("\t\t\t\t\t\t\t\t\t\tESCOLHA A OPÇÃO DESEJADA DO MENU\n");
        printf("1 - Registrar nomes");
        printf("\t\t\t\t\t\t\t\t2 - Consultar nomes");
        printf("\t\t\t\t\t\t\t\t\t3 - Deletar nomes\n");
        printf("\n\n\n\nEste Software foi criado por Ryan Vasconcelos para uso privado");
        printf("\nAperte 'F11' para melhor usabilidade.");
		printf("\nOpção:");

        scanf("%d", &opcao); // Leitura da opção escolhida pelo usuário

        system("cls"); // Limpa a tela do console

        switch (opcao) // Switch para lidar com as opções escolhidas
        {
        case 1:
            // Chama a função de registro
            registro();
            break;

        case 2:
            // Chama a função de consulta
            consulta();
            break;

        case 3:
            // Chama a função de deletar
            deletar();
            break;

        default:
            // Chama a função de erro para opções inválidas
            erro();
            break;
        }

        // Limpa a tela do console para a próxima iteração
        system("cls");
    }
    return 0;
}
