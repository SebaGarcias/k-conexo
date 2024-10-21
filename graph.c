#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

char buffer[] = "3\n1: 2,3\n2: 1,3\n3: 1,2";
graph* grafo;

void startGraph(){
    grafo->E = 0;

    // Se crea la lista de adyacencia
    grafo->ady = malloc(grafo->V * sizeof(int *));
    for(int i = 0; i < grafo->V; i++){
	grafo->ady[i] = malloc(grafo->V * sizeof(int));
	*(grafo->ady[i]) = 0;
    }
}

int readGraph(graph* aux){
    grafo = aux;

    grafo->V = buffer[0]- '0';
    startGraph();


    return 0;
}
