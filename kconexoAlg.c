#include <stdio.h>
#include <stdlib.h>
#include "func.h"

// 1 Es k-conexo y 0 no es kconexo
int kconexo(graph* grafo, int k){
    if(k == 1)
	return conexo(grafo);
    
    // 2.1 Quitar vértices 
    
    // 2.2 Ver si es conexo sin u 
    
    // 2.3 Devolver vértices eliminado y quitar otros 
    
    // 2.4 Ver si es conexo y repetir 2.1 
    conexo(grafo);
    
    return 1;
}

int filaXColumna(int size,int f, int c,int** vf,int** vc){
    int aux = 0;
    for (int i = 0; i < size; i++) {
	aux += vf[i][f] * vc[c][i];
    }

    return aux;
}
int** multMatrizCuadradas(int** A,int** B, int size){
    if(A == NULL || B == NULL)
	return NULL;

    // RESERVAMOS LA MEMORIA Y SET EN 0
    int** aux = malloc(sizeof(int*)*size);
    for (int i = 0; i < size; ++i) {
	aux[i] = malloc(sizeof(int)*size);
	for (int y = 0; y < size; y++) {
	    aux[i][y] = 0;
	}
    }

    for (int i = 0; i < size; ++i) {
	for (int y = 0; y < size; y++) {
	    aux[i][y] = filaXColumna(size,y,i,A,B);
	}
    }

    return aux;
}

// 1 Es conexo y 0 no es conexo
int conexo(graph* grafo){
    if(grafo->ready == 0)
	return -1;

    int resultado = 1;
    int*** adyM = malloc(sizeof(int**)*(grafo->V));
    adyM[0] = grafo->ady;
    for (int s = 1; s < grafo->V; s++) {
	adyM[s] = multMatrizCuadradas(adyM[s-1],grafo->ady,grafo->V);
    }

    for (int x = 0; x < grafo->V && !(resultado == 0); x++) {
	for (int y = 0; y < grafo->V; y++) {

	    int aux = 0;
	    for (int s = 0; s < grafo->V; s++) {
		aux += adyM[s][x][y];
	    }

	    if(aux == 0){
		resultado = 0;
		break;
	    }
	}
    }

    for (int s = 1; s < grafo->V; s++) {
	for (int x = 0; x < grafo->V; x++) {
	    free(adyM[s][x]);
	}
	free(adyM[s]);
    }

    free(adyM);

    return resultado;
}
