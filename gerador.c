#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funcoesGerador.c"

int main(int argv , char **argc){
	srand(time(NULL)); // gera "semente" de acordo com a hora atual em segundos
	
	unsigned int sizeFile = atoi(argc[1]);
	//printf("\n sizeFile --> %i ", sizeFile);
		
	unsigned int numWords = atoi(argc[2]);
	//printf("\t numWords --> %i ", numWords);
	
	unsigned int minW = atoi(argc[3]);
	//printf("\t minW --> %i ", minW);
	
	unsigned int maxW = atoi(argc[4]);
	//printf("\t maxW --> %i ", maxW);
	
	char *nameArchive = (char *)malloc(1);
	strcpy(nameArchive, argc[5]);
	
	if(nameArchive != NULL)	printf("\t nameArchive --> %s \n", nameArchive);
		
	if(sizeFile < numWords || sizeFile < numWords * minW + numWords || minW > maxW)
		return 1; //retorna 1 parametros passados de forma errada
		
				
	FILE *arquivo = fopen(nameArchive, "w+");
	fclose(arquivo);
	if(arquivo)	printf("\n \tARQUIVO CRIADO COM SUCESSO \n\n");
	else{
		 printf("ERRO NA CRIACAO DO ARQUIVO");
		 return 1;
	}
	
	unsigned int sizeFileTemp = 0;
	int tamanhoMaxWord = 0;
	int tamanhoWord = 0;
	//int tamMalloc = numWords * 2 * maxW	;
	char *texto  = (char*) malloc(sizeFile);
	
	if(!texto){
		printf("fia da puuuuuuu");
		return 1;
	}
	
	int contLaco = 0;
	arquivo = fopen(nameArchive, "w+");
	while(sizeFile > sizeFileTemp && numWords > 0){
		printf("cont laco %d \n", contLaco);
		contLaco++;
		tamanhoMaxWord = (sizeFile - sizeFileTemp) / (numWords * 2);
		if(tamanhoMaxWord >= maxW){
			tamanhoMaxWord = maxW;
		}
		tamanhoWord = minW + (rand() % (tamanhoMaxWord - minW));
		//printf("TAMANHO DA WORD %d \n", tamanhoWord);
		texto = geradorDePalavra(tamanhoWord, texto);
		numWords--;	
		sizeFileTemp = sizeFileTemp + tamanhoWord;
		//printf("temporario \t %d \n", sizeFileTemp);
		if(sizeFileTemp < sizeFile){
			texto = geradorDeSeparador(1,texto);
			sizeFileTemp = sizeFileTemp + 1;
		}		
		fscanf(arquivo, "%s", texto);
	}
	
	printf("saiu do laco");
	
	
	if(numWords == 0 && sizeFile > sizeFileTemp){
		int quantSeparadores = sizeFile - sizeFileTemp;
		char *separadores = (char*) malloc(quantSeparadores);
		printf("aisdjuaoisdjfhaoikfalkdkljsa");
		separadores = geradorDeSeparador(quantSeparadores,texto);
		fscanf(arquivo, "%s", separadores);
	}
	//printf("texto gerado %s \n", texto);
	fclose(arquivo);
		
	return 0;
}
