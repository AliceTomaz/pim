/* 
  Programa principal para o sistema de um hortifruti.
  Este código gerencia as interaços principais com o sistema, como acesso ao caixa, gerente e cliente.
 */

#include "hortiFrutiLib.h" // Funçoes gerais do sistema hortifruti
#include "caixa.h"         // Funçoes relacionadas ao modulo de caixa
#include "gerente.h"       // Funçoes relacionadas ao modulo de gerente

/* Funçao principal */
int main() {
    int opcao; // Variavel para armazenar a opção escolhida pelo usuário

    /* Carrega os produtos do sistema, inicializando o catálogo */
    carregarProdutos();

    printf("----------------------------\n");
    printf("-------- HORTIFRUTI --------\n");
    printf("----------------------------\n");
    
    /* Loop principal do menu */
    do {
        /* Exibe as opções do menu principal */
        printf("1 - Caixa               \n");
        printf("2 - Gerente             \n");
        printf("3 - Cliente             \n");
        printf("5 - Sair do Programa    \n");


        scanf("%d", &opcao);
        getchar(); // Consome o caractere de nova linha para evitar problemas de entrada

        /* Executa a ação correspondente à opção escolhida */
        switch (opcao) {
            case 1:
                senhaCaixa(); // Verifica a senha e permite acesso ao módulo de caixa
                break;
            case 2:
                senhaGerente(); // Verifica a senha e permite acesso ao módulo de gerente
                break;
            case 3:
                realizarCompra(); // Permite ao cliente realizar uma compra
                break;
            case 5:
                sair(); // Finaliza o programa
                break;
            default:
                /* Limpa a tela e informa o usuário sobre uma opção inválida */
                limparTela();
                printf("Opcao invalida.\n");
                break;
        }

    } while (opcao != 3); // Continua exibindo o menu até o usuário escolher sair

    return 0; // Retorna 0 indicando execução bem-sucedida
}
