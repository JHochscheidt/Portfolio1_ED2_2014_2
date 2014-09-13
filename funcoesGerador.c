#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoesGerador.h"
#include <time.h>

	/* definicao de constantes para caracteres e separadores tabela ascII */
		#define nChar32 32
		//#define nChar47 47
		#define zeroASCII 48
		#define noveASCII 57
		#define nChar58 58	
		//#define nChar64 64
		#define AASCII 65
		#define ZASCII 90
		#define nChar91 91	
		//#define nChar96 96
		#define aASCII 97
		#define zASCII 122	
		#define nChar123 123
		//#define nChar126 126
	
	/* ******************************************************************* */

char *geradorDeSeparador(){
	int sortChar = 0;
	char c;
	char *separador = (char*) malloc(1);
	if(!separador) return NULL;
	
	sortChar = rand() % 4;
	if(sortChar == 0) 		c = (char) (nChar32 + (rand() % 16)) ; // separadores de 32 a 47
	else if(sortChar == 1)	c = (char) (nChar58 + (rand() % 7)); // separadores de 58 a 64
	else if(sortChar == 2)	c = (char) (nChar91 + (rand() % 6)); // separadores de 91 a 96
	else 					c = (char) (nChar123 + (rand() % 4)); // separadores de 123 a 126
	
	strncat(separador,&c,1);
	return separador;
}

char *geradorDePalavra(int tamanhoW){
	int sortAlfanumerico = 0; // sort para saber se eh caracter minusculo, maiusculo ou numero.
	char c;
	char *palavra = (char*) malloc(tamanhoW);
	if(!palavra) return NULL;
	
	while(tamanhoW > 0){
		sortAlfanumerico = rand() % 3; // 0 - a ate z; 1 - A ate Z; 2 - 0 ate 9
		if(sortAlfanumerico == 0)		c = (char) aASCII + (rand() % (zASCII + 1 - aASCII));
		else if(sortAlfanumerico == 1)	c = (char) AASCII + (rand() % (ZASCII + 1 - AASCII));
		else 							c = (char) zeroASCII + (rand() % (noveASCII + 1 - zeroASCII));
		
		strncat(palavra, &c, 1);
		tamanhoW--;
	}
	return palavra;
}
