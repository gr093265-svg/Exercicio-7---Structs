
#include <stdio.h>

struct Produto {
    int codigo;
    char nome[50];
    float preco;
    int estoque;
};

int buscaProduto(struct Produto produtos[], int qtd, int codigo) {
    int i;

    for (i = 0; i < qtd; i++) {
        if (produtos[i].codigo == codigo) {
            return i;
        }
    }

    return -1;
}

void reporEstoque(int *estoque, int quantidade) {
    *estoque = *estoque + quantidade;
}

void baixaEstoque(int *estoque, int quantidade) {
    *estoque = *estoque - quantidade;
}

int main() {
    struct Produto produtos[15];
    int qtd = 0, opcao, codigo, pos, quantidade, i, maior;
    float totalEstoque, valor, maiorValor;

    do {
        printf("\n--- MENU ---\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Listar produtos\n");
        printf("3 - Repor estoque\n");
        printf("4 - Registrar venda\n");
        printf("5 - Consultar produto pelo codigo\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (qtd == 15) {
                    printf("Limite de produtos atingido\n");
                } else {
                    printf("Codigo: ");
                    scanf("%d", &codigo);

                    if (buscaProduto(produtos, qtd, codigo) != -1) {
                        printf("Codigo ja cadastrado\n");
                    } else {
                        produtos[qtd].codigo = codigo;

                        printf("Nome: ");
                        scanf(" %[^\n]", produtos[qtd].nome);

                        printf("Preco: ");
                        scanf("%f", &produtos[qtd].preco);

                        printf("Quantidade em estoque: ");
                        scanf("%d", &produtos[qtd].estoque);

                        qtd++;
                        printf("Produto cadastrado\n");
                    }
                }
                break;

            case 2:
                if (qtd == 0) {
                    printf("Nenhum produto cadastrado\n");
                } else {
                    totalEstoque = 0;
                    maior = 0;
                    maiorValor = 0;

                    for (i = 0; i < qtd; i++) {
                        printf("Codigo: %d | Nome: %s | Preco: R$ %.2f | Estoque: %d\n",
                               produtos[i].codigo, produtos[i].nome,
                               produtos[i].preco, produtos[i].estoque);

                        valor = produtos[i].preco * produtos[i].estoque;
                        totalEstoque = totalEstoque + valor;

                        if (valor > maiorValor) {
                            maiorValor = valor;
                            maior = i;
                        }
                    }

                    printf("\nValor total em estoque: R$ %.2f\n", totalEstoque);
                    printf("Produto com maior valor em estoque: %s (R$ %.2f)\n",
                           produtos[maior].nome, maiorValor);
                }
                break;

            case 3:
                printf("Codigo do produto: ");
                scanf("%d", &codigo);

                pos = buscaProduto(produtos, qtd, codigo);

                if (pos == -1) {
                    printf("Produto nao encontrado\n");
                } else {
                    printf("Quantidade a repor: ");
                    scanf("%d", &quantidade);

                    if (quantidade <= 0) {
                        printf("Quantidade invalida\n");
                    } else {
                        reporEstoque(&produtos[pos].estoque, quantidade);
                        printf("Novo estoque: %d\n", produtos[pos].estoque);
                    }
                }
                break;

            case 4:
                printf("Codigo do produto: ");
                scanf("%d", &codigo);

                pos = buscaProduto(produtos, qtd, codigo);

                if (pos == -1) {
                    printf("Produto nao encontrado\n");
                } else {
                    printf("Quantidade vendida: ");
                    scanf("%d", &quantidade);

                    if (quantidade <= 0) {
                        printf("Quantidade invalida\n");
                    } else if (quantidade > produtos[pos].estoque) {
                        printf("Venda maior que a quantidade disponivel (%d)\n",
                               produtos[pos].estoque);
                    } else {
                        baixaEstoque(&produtos[pos].estoque, quantidade);
                        printf("Venda registrada. Total: R$ %.2f\n",
                               quantidade * produtos[pos].preco);
                    }
                }
                break;

            case 5:
                printf("Codigo do produto: ");
                scanf("%d", &codigo);

                pos = buscaProduto(produtos, qtd, codigo);

                if (pos == -1) {
                    printf("Produto nao encontrado\n");
                } else {
                    printf("Nome: %s\n", produtos[pos].nome);
                    printf("Preco: R$ %.2f\n", produtos[pos].preco);
                    printf("Estoque: %d\n", produtos[pos].estoque);
                }
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida\n");
        }

    } while (opcao != 0);

    return 0;
}
