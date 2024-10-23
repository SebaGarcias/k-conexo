#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "importFile.h"

FILE* fptr;
char* result;

char* importFormat()
{
    fptr = fopen(RUTA_ARCHIVO,"r");
    result = malloc(BUFFER);

    if(fptr == NULL){
	printf("No se encontró el archivo\n");
	return NULL;
    }

    char aux = fgetc(fptr);
    int scale = BUFFER;
    int iter = 0;
    int temp = 0;
    while(!feof(fptr)){
	for (int i = 0; i < BUFFER; i++) {
	    if(aux == EOF)
		break;
	    temp = i+iter*BUFFER;
	    result[temp] = aux;
	    aux = fgetc(fptr);
	}
	iter++;
	scale*=2;
	if(!feof(fptr)){
	    result = realloc(result,scale+1);
	}
	else{
	    result[temp+1] = '\0';
	    result = realloc(result,temp+2);
	}
    }

    return result;
}

void clearFormat(){
    free(result);
    fclose(fptr);
}
