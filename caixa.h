#ifndef CAIXA_H
#define CAIXA_H
#include "hortiFrutiLib.h"

/* 
 * Definicoes e constantes 
 */
#define MAX_TENTATIVAS 5          // Numero maximo de tentativas para login do caixa
#define LOGIN_CAIXA "HORTI05"     // Login padrao do caixa
#define SENHA_CAIXA "F12345"      // Senha padrao do caixa

/* 
 * Funcao para autenticacao do caixa e gerenciamento de operacoes relacionadas 
 */
void senhaCaixa() {
    limparTela(); // Limpa a tela antes de iniciar a autenticacao
    char login[20];  // Armazena o login digitado pelo usuario
    char senha[20];  // Armazena a senha digitada pelo usuario
    int tentativas = 0; // Contador de tentativas de login

    /* Loop para verificar as credenciais do caixa */
    while (tentativas < MAX_TENTATIVAS) {
        printf("Login: ");
        scanf("%s", login); // Captura o login
        printf("Senha: ");
        scanf("%s", senha); // Captura a senha
        limparTela(); // Limpa a tela apos a entrada de dados

        /* Verifica se o login e a senha correspondem aos valores definidos */
        if (strcmp(login, LOGIN_CAIXA) == 0 && strcmp(senha, SENHA_CAIXA) == 0) {
            printf("Bem vindo, HORTI05! \n\n");

            int opcao; // Variavel para armazenar a escolha no menu

            carregarProdutos(); // Carrega a lista de produtos do estoque

            /* Exibe o cabecalho inicial do menu */
            printf("----------------------------\n");
            printf("-------- HORTIFRUTI --------\n");
            printf("----------------------------\n");

            /* Menu de operacoes do caixa */
            do {
                printf("1 - Editar Produto      \n");
                printf("2 - Visualizar Produto  \n");
                printf("3 - Visualizar Estoque  \n");
                printf("4 - Compra (Cliente)    \n");
                printf("5 - Sair do Programa    \n");
                scanf("%d", &opcao); // Captura a opcao do caixa
                getchar(); // Consome o caractere de nova linha para evitar erros

                /* Processa a opcao escolhida pelo caixa */
                switch (opcao) {
                    case 1:
                        editarProduto(); // Permite editar um produto
                        break;
                    case 2:
                        visualizarProduto(); // Exibe detalhes de um produto especifico
                        break;
                    case 3:
                        visualizarTodosProdutos(); // Exibe o estoque completo
                        break;
                    case 4:
                        realizarCompra(); // Inicia o processo de compra para um cliente
                        break;
                    case 5:
                        sair(); // Sai do programa
                        break;
                    default:
                        limparTela(); // Limpa a tela e informa erro em caso de opcao invalida
                        printf("Opcao invalida.\n");
                        break;
                }

            } while (opcao != 5); // Mantem o menu ativo ate o caixa optar por sair
        } else {
            /* Caso as credenciais sejam invalidas */
            printf("Usuario ou senha invalido.\n");
            tentativas++; // Incrementa o numero de tentativas
            printf("Tentativas restantes: %d\n", MAX_TENTATIVAS - tentativas);
        }
    }

    /* Acao tomada apos exceder o numero maximo de tentativas */
    acessoNegado(); // Funcao que lida com a rejeicao do acesso
}

#endif
