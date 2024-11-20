#ifndef CAIXA_H
#define CAIXA_H
#include "hortiFrutiLib.h"

#define MAX_TENTATIVAS 5
#define LOGIN_CAIXA "HORTI05"
#define SENHA_CAIXA "F12345"

void senhaCaixa() {
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

        if (strcmp(login, LOGIN_CAIXA) == 0 && strcmp(senha, SENHA_CAIXA) == 0) {
            printf("Bem vindo, HORTI05! \n\n");

            int opcao;

            carregarProdutos();

            printf("----------------------------\n");
            printf("-------- HORTIFRUTI --------\n");
            printf("----------------------------\n");

            do {
                printf("1 - Editar Produto      \n");
                printf("2 - Visualizar Produto  \n");
                printf("3 - Visualizar Estoque  \n");
                printf("4 - Compra (Cliente)    \n");
                printf("5 - Sair do Programa    \n");
                scanf("%d", &opcao);
                getchar();

                switch (opcao) {
                    case 1:
                        editarProduto();
                        break;
                    case 2:
                        visualizarProduto();
                        break;
                    case 3:
                        visualizarTodosProdutos();
                        break;
                    case 4:
                        realizarCompra();
                        break;
                    case 5:
                        sair();
                        break;
                    default:
                        limparTela();
                        printf("Opcao invalida.\n");
                        break;
                }

            } while (opcao != 5);
        } else {
            printf("Usuario ou senha invalido.\n");
            tentativas++;
            printf("Tentativas restantes: %d\n", MAX_TENTATIVAS - tentativas);
        }
    }

    acessoNegado();
}

#endif