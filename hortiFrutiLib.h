#ifndef HORTIFRUTILIB_H
#define HORTIFRUTILIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUTOS 100
#define TAMANHO_STRING 50


typedef struct {
    int id;
    char nome[TAMANHO_STRING];
    char tipo[TAMANHO_STRING];
    int quantidade;
    float preco;
} Produto;

Produto produto[MAX_PRODUTOS];
int totalProdutos = 0;

void pausar() {
    printf("\nPressione Enter para continuar...");
    getchar();
}


void limparTela() {
    system("cls || clear");
}

void salvarProdutos() {
    FILE *arquivo = fopen("hortiFruti.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    for (int i = 0; i < totalProdutos; i++) {
        fprintf(arquivo, "%d;%s;%s;%d;%.2f\n", produto[i].id, produto[i].nome, produto[i].tipo, produto[i].quantidade, produto[i].preco);
    }

    fclose(arquivo);
}


void carregarProdutos() {
    FILE *arquivo = fopen("hortiFruti.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }
    totalProdutos = 0;
    int i = 0; // Declarar e inicializar o índice 'i'
    while (fscanf(arquivo, "%d;%49[^;];%49[^;];%d;%f\n", &produto[i].id, produto[i].nome, produto[i].tipo, &produto[i].quantidade, &produto[i].preco) != EOF) {
        totalProdutos++;
        i++;
    }

    fclose(arquivo);
}




void cadastrarProduto() {
    limparTela();
    printf("--------------------------\n");
    printf("-------- Cadastro --------\n");
    printf("--------------------------\n");
    if (totalProdutos >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido.\n");
        pausar();
        return;
    }

    Produto novoProduto;

    printf("Digite o ID do Produto (deve ser unico e um numero inteiro): ");
    scanf("%d", &novoProduto.id);
    getchar();

    for (int i = 0; i < totalProdutos; i++) {
        if (produto[i].id == novoProduto.id) {
            printf("ID ja existente, tente novamente.\n");
            pausar();
            return;
        }
    }

    printf("Digite o nome do produto: ");
    fgets(novoProduto.nome, TAMANHO_STRING, stdin);
    novoProduto.nome[strcspn(novoProduto.nome, "\n")] = '\0';

    printf("Digite o tipo de produto: ");
    fgets(novoProduto.tipo, TAMANHO_STRING, stdin);
    novoProduto.tipo[strcspn(novoProduto.tipo, "\n")] = '\0';


    printf("Digite a quantidade desse produto: ");
    scanf("%d", &novoProduto.quantidade);
    getchar();

    printf("Digite o preco do produto: ");
    scanf("%f", &novoProduto.preco);
    getchar();

    produto[totalProdutos] = novoProduto;
    totalProdutos++;

    salvarProdutos();
    printf("Produto cadastrado com sucesso!\n");
    pausar();
}

void excluirProduto() {
    limparTela();
    if (totalProdutos == 0) {
        printf("Nenhum produto cadastrado.\n");
        pausar();
        return;
    }

    int id;
    printf("Digite o ID do produto que deseja excluir: ");
    scanf("%d", &id);
    getchar();

    int indice = -1;
    for (int i = 0; i < totalProdutos; i++) {
        if (produto[i].id == id) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("ID nao encontrado.\n");
        pausar();
        return;
    }

    for (int i = indice; i < totalProdutos - 1; i++) {
        produto[i] = produto[i + 1];
    }
    totalProdutos--;

    salvarProdutos();
    printf("Produto excluido com sucesso!\n");
    pausar();
}

void editarProduto() {
    limparTela();
        if (totalProdutos == 0) {
            printf("Nenhum produto cadastrado.\n");
            pausar();
            return;
        }

        int id;
        printf("Digite o ID do produto que deseja editar: ");
        scanf("%d", &id);
        getchar();

        int indice = -1;
        for (int i = 0; i < totalProdutos; i++) {
            if (produto[i].id == id) {
                indice = i;
                break;
            }
        }

        if (indice == -1) {
            printf("ID invalido.\n");
            pausar();
            return;
        }

        printf("-------- Editar Produto de ID: %d --------\n", produto[indice].id);
        printf("Aperte ENTER para manter os dados atuais.\n");

        printf("Nome atual: %s\nDigite o nome novo: ", produto[indice].nome);
        char novoNome[TAMANHO_STRING];
        fgets(novoNome, TAMANHO_STRING, stdin);
        novoNome[strcspn(novoNome, "\n")] = '\0';
        if (strlen(novoNome) > 0) {
            strcpy(produto[indice].nome, novoNome);
        }

        printf("Tipo atual: %s\nDigite o tipo novo: ", produto[indice].tipo);
        char novoTipo[TAMANHO_STRING];
        fgets(novoTipo, TAMANHO_STRING, stdin);
        novoTipo[strcspn(novoTipo, "\n")] = '\0';
        if (strlen(novoTipo) > 0) {
            strcpy(produto[indice].tipo, novoTipo);
        }

        printf("\nQuantidade atual: %d\nDigite a nova quantidade: ", produto[indice].quantidade);
        char novaQuantidade[10];
        fgets(novaQuantidade, 10, stdin);
        novaQuantidade[strcspn(novaQuantidade, "\n")] = '\0';
        if (strlen(novaQuantidade) > 0) {
            produto[indice].quantidade = atoi(novaQuantidade);
        }

        printf("\nPreco atual: %.2f\nDigite o novo preco do produto: ", produto[indice].preco);
        char novoPreco[20];
        fgets(novoPreco, 20, stdin);
        novoPreco[strcspn(novoPreco, "\n")] = '\0';
        if (strlen(novoPreco) > 0) {
            produto[indice].preco = atof(novoPreco);
        }

        salvarProdutos();
        printf("Produto editado com sucesso!\n");
        pausar();
}
void visualizarProduto() {
    limparTela();
    if (totalProdutos == 0) {
        printf("Nenhum produto cadastrado.\n");
        pausar();
        return;
    }

    int id;
    printf("Digite o ID do produto que deseja visualizar: ");
    scanf("%d", &id);
    getchar();

    int encontrado = 0;
    for (int i = 0; i < totalProdutos; i++) {
        if (produto[i].id == id) {
            printf("ID: %d | Nome: %s | Tipo: %s | Quantidade: %d | Preco: %.2f\n", 
                   produto[i].id, produto[i].nome, produto[i].tipo, produto[i].quantidade, produto[i].preco);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Nenhum produto encontrado com o ID informado.\n");
    }

    pausar();
}





#endif