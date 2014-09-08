	#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funcoesGerador.c"

int main(int argv , char **argc){
	srand(time(NULL)); // gera "semente" de acordo com a hora atual em segundos
	
	/*
	printf("%s \n", argc[0]); // gerador
	printf("%s \n", argc[1]); // SIZE of file
	printf("%s \n", argc[2]); // number of words 
	printf("%s \n", argc[3]); // number min of character for word
	printf("%s \n", argc[4]); // number max of character for word
	printf("%s \n", argc[5]); // name of archive 
	*/
	
	unsigned int sizeFile = atoi(argc[1]);
	printf("\n sizeFile --> %i ", sizeFile);
		
	unsigned int numWords = atoi(argc[2]);
	printf("\t numWords --> %i ", numWords);
	
	unsigned int minW = atoi(argc[3]);
	printf("\t minW --> %i ", minW);
	
	unsigned int maxW = atoi(argc[4]);
	printf("\t maxW --> %i ", maxW);
	
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
	
	
	int sizeFileTemp = 0;
	int tamanhoMaxWord = 0;
	int tamanhoWord = 0;
	
	char *texto = (char*) malloc(sizeFile);
	
	int contLaco = 0;
	
	arquivo = fopen(nameArchive, "a+");
	
	while(sizeFile > sizeFileTemp && numWords > 0){
		tamanhoMaxWord = (sizeFile - sizeFileTemp) / (numWords * 2);
		printf("TAMANHO MAX WORD %d \n", tamanhoMaxWord);
		if(tamanhoMaxWord >= maxW){
			tamanhoMaxWord = maxW;
		}
		tamanhoWord = minW + (rand() % (tamanhoMaxWord - minW));
		printf("TAMANHO DA WORD %d \n", tamanhoWord);
		texto = geradorDePalavra(tamanhoWord, texto);
		sizeFileTemp = sizeFileTemp + tamanhoWord;
		if(sizeFileTemp < sizeFile && numWords > 0){
			texto = geradorDeSeparador(texto);
			sizeFileTemp++;
		}
		printf("cont laco %d", contLaco);
		contLaco++;			
		numWords--;
		if(numWords == 0 && sizeFile > sizeFileTemp){
			while(sizeFile > sizeFileTemp){
				texto = geradorDeSeparador(texto);
				printf("laco separador %d", sizeFileTemp);
				sizeFileTemp++;
			}
		}
		printf("texto gerado a cada laco %s \n\n", texto);
	}
	fprintf(arquivo, "%s", texto);
	printf("texto gerado %s \n", texto);
	fclose(arquivo);
	
	
	
	return 0;
}
