#ifndef GERENTE_H
#define GERENTE_H
#include "hortiFrutiLib.h"

#define MAX_TENTATIVAS 5
#define LOGIN_GERENTE "HORTI10"
#define SENHA_GERENTE "G12345"

void senhaGerente() {
    limparTela();
    char login[20];
    char senha[20];
    int tentativas = 0;

    while (tentativas < MAX_TENTATIVAS) {
        printf("Login: ");
        scanf("%s", login);
        printf("Senha: ");
        scanf("%s", senha);
        limparTela();

        if (strcmp(login, LOGIN_GERENTE) == 0 && strcmp(senha, SENHA_GERENTE) == 0) {
            printf("Bem vindo, HORTI10! \n\n");

            int opcao;

            carregarProdutos();

            printf("----------------------------\n");
            printf("-------- HORTIFRUTI --------\n");
            printf("----------------------------\n");

            do {
                printf("1 - Cadastrar Produto   \n");
                printf("2 - Visualizar Estoque  \n");
                printf("3 - Editar Produto      \n");
                printf("4 - Visualizar Produto  \n");
                printf("5 - Excluir produto     \n");
                printf("6 - Sair do Programa    \n");
                scanf("%d", &opcao);
                getchar();

                switch (opcao) {
                    case 1:
                        cadastrarProduto();
                        break;
                    case 2:
                        visualizarTodosProdutos();
                        break;
                    case 3:
                        editarProduto();
                        break;
                    case 4:
                        visualizarProduto();
                        break;
                    case 5:
                        excluirProduto();
                        break;
                    case 6:
                        sair();
                        break;
                    default:
                        limparTela();
                        printf("Opcao invalida.\n");
                        break;
                }

            } while (opcao != 6);
        } else {
            printf("Usuario ou senha invalido.\n");
            tentativas++;
            printf("Tentativas restantes: %d\n", MAX_TENTATIVAS - tentativas);
        }
    }

    acessoNegado();
}

#endif