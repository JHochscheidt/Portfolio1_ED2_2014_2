#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funcoesGerador.h"

int main(int argv , char **argc){
		
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
		
	if(sizeFile < numWords || sizeFile < numWords * 2 * minW || minW > maxW){
		printf("parametros errados");
		return 1; //retorna 1 parametros passados de forma errada
	}
	srand(time(NULL)); // gera "semente" de acordo com a hora atual em segundos
			
	FILE *arquivo = fopen(nameArchive, "w+");
	fclose(arquivo);
	if(arquivo)	printf("\n \tARQUIVO CRIADO COM SUCESSO \n\n");
	else{
		 printf("ERRO NA CRIACAO DO ARQUIVO");
		 return 1;
	}
	
	int sizeFileTemp = 0;
	int tamanhoMaxWord = 0;
	int tamanhoWord = 0;
	char *texto  =  (char*) malloc(1);
		
	if(!texto) return 1;
	
	arquivo = fopen(nameArchive, "a+");
	while(sizeFile > sizeFileTemp && numWords > 0){
		tamanhoMaxWord = (sizeFile - sizeFileTemp) / (numWords * 2);
		if(tamanhoMaxWord >= maxW){
			tamanhoMaxWord = maxW;
		}
		tamanhoWord = minW + (rand() % (tamanhoMaxWord - minW));
		sizeFileTemp = sizeFileTemp + tamanhoWord;
		texto = geradorDePalavra(tamanhoWord);
		//printf("TEXTO %s",texto);
		fputs(texto,arquivo);
		numWords--;
		
		if(sizeFileTemp < sizeFile){
			texto = geradorDeSeparador(1);
			//printf("SEPARADOR %s",texto);
			fputs(texto,arquivo);
			sizeFileTemp++;
		}
		if(numWords == 0 && sizeFile > sizeFileTemp){
			int quantSeparadores = sizeFile - sizeFileTemp;
			while(quantSeparadores > 0){
				texto = geradorDeSeparador();
				//printf("WHILE %s",texto);
				quantSeparadores--;
				fputs(texto,arquivo);
			}
			
		}
	}
	fclose(arquivo);	
	return 0;
}
