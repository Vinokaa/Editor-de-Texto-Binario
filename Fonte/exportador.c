#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    if(argc != 3){
        printf("Uso incorreto do comando\n");
        printf("./exportador <nome do arquivo .bin> <nome do arquivo.txt>\n");
        return 1;
    }

    FILE* bin = fopen(argv[1], "r");

    if(bin == NULL){
        printf("Arquivo '%s' nao encontrado\n", argv[1]);
    }

    FILE* txt = fopen(argv[2], "w");

    char c;

    while(fread(&c, 1, 1, bin)){
        fprintf(txt, "%c", c);
    }

    fclose(txt);
    fclose(bin);

    return 0;
}