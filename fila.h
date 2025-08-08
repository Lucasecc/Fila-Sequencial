#ifndef FILA_H
#define FILA_H

#define MAX 5  // tamanho máximo da fila

typedef struct {
    int dados[MAX];
    int inicio;
    int fim;
    int tamanho;
} Fila;

void inicializarFila(Fila *f);
int isEmpty(Fila *f);
int isFull(Fila *f);
int enqueue(Fila *f, int valor);
int dequeue(Fila *f, int *removido);
int peek(Fila *f, int *primeiro);

#endif
