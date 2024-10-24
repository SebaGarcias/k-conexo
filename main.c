#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#include "importFile.h"

int main(void)
{
    // 0. Importar formato 
    char* input = importFormat();

    // 1. Formato a grafo
    graph* grafo = (graph*) malloc(sizeof(graph));
    readGraph(grafo,input);
   
    // 2. Algoritmo k-conexo k {1,2,3,4}
    int k1 = kconexo(grafo,1);
    //int k2 = kconexo(grafo,2);
    //int k3 = kconexo(grafo,3);
    //int k4 = kconexo(grafo,4);
    
    // 3. Grado mínimo y máximo
    int gradoMax = grade(grafo,"MAX"); 
    int gradoMin = grade(grafo,"MIN"); 

    // 4. Imprimir resultados
    
    printf("\nLa cantidad de vertices: %d",grafo->V);
    printf("\nLa cantidad de aristas: %d",grafo->E);
    printf("\nGrado minimo: %d",gradoMin);
    printf("\nGrado maximo: %d",gradoMax);
    printAdyGraph(grafo);

    if(k1 == 1)
	printf("\nEl grafo es 1-conexo\n");
    else
	printf("\nEl grafo NO es 1-conexo\n");

    // 5. Liberar memoria
    clearGraph(grafo);
    clearFormat();

    return 0;
}
