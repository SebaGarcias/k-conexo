#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#include "importFile.h"

int main(void)
{

    // 0. Importar formato 
    char* input = importFormat();
    printf("%s\n",input);

    // 1. Formato a grafo
    graph* grafo = (graph*) malloc(sizeof(graph));
    readGraph(grafo,input);
   
    // 2. Algoritmo k-conexo k {1,2,3,4}
    
    // 2.1 Quitar vértices 
    
    // 2.2 Ver si es conexo sin u 
    
    // 2.3 Devolver vértices eliminado y quitar otros 
    
    // 2.4 Ver si es conexo y repetir 2.1 
    
    // 3. Grado mínimo y máximo
    int gradoMax = grade(grafo,"MAX"); 
    int gradoMin = grade(grafo,"MIN"); 

    // 4. Imprimir resultados
    
    printf("\nLa cantidad de vertices: %d",grafo->V);
    printf("\nLa cantidad de aristas: %d",grafo->E);
    printf("\nGrado minimo: %d",gradoMin);
    printf("\nGrado maximo: %d",gradoMax);
    printAdyGraph(grafo);

    // 5. Liberar memoria
    clearGraph(grafo);
    clearFormat();

    return 0;
}
