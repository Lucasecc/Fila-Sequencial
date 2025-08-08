#include <stdio.h>
#include "fila.h"

void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
    f->tamanho = 0;
}

int isEmpty(Fila *f) {
    return f->tamanho == 0;
}

int isFull(Fila *f) {
    return f->tamanho == MAX;
}

int enqueue(Fila *f, int valor) {
    if (isFull(f)) {
        return 0; // fila cheia
    }
    f->dados[f->fim] = valor;
    f->fim = (f->fim + 1) % MAX;
    f->tamanho++;
    return 1;
}

int dequeue(Fila *f, int *removido) {
    if (isEmpty(f)) {
        return 0; // fila vazia
    }
    *removido = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->tamanho--;
    return 1;
}

int peek(Fila *f, int *primeiro) {
    if (isEmpty(f)) {
        return 0; // fila vazia
    }
    *primeiro = f->dados[f->inicio];
    return 1;
}
