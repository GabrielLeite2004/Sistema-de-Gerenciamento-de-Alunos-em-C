#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int sequencial;
    int matricula;
    char nome[50];
} Aluno;


void cadastrarAluno(Aluno *alunos, int *totalAlunos) {
    printf("Matrícula do aluno: ");
    scanf("%d", &alunos[*totalAlunos].matricula);

    printf("Nome do aluno: ");
    scanf(" %[^\n]", alunos[*totalAlunos].nome);

    alunos[*totalAlunos].sequencial = (*totalAlunos) + 1;
    (*totalAlunos)++;
}


void editarAluno(Aluno *alunos, int totalAlunos, int matricula) {
    for (int i = 0; i < totalAlunos; i++) {
        if (alunos[i].matricula == matricula) {
            printf("Novo nome do aluno: ");
            scanf(" %[^\n]", alunos[i].nome);
            break;
        }
    }
}


void deletarAluno(Aluno *alunos, int *totalAlunos, int matricula) {
    for (int i = 0; i < *totalAlunos; i++) {
        if (alunos[i].matricula == matricula) {

            alunos[i] = alunos[*totalAlunos - 1];
            (*totalAlunos)--;
            printf("Aluno deletado com sucesso.\n");
            break;
        }
    }
}


int compararAlunos(const void *a, const void *b) {
    return ((Aluno *)a)->sequencial - ((Aluno *)b)->sequencial;
}


void pesquisarAluno(Aluno *alunos, int totalAlunos, int matricula) {
    for (int i = 0; i < totalAlunos; i++) {
        if (alunos[i].matricula == matricula) {
            printf("Aluno encontrado:\n");
            printf("Sequencial: %d\n", alunos[i].sequencial);
            printf("Matrícula: %d\n", alunos[i].matricula);
            printf("Nome: %s\n", alunos[i].nome);
            return;
        }
    }
    printf("Aluno não encontrado.\n");
}


void salvarDados(Aluno *alunos, int totalAlunos) {
    FILE *arquivo = fopen("alunos.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    for (int i = 0; i < totalAlunos; i++) {
        fprintf(arquivo, "%d %d %s\n", alunos[i].sequencial, alunos[i].matricula, alunos[i].nome);
    }

    fclose(arquivo);
}


int carregarDados(Aluno *alunos) {
    FILE *arquivo = fopen("alunos.txt", "r");
    if (arquivo == NULL) {
        return 0;
    }

    int totalAlunos = 0;
    while (fscanf(arquivo, "%d %d %[^\n]", &alunos[totalAlunos].sequencial, &alunos[totalAlunos].matricula, alunos[totalAlunos].nome) != EOF) {
        totalAlunos++;
    }

    fclose(arquivo);
    return totalAlunos;
}

int main() {
    Aluno alunos[100];
    int totalAlunos = 0;

    totalAlunos = carregarDados(alunos);

    int opcao;
    do {
            system("cls");
        printf("1 - Cadastrar aluno\n");
        printf("2 - Editar aluno\n");
        printf("3 - Deletar aluno\n");
        printf("4 - Ordenar alunos\n");
        printf("5 - Pesquisar aluno\n");
        printf("6 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarAluno(alunos, &totalAlunos);
                break;
            case 2:
                if (totalAlunos > 0) {
                    int matriculaEditar;
                    printf("Matrícula do aluno a ser editado: ");
                    scanf("%d", &matriculaEditar);
                    editarAluno(alunos, totalAlunos, matriculaEditar);
                } else {
                    printf("Nenhum aluno cadastrado.\n");
                }
                break;
            case 3:
                if (totalAlunos > 0) {
                    int matriculaDeletar;
                    printf("Matrícula do aluno a ser deletado: ");
                    scanf("%d", &matriculaDeletar);
                    deletarAluno(alunos, &totalAlunos, matriculaDeletar);
                } else {
                    printf("Nenhum aluno cadastrado.\n");
                }
                break;
            case 4:
                if (totalAlunos > 0) {
                    qsort(alunos, totalAlunos, sizeof(Aluno), compararAlunos);
                    printf("Alunos ordenados por sequencial.\n");
                } else {
                    printf("Nenhum aluno cadastrado.\n");
                }
                break;
            case 5:
                if (totalAlunos > 0) {
                    int matriculaPesquisar;
                    printf("Matrícula do aluno a ser pesquisado: ");
                    scanf("%d", &matriculaPesquisar);
                    pesquisarAluno(alunos, totalAlunos, matriculaPesquisar);
                } else {
                    printf("Nenhum aluno cadastrado.\n");
                }
                break;
            case 6:
                salvarDados(alunos, totalAlunos);
                printf("Dados salvos no arquivo.\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 9);

    return 0;
}
