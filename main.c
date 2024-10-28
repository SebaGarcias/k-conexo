#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#include "importFile.h"
#include <time.h>

int main(void)
{
    // Iniciar el temporizador
    clock_t start_time = clock();

    // 0. Importar formato 
    char* input = importFormat();

    // 1. Formato a grafo
    graph* grafo = (graph*) malloc(sizeof(graph));
    readGraph(grafo,input);
   
    // 2. Algoritmo k-conexo k {1,2,3,4}
    kalgoritmo(grafo);
    int k1,k2,k3,k4;

    k4 = iskconexo(grafo,4);
    if(k4 == 1){
	k1=1;
	k2=1;
	k3=1;
    }
    else
	k3 = iskconexo(grafo,3);

    if(k3 == 1){
	k1=1;
	k2=1;
    }
    else
	k2 = iskconexo(grafo,2);

    if(k2 == 1){
	k1=1;
    }
    else
	k1 = iskconexo(grafo,1);
    
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
    if(k2 == 1)
	printf("\nEl grafo es 2-conexo\n");
    else
	printf("\nEl grafo NO es 2-conexo\n");
    if(k3 == 1)
	printf("\nEl grafo es 3-conexo\n");
    else
	printf("\nEl grafo NO es 3-conexo\n");
    if(k4 == 1)
	printf("\nEl grafo es 4-conexo\n");
    else
	printf("\nEl grafo NO es 4-conexo\n");

    printf("\n");

    // Finalizar el temporizador
    clock_t end_time = clock();

    // Calcular el tiempo transcurrido
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Tiempo transcurrido: %.2f segundos\n", elapsed_time);

    // 5. Liberar memoria
    clearResults();
    clearGraph(grafo);
    clearFormat();

    return 0;
}
