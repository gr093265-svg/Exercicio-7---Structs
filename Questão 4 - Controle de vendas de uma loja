
#include <stdio.h>

struct Produto {
    int codigo;
    char nome[50];
    float preco;
    int estoque;
};

struct Venda {
    int codigoProduto;
    int quantidade;
    float valorTotal;
};

int main() {
    struct Produto produtos[10];
    struct Venda vendas[20];

    int qtdProdutos = 0, qtdVendas = 0;
    int opcao, codigo, pos, quantidade, i, j, maior;
    float faturamentoTotal, fatProduto, maiorFat;

    do {
        printf("\n--- MENU ---\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Registrar venda\n");
        printf("3 - Faturamento total e produto de maior faturamento\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            if (qtdProdutos == 10) {
                printf("Limite de produtos atingido\n");
            } else {
                printf("Codigo: ");
                scanf("%d", &codigo);

                pos = -1;

                for (i = 0; i < qtdProdutos; i++) {
                    if (produtos[i].codigo == codigo) {
                        pos = i;
                    }
                }

                if (pos != -1) {
                    printf("Codigo ja cadastrado\n");
                } else {
                    produtos[qtdProdutos].codigo = codigo;

                    printf("Nome: ");
                    scanf(" %[^\n]", produtos[qtdProdutos].nome);

                    printf("Preco: ");
                    scanf("%f", &produtos[qtdProdutos].preco);

                    printf("Estoque: ");
                    scanf("%d", &produtos[qtdProdutos].estoque);

                    qtdProdutos++;
                    printf("Produto cadastrado\n");
                }
            }

        } else if (opcao == 2) {
            if (qtdVendas == 20) {
                printf("Limite de vendas atingido\n");
            } else {
                printf("Codigo do produto vendido: ");
                scanf("%d", &codigo);

                pos = -1;

                for (i = 0; i < qtdProdutos; i++) {
                    if (produtos[i].codigo == codigo) {
                        pos = i;
                    }
                }

                if (pos == -1) {
                    printf("Produto nao cadastrado\n");
                } else {
                    printf("Quantidade vendida: ");
                    scanf("%d", &quantidade);

                    if (quantidade <= 0) {
                        printf("Quantidade invalida\n");
                    } else if (quantidade > produtos[pos].estoque) {
                        printf("Estoque insuficiente (%d disponiveis)\n",
                               produtos[pos].estoque);
                    } else {
                        vendas[qtdVendas].codigoProduto = codigo;
                        vendas[qtdVendas].quantidade = quantidade;
                        vendas[qtdVendas].valorTotal = quantidade * produtos[pos].preco;

                        produtos[pos].estoque = produtos[pos].estoque - quantidade;

                        printf("Venda registrada. Total: R$ %.2f\n",
                               vendas[qtdVendas].valorTotal);

                        qtdVendas++;
                    }
                }
            }

        } else if (opcao == 3) {
            if (qtdVendas == 0) {
                printf("Nenhuma venda registrada\n");
            } else {
                faturamentoTotal = 0;

                for (i = 0; i < qtdVendas; i++) {
                    faturamentoTotal = faturamentoTotal + vendas[i].valorTotal;
                }

                maior = 0;
                maiorFat = 0;

                for (i = 0; i < qtdProdutos; i++) {
                    fatProduto = 0;

                    for (j = 0; j < qtdVendas; j++) {
                        if (vendas[j].codigoProduto == produtos[i].codigo) {
                            fatProduto = fatProduto + vendas[j].valorTotal;
                        }
                    }

                    if (fatProduto > maiorFat) {
                        maiorFat = fatProduto;
                        maior = i;
                    }
                }

                printf("Faturamento total: R$ %.2f\n", faturamentoTotal);

                printf("Produto de maior faturamento: %s (R$ %.2f)\n",
                       produtos[maior].nome, maiorFat);
            }

        } else if (opcao != 0) {
            printf("Opcao invalida\n");
        }

    } while (opcao != 0);

    return 0;
}
