
#include <stdio.h>

struct Aluno {
    int matricula;
    char nome[50];
    float nota1;
    float nota2;
    float media;
};

float calculaMedia(float n1, float n2) {
    return (n1 + n2) / 2;
}

int main() {
    struct Aluno alunos[10];
    int i, maior = 0, menor = 0, acima = 0;
    float soma = 0, mediaGeral;

    for (i = 0; i < 10; i++) {
        printf("\nAluno %d\n", i + 1);
        printf("Matricula: ");
        scanf("%d", &alunos[i].matricula);

        printf("Nome: ");
        scanf(" %[^\n]", alunos[i].nome);

        printf("Nota 1: ");
        scanf("%f", &alunos[i].nota1);

        printf("Nota 2: ");
        scanf("%f", &alunos[i].nota2);

        alunos[i].media = calculaMedia(alunos[i].nota1, alunos[i].nota2);
        soma = soma + alunos[i].media;
    }

    printf("\nSituacao dos alunos:\n");

    for (i = 0; i < 10; i++) {
        printf("%s - media %.2f - ", alunos[i].nome, alunos[i].media);

        if (alunos[i].media >= 6.0) {
            printf("aprovado\n");
        } else {
            printf("reprovado\n");
        }
    }

    for (i = 1; i < 10; i++) {
        if (alunos[i].media > alunos[maior].media) {
            maior = i;
        }

        if (alunos[i].media < alunos[menor].media) {
            menor = i;
        }
    }

    mediaGeral = soma / 10;

    for (i = 0; i < 10; i++) {
        if (alunos[i].media > mediaGeral) {
            acima++;
        }
    }

    printf("\nMaior media: %s (%.2f)\n", alunos[maior].nome, alunos[maior].media);
    printf("Menor media: %s (%.2f)\n", alunos[menor].nome, alunos[menor].media);
    printf("Media geral da turma: %.2f\n", mediaGeral);
    printf("Alunos acima da media geral: %d\n", acima);

    return 0;
}
