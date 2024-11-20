#ifndef HORTIFRUTILIB_H
#define HORTIFRUTILIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUTOS 500
#define TAMANHO_STRING 100

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
    printf("\nPressione Enter para continuar.");
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
    int i = 0;
    while (fscanf(arquivo, "%d;%49[^;];%49[^;];%d;%f\n", &produto[i].id, produto[i].nome, produto[i].tipo, &produto[i].quantidade, &produto[i].preco) != EOF) {
        totalProdutos++;
        i++;
    }

    fclose(arquivo);
}

void acessoNegado() {
    printf("\nNumero maximo de tentativas atingido.\nAcesso negado!\n\n");
    exit(0);
}

void sair() {
    limparTela();
    printf("------------------------------------\n");
    printf("--------- Saindo do Programa -------\n");
    printf("------------------------------------\n");
    exit(0);
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

void visualizarTodosProdutos() {
    limparTela();
    if (totalProdutos == 0) {
        printf("Nenhum produto cadastrado.\n");
        pausar();
        return;
    }

    printf("Lista de Produtos Cadastrados:\n\n");
    for (int i = 0; i < totalProdutos; i++) {
        Produto prod = produto[i];
        printf("ID: %d | Nome: %s | Tipo: %s | Quantidade: %d | Preco: %.2f\n", 
               prod.id, prod.nome, prod.tipo, prod.quantidade, prod.preco);
    }
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
        printf("Nome atual: %s\nDigite o novo nome : ",       produto[indice].nome);
        char novoNome[TAMANHO_STRING];
        fgets(novoNome, TAMANHO_STRING, stdin);
        novoNome[strcspn(novoNome, "\n")] = '\0';
        if (strlen(novoNome) > 0) {
            strcpy(produto[indice].nome, novoNome);
        }

        printf("Tipo atual: %s\nDigite o novo tipo: ", produto[indice].tipo);
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
        Produto prod = produto[i];
        if (prod.id == id) {
            printf("ID: %d | Nome: %s | Tipo: %s | Quantidade: %d | Preco: %.2f\n",
                   prod.id, prod.nome, prod.tipo, prod.quantidade, prod.preco);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Nenhum produto encontrado com o ID informado.\n");
    }

    pausar();
}

void realizarCompra() {
    limparTela();
    
    if (totalProdutos == 0) {
        printf("Nenhum produto cadastrado.\n");
        pausar();
        return;
    }

    int id, quantidadeCompra, adicionarOutro = 1;
    float totalCompra = 0;

    while (adicionarOutro == 1) {
        printf("Digite o ID do produto que deseja comprar: ");
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
            printf("ID não encontrado.\n");
            pausar();
            return;
        }

        printf("Produto: %s\nQuantidade disponivel: %d\nPreco: %.2f\n", 
               produto[indice].nome, produto[indice].quantidade, produto[indice].preco);

        printf("Digite a quantidade que deseja comprar: ");
        scanf("%d", &quantidadeCompra);

        if (quantidadeCompra <= 0) {
            printf("Quantidade invalida.\n");
            pausar();
            return;
        }

        if (quantidadeCompra > produto[indice].quantidade) {
            printf("Quantidade solicitada maior do que a disponivel no estoque.\n");
            pausar();
            return;
        }

        produto[indice].quantidade -= quantidadeCompra;
        totalCompra += produto[indice].preco * quantidadeCompra;

        printf("Deseja adicionar outro item? (1 - Sim, 0 - Nao): ");
        scanf("%d", &adicionarOutro);
    }

    printf("\nTotal da compra: %.2f\n", totalCompra);

    printf("Escolha o metodo de pagamento:\n");
    printf("1 - Dinheiro                  \n");
    printf("2 - Cartao                    \n");
    printf("3 - PIX                       \n");
    int metodoPagamento;
    scanf("%d", &metodoPagamento);

    float valorFinal = totalCompra, desconto;
    int parcelas = 1;

    switch (metodoPagamento) {
        case 1:
            desconto  = totalCompra * 0.05;
            printf("Pagamento em Dinheiro (5%% de desconto aplicado).\n");
            valorFinal = totalCompra - desconto;
            break;
        case 2:
            printf("Pagamento em Cartao.\n");
            printf("Deseja parcelar em quantas vezes? ");
            scanf("%d", &parcelas);
            if (parcelas > 1) {
                printf("Total por parcela: %.2f\n", valorFinal / parcelas);
            }
            break;
        case 3:
            desconto = totalCompra * 0.05;
            printf("Pagamento via PIX (5%% de desconto aplicado).\n");
            valorFinal = totalCompra - desconto;
            break;
        default:
            printf("Metodo de pagamento invalido.\n");
            pausar();
            return;
    }

    salvarProdutos();

    printf("Total a pagar: %.2f\n", valorFinal);
    printf("Compra realizada com sucesso!\n");
    if (parcelas > 1) {
        printf("Pagar %dx de %.2f\n", parcelas, valorFinal / parcelas);
    }
    pausar();
}
void exportarParaCSV(const char *nomeArquivo) {
    FILE *arquivoTXT = fopen(nomeArquivo, "r");
    if (arquivoTXT == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", nomeArquivo);
        pausar();
        return;
    }

    char nomeCSV[100];
    snprintf(nomeCSV, sizeof(nomeCSV), "%s.csv", nomeArquivo);

    FILE *arquivoCSV = fopen(nomeCSV, "w");
    if (arquivoCSV == NULL) {
        printf("Erro ao criar o arquivo %s.\n", nomeCSV);
        fclose(arquivoTXT);
        pausar();
        return;
    }

    fprintf(arquivoCSV, "Conteudo do arquivo %s:\n", nomeArquivo);

    char linha[300];
    while (fgets(linha, sizeof(linha), arquivoTXT)) {
        fprintf(arquivoCSV, "%s", linha);
    }

    fclose(arquivoTXT);
    fclose(arquivoCSV);

    printf("Arquivo exportado com sucesso para %s.\n", nomeCSV);
    pausar();
}

void exportarParaHTML(const char *nomeArquivo) {
    FILE *arquivoTXT = fopen(nomeArquivo, "r");
    if (arquivoTXT == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", nomeArquivo);
        pausar();
        return;
    }

    char nomeHTML[100];
    snprintf(nomeHTML, sizeof(nomeHTML), "%s.html", nomeArquivo);

    FILE *arquivoHTML = fopen(nomeHTML, "w");
    if (arquivoHTML == NULL) {
        printf("Erro ao criar o arquivo %s.\n", nomeHTML);
        fclose(arquivoTXT);
        pausar();
        return;
    }

    fprintf(arquivoHTML, "<html><body><h1>Relatório - %s</h1><pre>\n", nomeArquivo);

    char linha[300];
    while (fgets(linha, sizeof(linha), arquivoTXT)) {
        fprintf(arquivoHTML, "%s", linha);
    }

    fprintf(arquivoHTML, "</pre></body></html>");

    fclose(arquivoTXT);
    fclose(arquivoHTML);

    printf("Arquivo exportado com sucesso para %s.\n", nomeHTML);
    pausar();
}

void exportarRelatorios() {
    int opcaoPrincipal, opcaoArquivos, opcaoExportar;

    do {
        limparTela();
        printf("-------- Exportar Relatorios --------\n");
        printf("0 - Voltar ao menu principal\n");
        printf("1 - Escolher arquivo .txt para gerar relatorio\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcaoPrincipal);
        getchar();

        if (opcaoPrincipal == 1) {
            do {
                limparTela();
                printf("-------- Escolher Arquivo --------\n");
                printf("0 - Voltar\n");
                printf("1 - hortiFruti.txt\n");
                printf("Escolha um arquivo: ");
                scanf("%d", &opcaoArquivos);
                getchar();

                const char *arquivoSelecionado = NULL;
                if (opcaoArquivos == 1) {
                    arquivoSelecionado = "hortiFruti.txt";
                } else if (opcaoArquivos == 0) {
                    break;
                } else {
                    printf("opcao invalida.\n");
                    pausar();
                    continue;
                }

                do {
                    limparTela();
                    printf("-------- Formatos de Exportacao --------\n");
                    printf("0 - Voltar\n");
                    printf("1 - Exportar como HTML\n");
                    printf("2 - Exportar como CSV\n");
                    printf("Escolha uma opcao: ");
                    scanf("%d", &opcaoExportar);
                    getchar();

                    switch (opcaoExportar) {
                        case 1:
                            exportarParaHTML(arquivoSelecionado);
                            break;
                        case 2:
                            exportarParaCSV(arquivoSelecionado);
                            break;
                        case 0:
                            break;
                        default:
                            printf("opcao invalida.\n");
                            pausar();
                            break;
                    }
                } while (opcaoExportar != 0);
            } while (opcaoArquivos != 0);
        } else if (opcaoPrincipal != 0) {
            printf("opcao invalida.\n");
            pausar();
        }
    } while (opcaoPrincipal != 0);
    
   limparTela();
}

#endif