#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int registro() {
    setlocale(LC_ALL, "Portuguese");

    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);

    strcpy(arquivo, cpf);

    FILE *file;
    file = fopen(arquivo, "w");
    fprintf(file, cpf);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, "\nNome do usu�rio: ");
    fclose(file);

    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);

    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, "\nSobrenome do usu�rio: ");
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, "\nCargo do usu�rio: ");
    fclose(file);

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);

    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);

    system("pause");
}

int consulta() {
    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    printf("CPF do usu�rio: ");

    FILE *file;
    file = fopen(cpf, "r");

    if (file == NULL) {
        printf("Usu�rio n�o encontrado\n");
    }

    while (fgets(conteudo, 200, file) != NULL) {
        printf("%s", conteudo);
        printf("\n");
    }
    fclose(file);
    system("pause");
    return 0;
}

int deletar() {
    char cpf[40];

    printf("Digite o CPF a ser deletado: ");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if (file == NULL) {
        printf("Usu�rio n�o encontrado, volte ao menu.\n");
        system("pause");
    } else {
        fclose(file);
        int erro = remove(cpf);

        if (erro == -1) {
            printf("Erro ao deletar os dados do usu�rio");
            system("pause");
        } else {
            printf("Os dados do usu�rio foram deletados.\n");
            system("pause");
        }
    }
}

int erro() {
    printf("A op��o escolhida est� indispon�vel\n");
    system("pause");
}

int main() {
    int opcao = 0;
    int x = 1;
    char senhadigitada[10]="a";
    
    printf("###Cart�rio da EBAC###\n\n");
    printf("Login de administrador!\n\nDigite a senha:");
    scanf("%s", senhadigitada);
    
    if(strcmp(senhadigitada, "admin") == 0) {
        
		system("cls");
		while (x == 1) {
            setlocale(LC_ALL, "Portuguese");
    
            printf("###Cart�rio da EBAC###\n\n");
            printf("\t\t\t\t\t\t\t\t\t\tESCOLHA A OP��O DESEJADA DO MENU\n");
            printf("1 - Registrar nomes");
            printf("\t\t\t\t2 - Consultar nomes");
            printf("\t\t\t\t\t3 - Deletar nomes");
            printf("\t\t\t\t\t\t4 - Sair do programa");
            printf("\n\n\n\nEste Software foi criado por Ryan Vasconcelos para uso privado");
            printf("\nAperte 'F11' para melhor usabilidade.");
            printf("\nOp��o:");
        
            scanf("%d", &opcao);
            

            switch (opcao) {
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
                    printf("Obrigado por utilizar o sistema\n");
                    return 0;
                    break;
            
                default:
                    erro();
                    break;
            }
    
            system("cls");
        }
    }
    
    return 0;
}

