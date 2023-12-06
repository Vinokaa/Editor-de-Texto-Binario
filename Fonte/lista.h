#ifndef LISTA_H
#define LISTA_H

typedef struct Lista Lista;

struct Lista{
    char chassi[10];
    char nome[50];
    Lista* prox;
};

int alfa(char[], char[]);

Lista* criarNode();

Lista* definirNode(Lista*, char[], char[]);

Lista* leituraArquivoBinario(char[]);

void limpeza(Lista*);

void escritaBinaria(Lista*, char[]);

#endif