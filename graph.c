#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

char buffer[] = "3\n1: 2,3\n2: 1,3\n3: 1,2";
graph* grafo;

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
	    (grafo->ady[i])[y] = 0;
	}
    }
}
char** auxArg;
int readGraph(graph* aux){
    grafo = aux;

    grafo->V = buffer[0] - '0';
    startGraph();


    char* ptr = strtok(buffer,"\n");
    auxArg = malloc((sizeof(char*)*grafo->V)+1);

    int index = 0;
    while(ptr != NULL){
	auxArg[index] = malloc(strlen(ptr)+1);
	strcpy(auxArg[index],ptr);
	index++;

	ptr = strtok(NULL,"\n");
    }

    for (int i = 1; i < grafo->V+1; i++) {
	char* ptr2 = strtok(auxArg[i],":");
	int inputV = atoi(ptr2);
	ptr2 = strtok(NULL,":");

	if(ptr2 == NULL)
	    break;
	char* ptrV = strtok(ptr2,",");

	while(ptrV != NULL){
	    int adyV = atoi(ptrV);
	    setEdge(grafo,inputV,adyV);
	    ptrV = strtok(NULL,",");
	}
    }

    grafo->ready = 1;

    return 0;
}

void printAdyGraph(graph* grafo){
    if(grafo == NULL || grafo->ready == 0){
	printf("Grafo no inicializado\n");
	return;
    }

    printf("\n\nV   ");
    for (int c = 0; c < grafo->E; c++) {
	printf("%d ",c+1);
    }
    printf("\n");
    for (int f = 0; f < grafo->V; f++) {
	printf("\n%d   ",f+1);
	for (int c = 0; c < grafo->E; c++) {
	    printf("%d ",grafo->ady[f][c]);
	}
    }
}

void clearGraph(graph* grafo){
    for(int i = 0; i < grafo->V; i++){
	free(auxArg[i]);
	if(i == grafo->V - 1)
	    free(auxArg[i+1]);

	free(grafo->ady[i]);
    }
    free(auxArg);
    free(grafo->ady);
    free(grafo);
}
