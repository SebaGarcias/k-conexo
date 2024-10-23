#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

graph* grafo;
char* buffer;

int setEdge(graph* grafo, int U,int V){
    if(grafo == NULL)
	return 1;

    grafo->ady[U-1][V-1] = 1;
    if(grafo->ady[V-1][U-1] == 0){
	grafo->E++;
    }
    return 0;
}

void startGraph(){
    grafo->E = 0;

    // Se crea la lista de adyacencia
    grafo->ady = malloc(grafo->V * sizeof(int *));
    for(int i = 0; i < grafo->V; i++){
	grafo->ady[i] = malloc(grafo->V * sizeof(int));
	for (int y = 0; y < grafo->V; y++) {
	    grafo->ady[i][y] = 0;
	}
    }
}
char** auxArg;
int readGraph(graph* aux,char* b){
    buffer = malloc(strlen(b)+1);
    strcpy(buffer,b);

    grafo = aux;

    grafo->V = buffer[0] - '0';
    startGraph();


    char* ptr = strtok(buffer,"\n");
    if(ptr == NULL)
	return -1;
    auxArg = malloc(sizeof(char*)*(grafo->V+1));

    // CLEAR
    for (int i = 0; i < grafo->V +1; i++) {
	auxArg[i] = NULL;
    }

    int index = 0;
    while(ptr != NULL){
	auxArg[index] = malloc(strlen(ptr)+1);
	strcpy(auxArg[index],ptr);
	index++;

	ptr = strtok(NULL,"\n");
    }

    for (int i = 1; i < grafo->V+1; i++) {
	if(auxArg[i] == NULL)
	    break;
	char* ptr2 = strtok(auxArg[i],":");

	if(ptr2 == NULL)
	    continue;

	int inputV = atoi(ptr2);
	ptr2 = strtok(NULL,":");

	if(ptr2 == NULL)
	    continue;

	char* ptrV = strtok(ptr2,",");

	while(ptrV != NULL){
	    int adyV = atoi(ptrV);
	    setEdge(grafo,inputV,adyV);
	    ptrV = strtok(NULL,",");
	}
    }

    grafo->ready = 1;
    for (int i = 0; i < grafo->V+1; i++) {
	free(auxArg[i]);
    }
    free(auxArg);
    free(buffer);

    return 0;
}

void printAdyGraph(graph* grafo){
    if(grafo == NULL || grafo->ready == 0){
	printf("Grafo no inicializado\n");
	return;
    }

    printf("\n\nV   ");
    for (int c = 0; c < grafo->V; c++) {
	printf("%d ",c+1);
    }
    printf("\n");
    for (int f = 0; f < grafo->V; f++) {
	printf("\n%d   ",f+1);
	for (int c = 0; c < grafo->V; c++) {
	    printf("%d ",grafo->ady[f][c]);
	}
    }
    printf("\n");
}

void clearGraph(graph* grafo){
    for(int i = 0; i < grafo->V; i++){
	free(grafo->ady[i]);
    }
    free(grafo->ady);
    free(grafo);
}

int grade(graph* grafo,char type[3]){
    if(grafo == NULL || grafo->ready == 0 || (strcmp(type,"MAX") != 0 && strcmp(type,"MIN") != 0))
	return -1;

    int max = 0;
    int min = grafo->V;
    for (int v = 0; v < grafo->V; v++) {
	int aux = 0;
	for (int a = 0; a < grafo->V; a++) {
	    aux += grafo->ady[v][a];
	}

	if(max < aux)
	    max = aux;
	if(min > aux)
	    min = aux;
    }

    if(strcmp(type,"MAX") == 0)
	return max;
    else
	return min;
}
