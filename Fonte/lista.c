#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"

// Retorna 1 (True) se o parâmetro l1 vem antes na ordem alfabetica

int alfa(char l1[], char l2[]){
    for(int i = 0; l1[i] != '\0'; i++){
        if(l1[i] < l2[i]){
            return 1;
        }else if(l1[i] > l2[i]){
            return 0;
        }
    }
}


// As duas funcoes abaixo atuam em conjunto, sao responsaveis por criar uma linked list seguindo a ordem alfabetica

Lista* criarNode(){
    Lista* temp = (Lista*) calloc(1, sizeof(Lista));
    temp->prox = NULL;
    return temp;
}


Lista* definirNode(Lista* head, char chassi[], char nome[]){
    Lista* temp;
    temp = criarNode();
    strcpy(temp->chassi, chassi);
    strcpy(temp->nome, nome);

    if(head == NULL){
        head = temp;
    }else if(alfa(temp->chassi, head->chassi)){
        temp->prox = head;
        return temp;
    }else{
        Lista* p = head;
        while(p->prox != NULL && alfa((p->prox)->chassi, temp->chassi)){
            p = p->prox;
        }

        if(p->prox != NULL){
            temp->prox = p->prox;
        }
        p->prox = temp;
    }

    return head;
}


// Realiza a leitura de um arquivo binário e retorna uma linked list com todos os dados lidos

Lista* leituraArquivoBinario(char arquivo[]){
    Lista* head = criarNode();
    head = NULL;
    FILE* bin = fopen(arquivo, "rb");
    char chassi[10], nome[50];

    char c;

    // Leitura char a char, enquanto j for 0, o char e adicionado ao chassi, enquanto for 1, o char é adicionado ao nome
    // A mudanca do valor de j ocorre depois de chassi alcancar um espaco, ou depois de nome chegar a um line feed

    for(int i = 0, j = 0; fread(&c, 1, 1, bin); i++){
        switch(j){
            case 0:
                if(c == ' '){
                    chassi[i] = '\0';
                    j = 1;
                    i = -1;
                }else{
                    chassi[i] = c;
                }
                break;
            case 1:
                if(c == '\n'){
                    nome[i] = '\0';
                    head = definirNode(head, chassi, nome);
                    j = 0;
                    i = -1;
                }else{
                    nome[i] = c;
                }
        }
    }    

    fclose(bin);
    return head;
}


// Libera o espaço de memória consumido pela linked list passada como parâmetro

void limpeza(Lista* head){
    if(head != NULL){
        limpeza(head->prox);
        free(head);
    }
}


// Escreve dados em um arquivo binário

void escritaBinaria(Lista* head, char arquivo[]){
    FILE* bin = fopen(arquivo, "wb");

    while(head != NULL){
        fwrite(head->chassi, strlen(head->chassi), 1, bin);
        fwrite(" ", 1, 1, bin);
        fwrite(head->nome, strlen(head->nome), 1, bin);
        fwrite("\n", 1, 1, bin);
        head = head->prox;
    }

    fclose(bin);
}