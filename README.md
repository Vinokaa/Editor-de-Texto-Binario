# Execução
./gerador <nome do arquivo .txt> <nome do arquivo .bin>  
./editor <nome do arquivo .bin entrada> <nome do arquivo .bin saida>  
./exportador <nome do arquivo .bin> <nome do arquivo .txt>


# Descrição
Um conjunto de três programas para editar um arquivo de texto composto por um código chave (no exemplo, chassi de carros) e outras informações (no exemplo, a marca e modelo do carro).


# Funcionamento Individual

- gerador.exe
   - Realiza a leitura de um arquivo de texto e o converte para um arquivo binário.

- editor.exe
   - Realiza a leitura do arquivo binário gerado pelo gerador.exe e disponibiliza algumas operações sobre esses dados, como consulta, inserção, remoção,  e busca.

- exportador.exe
   - Converte o arquivo binário para um arquivo de texto novamente.


# Observações
O armazenamento dos dados durante a execução dos programas é feito utilizando linked lists com armazenamento em memória dinâmica.

Caso queira compilar os arquivos fonte, os arquivos lista.c, gerador.c e editor.c devem ser compilados para objetos (arquivo .o):  
gcc -c -o lista.o lista.c  
gcc -c -o exportador.o exportador.c  
gcc -c -o editor.o editor.c

e após isso compilados em conjunto:  
gcc -o gerador gerador.o lista.o  
gcc -o editor editor.o lista.o.
