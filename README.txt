Portfolio1_ED2_2014_2
Aluno: Jackson Henrique Hochscheidt
=====================

Implementação do Portfólio parte 1, da disciplina de Estrutura de Dados II 2014.2 UFFS


Somente via terminal:
	-->Para compilar:
		gcc *.c -o "arquivo.out" -Wall -pedantic -std=c99
		Ex: *.c -o gerador -Wall -pedantic -std=c99
	-->Para executar:
		./"arquivo.out" tamanhoArquivo(int) quantidadePalavras(int) numeroMinimoChar(int) numeroMaximoChar(int)  nomeArquivo(char *)
		Ex: ./gerador 1000000 1000 3 20 filename.txt
	

OBS: para tamanhos muito grandes para "quantidadePalavras" ou "numeroMaximoChar" retorna o seguinte erro no terminal 
	|======================================================================================================================================	
	|gerador: malloc.c:2372: sysmalloc: Assertion `(old_top == (((mbinptr) (((char *) &((av)->bins[((1) - 1) * 2])) - __builtin_offsetof  | 	|(struct malloc_chunk, fd)))) && old_size == 0) || ((unsigned long) (old_size) >= (unsigned long)((((__builtin_offsetof (struct       | 	|malloc_chunk, fd_nextsize))+((2 *(sizeof(size_t))) - 1)) & ~((2 *(sizeof(size_t))) - 1))) && ((old_top)->size & 0x1) && ((unsigned   | 	|long) old_end & pagemask) == 0)' failed. Abortado (imagem do núcleo gravada)                                                         |
	|=====================================================================================================================================|

	Como exemplo usei as seguintes entradas: ./gerador 10000000 100000 2 30  jacksparrow.txt.
	Esta entrada gera o erro descrito acima. 




