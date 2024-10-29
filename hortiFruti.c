#include "hortiFrutiLib.h"

int main() {
    int opcao;

    // Carregar produtos existentes do arquivo ao iniciar o programa
    carregarProdutos();

    printf("----------------------------\n");
    printf("-------- HORTIFRUTI --------\n");
    printf("----------------------------\n");
    
    do {
        printf("1 - Cadastrar Produtos \n");
        printf("2 - Excluir Produtos   \n");
        printf("3 - Editar Produtos    \n");
        printf("4 - Visulizar Produtos \n");
        printf("5 - Sair do Programa   \n");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                cadastrarProduto();
                break;
            case 2:
                printf("--------------------------\n");
                printf("--------- Excluir --------\n");
                printf("--------------------------\n");
                break;
            case 3:
                printf("--------------------------\n");
                printf("--------- Editar ---------\n");
                printf("--------------------------\n");
                break;
            case 4:
                printf("--------------------------\n");
                printf("------- Vizualizar -------\n");
                printf("--------------------------\n");
                break;
            default:
                system("cls");
                printf("Opcao invalida.\n");
                break;
        }

    } while (opcao != 5);

    return 0;
}
