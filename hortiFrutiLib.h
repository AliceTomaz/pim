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
    system("cls");
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

#endif