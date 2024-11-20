#ifndef GERENTE_H
#define GERENTE_H
#include "hortiFrutiLib.h"


#define MAX_TENTATIVAS 5          // Numero maximo de tentativas para login do gerente
#define LOGIN_GERENTE "HORTI10"   // Login  do gerente
#define SENHA_GERENTE "G12345"    // Senha  do gerente

/* 
 * Funçao para autenticaçao do gerente e gerenciamento de operações relacionadas 
 */
void senhaGerente() {
    limparTela(); // Limpa a tela antes de iniciar a autenticação
    char login[20];  // Armazena o login digitado pelo usuário
    char senha[20];  // Armazena a senha digitada pelo usuário
    int tentativas = 0; // Contador de tentativas de login

    /* Loop para verificar as credenciais do gerente */
    while (tentativas < MAX_TENTATIVAS) {
        printf("Login: ");
        scanf("%s", login); //  login
        printf("Senha: ");
        scanf("%s", senha); // senha
        limparTela(); // Limpa a tela após a entrada de dados

        /* Verifica se o login e a senha correspondem aos valores definidos */
        if (strcmp(login, LOGIN_GERENTE) == 0 && strcmp(senha, SENHA_GERENTE) == 0) {
            printf("Bem vindo, HORTI10! \n\n");

            int opcao; // Variável para armazenar a escolha no menu

            carregarProdutos(); // Carrega a lista de produtos do estoque

            printf("----------------------------\n");
            printf("-------- HORTIFRUTI --------\n");
            printf("----------------------------\n");

            /* Menu de operaçoes do gerente */
            do {
                printf("1 - Cadastrar Produto   \n");
                printf("2 - Visualizar Estoque  \n");
                printf("3 - Editar Produto      \n");
                printf("4 - Visualizar Produto  \n");
                printf("5 - Excluir produto     \n");
                printf("6 - Sair do Programa    \n");
                scanf("%d", &opcao); // Captura a opção do gerente
                getchar(); // Consome o caractere de nova linha para evitar erros

                /* Processa a opção escolhida pelo gerente */
                switch (opcao) {
                    case 1:
                        cadastrarProduto(); // Cadastra um novo produto
                        break;
                    case 2:
                        visualizarTodosProdutos(); // Exibe o estoque completo
                        break;
                    case 3:
                        editarProduto(); // Permite editar um produto
                        break;
                    case 4:
                        visualizarProduto(); // Exibe detalhes de um produto específico
                        break;
                    case 5:
                        excluirProduto(); // Exclui um produto do estoque
                        break;
                    case 6:
                        sair(); // Sai do programa
                        break;
                    default:
                        limparTela(); // Limpa a tela e informa erro em caso de opção inválida
                        printf("Opcao invalida.\n");
                        break;
                }

            } while (opcao != 6); // Mantem o menu ativo ate o gerente optar por sair
        } else {
            /* Caso as credenciais sejam invalidas */
            printf("Usuario ou senha invalido.\n");
            tentativas++; // Incrementa o numero de tentativas
            printf("Tentativas restantes: %d\n", MAX_TENTATIVAS - tentativas);
        }
    }

    /* Açao tomada apos exceder o numero maximo de tentativas */
    acessoNegado(); // Funçao que lida com a rejeiçao do acesso
}

#endif
