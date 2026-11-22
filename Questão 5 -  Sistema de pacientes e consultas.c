
#include <stdio.h>

struct Data {
    int dia;
    int mes;
    int ano;
};

struct Paciente {
    int codigo;
    char nome[50];
    int idade;
};

struct Consulta {
    struct Paciente paciente;
    struct Data data;
    char descricao[100];
};

int main() {
    struct Paciente pacientes[15];
    struct Consulta consultas[30];
    struct Data data;

    int qtdPacientes = 0, qtdConsultas = 0;
    int opcao, i, j, codigo, pos, cont, maior, maiorCont, achou;

    do {
        printf("\n--- MENU ---\n");
        printf("1 - Cadastrar paciente\n");
        printf("2 - Registrar consulta\n");
        printf("3 - Pesquisar consultas de um paciente pelo codigo\n");
        printf("4 - Listar consultas de uma data\n");
        printf("5 - Numero de consultas por paciente\n");
        printf("6 - Paciente com mais atendimentos\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (qtdPacientes == 15) {
                    printf("Limite de pacientes atingido\n");
                } else {
                    printf("Codigo: ");
                    scanf("%d", &codigo);

                    pos = -1;

                    for (i = 0; i < qtdPacientes; i++) {
                        if (pacientes[i].codigo == codigo) {
                            pos = i;
                        }
                    }

                    if (pos != -1) {
                        printf("Codigo ja cadastrado\n");
                    } else {
                        pacientes[qtdPacientes].codigo = codigo;

                        printf("Nome: ");
                        scanf(" %[^\n]", pacientes[qtdPacientes].nome);

                        printf("Idade: ");
                        scanf("%d", &pacientes[qtdPacientes].idade);

                        qtdPacientes++;
                        printf("Paciente cadastrado\n");
                    }
                }
                break;

            case 2:
                if (qtdConsultas == 30) {
                    printf("Limite de consultas atingido\n");
                } else {
                    printf("Codigo do paciente: ");
                    scanf("%d", &codigo);

                    pos = -1;

                    for (i = 0; i < qtdPacientes; i++) {
                        if (pacientes[i].codigo == codigo) {
                            pos = i;
                        }
                    }

                    if (pos == -1) {
                        printf("Paciente nao cadastrado\n");
                    } else {
                        consultas[qtdConsultas].paciente = pacientes[pos];

                        printf("Data da consulta (dia mes ano): ");
                        scanf("%d %d %d",
                              &consultas[qtdConsultas].data.dia,
                              &consultas[qtdConsultas].data.mes,
                              &consultas[qtdConsultas].data.ano);

                        printf("Descricao do atendimento: ");
                        scanf(" %[^\n]", consultas[qtdConsultas].descricao);

                        qtdConsultas++;
                        printf("Consulta registrada\n");
                    }
                }
                break;

            case 3:
                printf("Codigo do paciente: ");
                scanf("%d", &codigo);

                achou = 0;

                for (i = 0; i < qtdConsultas; i++) {
                    if (consultas[i].paciente.codigo == codigo) {
                        printf("%02d/%02d/%d - %s (%s)\n",
                               consultas[i].data.dia,
                               consultas[i].data.mes,
                               consultas[i].data.ano,
                               consultas[i].descricao,
                               consultas[i].paciente.nome);

                        achou = 1;
                    }
                }

                if (achou == 0) {
                    printf("Nenhuma consulta encontrada para esse codigo\n");
                }
                break;

            case 4:
                printf("Data (dia mes ano): ");
                scanf("%d %d %d", &data.dia, &data.mes, &data.ano);

                achou = 0;

                for (i = 0; i < qtdConsultas; i++) {
                    if (consultas[i].data.dia == data.dia &&
                        consultas[i].data.mes == data.mes &&
                        consultas[i].data.ano == data.ano) {

                        printf("%s - %s\n",
                               consultas[i].paciente.nome,
                               consultas[i].descricao);

                        achou = 1;
                    }
                }

                if (achou == 0) {
                    printf("Nenhuma consulta nessa data\n");
                }
                break;

            case 5:
                if (qtdPacientes == 0) {
                    printf("Nenhum paciente cadastrado\n");
                } else {
                    for (i = 0; i < qtdPacientes; i++) {
                        cont = 0;

                        for (j = 0; j < qtdConsultas; j++) {
                            if (consultas[j].paciente.codigo == pacientes[i].codigo) {
                                cont++;
                            }
                        }

                        printf("%s: %d consulta(s)\n", pacientes[i].nome, cont);
                    }
                }
                break;

            case 6:
                if (qtdPacientes == 0) {
                    printf("Nenhum paciente cadastrado\n");
                } else {
                    maior = 0;
                    maiorCont = 0;

                    for (i = 0; i < qtdPacientes; i++) {
                        cont = 0;

                        for (j = 0; j < qtdConsultas; j++) {
                            if (consultas[j].paciente.codigo == pacientes[i].codigo) {
                                cont++;
                            }
                        }

                        if (cont > maiorCont) {
                            maiorCont = cont;
                            maior = i;
                        }
                    }

                    if (maiorCont == 0) {
                        printf("Nenhuma consulta registrada\n");
                    } else {
                        printf("Paciente com mais atendimentos: %s (%d consultas)\n",
                               pacientes[maior].nome, maiorCont);
                    }
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
