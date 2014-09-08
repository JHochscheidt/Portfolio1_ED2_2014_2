#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoesGerador.h"
#include <time.h>

	/* definicao de constantes para caracteres e separadores tabela ascII */
		#define nChar0 0
		#define nChar47 47
		#define zeroASCII 48
		#define noveASCII 57
		#define nChar58 58	
		#define nChar64 64
		#define AASCII 65
		#define ZASCII 90
		#define nChar91 91	
		#define nChar96 96
		#define aASCII 97
		#define zASCII 122	
		#define nChar123 123
		#define nChar255 255
		#define tableASCII 256
	
	/* ******************************************************************* */

char *geradorDeSeparador(char *texto){
	int teste = rand() % 4;
	char c;
	
	if(teste == 0) 		c = (char) rand() % (nChar47 + 1) ; // separadores de 0 a 47
	else if(teste == 1)	c = (char) nChar58 + (rand() % (nChar64 + 1 - nChar58)); // separadores de 58 a 64
	else if(teste == 2) c = (char) nChar91 + (rand() % (nChar96 + 1 - nChar91)); // separadores de 91 a 96
	else 				c = (char) nChar123 + (rand() % (nChar255 + 1 - nChar123)); // separadores de 123 a 255
	
	strncat(texto,&c,1);
	//printf("\n separador %c  \n", c );
	return texto;
}

char *geradorDePalavra(int tamanhoW ,char *texto){
	
	int sortAlfanumerico; // sort para saber se eh caracter minusculo, maiusculo ou numero.
	char c;
	
	while(tamanhoW > 0){
		sortAlfanumerico = rand() % 3; // 0 - a ate z; 1 - A ate Z; 2 - 0 ate 9
		if(sortAlfanumerico == 0)		c = (char) aASCII + (rand() % (zASCII + 1 - aASCII));
		else if(sortAlfanumerico == 1)	c = (char) AASCII + (rand() % (ZASCII + 1 - AASCII));
		else 							c = (char) zeroASCII + (rand() % (noveASCII + 1 - zeroASCII));
		//printf("\n SORT %d \t CHAR %c", sortAlfanumerico, c);		
		strncat(texto, &c, 1);
		tamanhoW--;
	}
	return texto;
}


