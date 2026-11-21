
#include <stdio.h>

struct Funcionario {
    int codigo;
    char nome[50];
    char cargo[30];
    float salarioBase;
    int horasExtras;
    float salarioBruto;
    float salarioLiquido;
};

int main() {
    struct Funcionario func[8];
    int qtd, i, maior = 0;
    float valorHora, valorHoraExtra, totalFolha = 0;

    do {
        printf("Quantos funcionarios deseja cadastrar (1 a 8)? ");
        scanf("%d", &qtd);
    } while (qtd < 1 || qtd > 8);

    for (i = 0; i < qtd; i++) {
        printf("\nFuncionario %d\n", i + 1);

        printf("Codigo: ");
        scanf("%d", &func[i].codigo);

        printf("Nome: ");
        scanf(" %[^\n]", func[i].nome);

        printf("Cargo: ");
        scanf(" %[^\n]", func[i].cargo);

        printf("Salario base: ");
        scanf("%f", &func[i].salarioBase);

        printf("Horas extras: ");
        scanf("%d", &func[i].horasExtras);

        valorHora = func[i].salarioBase / 160;
        valorHoraExtra = valorHora * 1.5;

        func[i].salarioBruto = func[i].salarioBase +
                               (func[i].horasExtras * valorHoraExtra);

        func[i].salarioLiquido = func[i].salarioBruto -
                                 (func[i].salarioBruto * 0.10);

        totalFolha = totalFolha + func[i].salarioBruto;

        if (func[i].salarioLiquido > func[maior].salarioLiquido) {
            maior = i;
        }
    }

    printf("\nSalario liquido de cada funcionario:\n");

    for (i = 0; i < qtd; i++) {
        printf("%s (%s): R$ %.2f\n",
               func[i].nome, func[i].cargo, func[i].salarioLiquido);
    }

    printf("\nMaior salario liquido: %s - R$ %.2f\n",
           func[maior].nome, func[maior].salarioLiquido);

    printf("Custo total da folha: R$ %.2f\n", totalFolha);

    return 0;
}
