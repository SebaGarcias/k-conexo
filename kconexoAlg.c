#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#include "conjuntos.h"

graph* deleteV(graph* grafo, int x, int y, int z){
    graph* aux = malloc(sizeof(graph));
    aux->v = malloc(sizeof(dot)*grafo->V);

    int eliT = 0;
    for (int i = 0; i < grafo->V; i++) {
	aux->v[i].vertice = i+1;

	if(i == x || i == y || i == z){
	    aux->v[i].eliminado = 1;
	    eliT++;
	}
	else
	    aux->v[i].eliminado = 0;
    }
    aux->V = grafo->V - eliT;
    aux->ady = malloc(sizeof(int *) * aux->V);
    int auxX = 0;
    aux->ady[0] = malloc(sizeof(int)*aux->V);
    for (int x = 0; x < grafo->V; x++) {
	if(aux->v[x].eliminado == 1)
	    continue;

	int temp = 0;
	for (int y = 0; y < aux->V; y++) {
	    while(aux->v[y+temp].eliminado == 1){
		temp++;
	    }
	    aux->ady[auxX][y] = grafo->ady[x][y+temp];
	}
	auxX++;
	if(auxX == aux->V)
	    break;
	aux->ady[auxX] = malloc(sizeof(int)*aux->V);
    }

    aux->ready = 1;
    free(aux->v);
    return aux;
}

int** resultadoKConexidad;
// 1 Es k-conexo | 0 no es kconexo | -1 es un fallo
int iskconexo(graph* grafo,int k){
    if(resultadoKConexidad == NULL)
	return -1;

    if(k >= grafo->V)
	return -1;

    if(k == 1)
	return conexo(grafo);

    int totalSubC = resultadoKConexidad[0][0];
    for (int s = 1; s < totalSubC; s++) {
	int v1 = resultadoKConexidad[s][0];
	int v2 = resultadoKConexidad[s][1];
	int v3 = resultadoKConexidad[s][2];
	int estado = resultadoKConexidad[s][3];

	if(estado == -1)
	    continue;

	switch (k) {
		case 2:
		    if(v1 == v2 && v2 == v3 && estado == 0)
			return 0;
			break;
		case 3:
		    if(v1 != v2 && v2 == v3 && estado == 0)
			return 0;
			break;
		case 4:
		    if(v1 != v2 && v2 != v3 && v1 != v3 && estado == 0)
			return 0;
			break;
	}
    }
    return 1;
}

int kalgoritmo(graph* grafo){
    int* conjVertices = conjunto(grafo->V);
    int** subConjVert = subconjuntoOrdenM(conjVertices,grafo->V,3);

    // Conjunto que contiene los subconjuntos hasta tamaño 3 -> {-1,0,1} Es conexo o no, sin estos vertices |-1 si no fue asignado su estado
    int cantSubConj = subConjVert[0][0];
    for (int i = 1; i < cantSubConj; i++) {
	int v1 = subConjVert[i][0]-1;
	int v2 = subConjVert[i][1]-1;
	int v3 = subConjVert[i][2]-1;
	// Representa el estado de esos vértices
	subConjVert[i][3] = -1;

	graph* gmod = deleteV(grafo,v1,v2,v3);
	subConjVert[i][3] = conexo(gmod);
	for (int i = 0; i < gmod->V; i++) {
	    free(gmod->ady[i]);
	}
	free(gmod->ady);
	free(gmod);
    }
    free(conjVertices);
    resultadoKConexidad = subConjVert;
}

void clearResults(){
    clearSubconjunto(resultadoKConexidad);
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
