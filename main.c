#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

#ifdef _WIN32
    #define LIMPA_TELA "cls"
#else
    #define LIMPA_TELA "clear"
#endif

void pausar() {
    printf("\nPressione ENTER para continuar...");
    getchar(); // consome enter anterior
    getchar();
}

void casosDeTeste() {
    Fila f;
    int valor;

    inicializarFila(&f);

    printf("===== CASOS DE TESTE AUTOMATICOS =====\n");

    for (int i = 1; i <= 5; i++) {
        enqueue(&f, i * 10);
        printf("Enfileirado: %d\n", i * 10);
    }

    peek(&f, &valor);
    printf("Inicio da fila: %d\n", valor);

    for (int i = 0; i < 2; i++) {
        dequeue(&f, &valor);
        printf("Removido: %d\n", valor);
    }

    enqueue(&f, 60);
    enqueue(&f, 70);

    while (!isEmpty(&f)) {
        dequeue(&f, &valor);
        printf("Removido: %d\n", valor);
    }

    printf("===== FIM DOS TESTES =====\n");
    pausar();
}

void menuInterativo() {
    Fila f;
    inicializarFila(&f);

    FILE *arquivo = fopen("operacoes_fila.txt", "w");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo para salvar dados!\n");
        return;
    }

    int opcao, valor, removido;

    do {
        system(LIMPA_TELA);
        printf("===== MENU FILA =====\n");
        printf("1 - Inserir no fim\n");
        printf("2 - Remover do inicio\n");
        printf("3 - Consultar inicio\n");
        printf("4 - Verificar se esta vazia\n");
        printf("5 - Verificar se esta cheia\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                if (enqueue(&f, valor)) {
                    printf("Enfileirado: %d\n", valor);
                    fprintf(arquivo, "Inserido: %d\n", valor);
                } else {
                    printf("Fila cheia!\n");
                    fprintf(arquivo, "Falha ao inserir %d (fila cheia)\n", valor);
                }
                pausar();
                break;

            case 2:
                if (dequeue(&f, &removido)) {
                    printf("Removido: %d\n", removido);
                    fprintf(arquivo, "Removido: %d\n", removido);
                } else {
                    printf("Fila vazia!\n");
                    fprintf(arquivo, "Falha ao remover (fila vazia)\n");
                }
                pausar();
                break;

            case 3:
                if (peek(&f, &valor)) {
                    printf("Inicio da fila: %d\n", valor);
                    fprintf(arquivo, "Consultado inicio: %d\n", valor);
                } else {
                    printf("Fila vazia!\n");
                    fprintf(arquivo, "Falha ao consultar inicio (fila vazia)\n");
                }
                pausar();
                break;

            case 4:
                printf("%s\n", isEmpty(&f) ? "Fila vazia" : "Fila nao vazia");
                fprintf(arquivo, "Verificacao: %s\n", isEmpty(&f) ? "Fila vazia" : "Fila nao vazia");
                pausar();
                break;

            case 5:
                printf("%s\n", isFull(&f) ? "Fila cheia" : "Fila nao cheia");
                fprintf(arquivo, "Verificacao: %s\n", isFull(&f) ? "Fila cheia" : "Fila nao cheia");
                pausar();
                break;

            case 0:
                printf("Saindo do menu...\n");
                break;

            default:
                printf("Opcao invalida!\n");
                pausar();
        }
    } while (opcao != 0);

    fclose(arquivo);
    printf("Operacoes salvas em 'operacoes_fila.txt'.\n");
}

int main() {
    system(LIMPA_TELA);
    casosDeTeste();
    menuInterativo();
    return 0;
}
