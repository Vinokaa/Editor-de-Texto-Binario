#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"

// Realiza a leitura de um arquivo de texto e retorna uma linked list com todos os dados lidos

Lista* leituraArquivoTexto(char arquivo[]){
    Lista* head = criarNode();
    head = NULL;
    FILE* f = fopen(arquivo, "r");
    char chassi[10], nome[50];
    while(fscanf(f, "%s %s", chassi, nome) != EOF){
        head = definirNode(head, chassi, nome);
    }
    fclose(f);
    return head;
}


int main(int argc, char* argv[]){
    if(argc != 3){
        printf("Uso de comando invalido\n");
        printf("./gerador <nome do arquivo .txt> <nome do arquivo .bin>\n");
        return 1;
    }

    Lista* head = leituraArquivoTexto(argv[1]);

    if(head == NULL){
        printf("Arquivo '%s' nao encontrado", argv[1]);
        return 1;
    }

    escritaBinaria(head, argv[2]);

    limpeza(head);

    return 0;
}