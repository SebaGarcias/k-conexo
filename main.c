#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main(void)
{
    graph* grafo = (graph*) malloc(sizeof(graph));
    char* input = "5\n1:2,3,5\n2:1,4\n3:1,5\n4:2\n5:1,3";

    // 0. Importar formato 

    // 1. Formato a grafo
    readGraph(grafo,input);
   
    // 2. Algoritmo k-conexo k {1,2,3,4}
    
    // 2.1 Quitar vértices 
    
    // 2.2 Ver si es conexo sin u 
    
    // 2.3 Devolver vértices eliminado y quitar otros 
    
    // 2.4 Ver si es conexo y repetir 2.1 
    
    // 3. Grado mínimo y máximo
     
    // 4. Imprimir resultados
    
    printf("\nLa cantidad de vertices: %d",grafo->V);
    printf("\nLa cantidad de aristas: %d",grafo->E);
    printAdyGraph(grafo);

    // 5. Liberar memoria
    clearGraph(grafo);

    return 0;
}
