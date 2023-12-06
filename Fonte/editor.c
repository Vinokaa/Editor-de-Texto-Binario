#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"

// Funcao recursiva que busca, na linked list, todos os dados de uma chave fornecida

Lista* busca(char chassi[], Lista* node){
    if(node == NULL){
        node = criarNode();
        strcpy(node->chassi, "N/A");
        strcpy(node->nome, "N/A");
        return node;
    }else if(strcmp(node->chassi, chassi) == 0){
        return node;
    }else{
        return busca(chassi, node->prox);
    }
}

void inputBusca(Lista* head){
    char chassi[10];
    printf("Digite o chassi do carro: ");
    fgets(chassi, 10, stdin);
    setbuf(stdin, NULL);
    Lista* result = busca(chassi, head);
    printf("%s %s\n\n", result->chassi, result->nome);
}


// Insere um novo valor na linked list, fazendo as devidas alteracoes em sua estrutura

Lista* inserir(Lista* head){
    char chassi[10], nome[50];
    printf("Digite o chassi do carro a ser adicionado: ");
    fgets(chassi, 10, stdin);
    setbuf(stdin, NULL);
    printf("Digite o nome do carro a ser adicionado (use '_' ao inves de espaco): ");
    fgets(nome, 50, stdin);
    setbuf(stdin, NULL);
    nome[strcspn(nome, "\n")] = '\0';
    head = definirNode(head, chassi, nome);
    printf("\nAdicionado:\n");
    printf("%s %s\n\n", chassi, nome);
    return head;
}


// Remove um valor da linked list, fazendo as devidas alteracoes em sua estrutura

Lista* remover(Lista* head){
    char chassi[10];
    printf("Digite o chassi do carro a ser removido: ");
    fgets(chassi, 10, stdin);
    setbuf(stdin, NULL);
    Lista* p = head;

    if(strcmp(chassi, p->chassi) == 0){
        head = p->prox;
        printf("Removido:\n");
        printf("%s %s\n\n", p->chassi, p->nome);
        free(p);
        return head;
    }

    while(p->prox != NULL && strcmp(chassi, (p->prox)->chassi) != 0){
        p = p->prox;
    }

    if(p->prox == NULL){
        printf("Chassi nao encontrado na lista\n\n");
    }else{
        Lista* endereco = p->prox;
        p->prox = endereco->prox;
        printf("Removido:\n");
        printf("%s %s\n\n", endereco->chassi, endereco->nome);
        free(endereco);
    }
    return head;
}



int main(int argc, char* argv[]){
    if(argc != 3){
        printf("Uso incorreto do comando\n");
        printf("./editor <nome do arquivo binario entrada> <nome do arquivo binario saida>\n");
        return 1;
    }

    Lista* head = leituraArquivoBinario(argv[1]);

    if(head == NULL){
        printf("Arquivo '%s' nao encontrado", argv[1]);
        return 1;
    }

    for(int entrada = 0; entrada != 5 && entrada != 6; ){
        printf("1. Consultar dados\n");
        printf("2. Inserir dados\n");
        printf("3. Remover dados\n");
        printf("4. Buscar dados\n");
        printf("5. Salvar e sair\n");
        printf("6. Descartar e sair\n\n");
        printf(": ");
        fscanf(stdin, "%d", &entrada);
        setbuf(stdin, NULL);
        printf("\n");

        switch(entrada){
            case 1:
                Lista* p = head;
                while(p != NULL){
                    printf("%s %s\n", p->chassi, p->nome);
                    p = p->prox;
                }
                printf("\n");
                break;
            case 2:
                head = inserir(head);
                break;
            case 3:
                head = remover(head);
                break;
            case 4:
                inputBusca(head);
                break;
            case 5:
                escritaBinaria(head, argv[2]);
                limpeza(head);
                break;
            case 6:
                limpeza(head);
                break;
            default:
                printf("\nOpcao indisponivel\n\n");
        }
    }

    return 0;
}