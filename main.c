#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main(void)
{
    graph* grafo = (graph*) malloc(sizeof(graph));

    // 0. Importar formato 

    // 1. Formato a grafo
    readGraph(grafo);
   
    // 2. Algoritmo k-conexo k {1,2,3,4}
    
    // 2.1 Quitar vértices 
    
    // 2.2 Ver si es conexo sin u 
    
    // 2.3 Devolver vértices eliminado y quitar otros 
    
    // 2.4 Ver si es conexo y repetir 2.1 
    
    // 3. Grado mínimo y máximo
     
    // 4. Imprimir resultados
    printf("%d\n",grafo->V);

    // 5. Liberar memoria
    for(int i = 0; i < grafo->V; i++){

	free(grafo->ady[i]);
    }
    free(grafo->ady);
    free(grafo);

    return 0;
}
