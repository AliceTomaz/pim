#include <stdio.h>
#include <string.h>

#define PRODUTOS_ESTOQUE 10

// variaveis
typedef struct {
    int id;
    char nome[50];
    int quantidade;
    float preco;
} Produto;

// Inicializa uma base de dados fixa
void inicializarEstoque(Produto estoque[]) {

    estoque[0] = (Produto){1, "Maca", 50, 4.0};
    estoque[1] = (Produto){2, "Banana", 30, 4.0};
    estoque[2] = (Produto){3, "Melancia", 40, 15.5};
    estoque[3] = (Produto){4, "Pera", 25, 6.0};
    estoque[4] = (Produto){5, "Morango", 10, 7.5};    
    estoque[5] = (Produto){4, "Laranja", 25, 4.0};
    estoque[6] = (Produto){5, "Limao", 10, 4.5};
    estoque[7] = (Produto){4, "Tomate", 25, 5.0};
    estoque[8] = (Produto){5, "Kiwi", 10, 7.5};
    estoque[9] = (Produto){4, "Amora", 50, 12.0};
}

void listarEstoque(Produto estoque[]) {
    printf("\n--------------------------------\n");
    printf("\n--------  Estoque Atual  -------\n");
    printf("\n--------------------------------\n");
     for (int i = 0; i < PRODUTOS_ESTOQUE; i++) {
    printf("ID: %d | Nome: %s | Quantidade: %d | Preço: %.2f\n", 
         estoque[i].id, estoque[i].nome, estoque[i].quantidade, estoque[i].preco);
    }
}

void comprarProduto(Produto estoque[]) {
    int nome, quantidadeDesejada;
    
    printf("Digite o nome do produto que deseja comprar: ");
    scanf("%s", &nome);

    for (int i = 0; i < PRODUTOS_ESTOQUE; i++) {
        if (estoque[i].nome == nome) {
            printf("Produto encontrado: %s\n", estoque[i].nome);
            printf("Quantidade disponível: %d\n", estoque[i].quantidade);
            printf("Digite a quantidade que deseja comprar: ");
            scanf("%d", &quantidadeDesejada);

            if (quantidadeDesejada > estoque[i].quantidade) {
                printf("Quantidade insuficiente no estoque!\n");
            } else {

                //ideia para comentar com a galera
                //fazer mais um if para forma de pagamento
                //podemos fazer com chave pix, cartao ou dinheiro


                
                estoque[i].quantidade -= quantidadeDesejada;
                printf("Compra realizada com sucesso! Quantidade restante: %d\n", estoque[i].quantidade);
            }
            return;
        }
    }
    
    printf("Produto '%s' não encontrado!\n", nome);
}

int main() {
    Produto estoque[PRODUTOS_ESTOQUE];
    inicializarEstoque(estoque);
    
    int opcao;
    
    do {
        printf("\n*******************************\n");
        printf("\n******   HORTFUYNTS US   ******\n");
        printf("\n*******************************\n");
        printf("1. Listar estoque\n");
        printf("2. Comprar produto\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                listarEstoque(estoque);
                break;
            case 2:
                comprarProduto(estoque);
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 3);
    
    return 0;
}
