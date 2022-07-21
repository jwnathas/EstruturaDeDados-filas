//arquivo de cabeçalho
#include <stdio.h>
#include <stdlib.h>

//processos
typedef struct no No;

typedef struct fila Fila;

//função para criar a fila de processos
void criarFila(Fila *fila);

//Função para inserir na fila
void inserirProcessos(Fila *fila, int id);

//Função para retirar da fila
No* removerProcesso(Fila *fila);

void imprimir(Fila *fila);
