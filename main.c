#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#include "importFile.h"
#include <time.h>

clock_t start_time;
int Consulta4(graph* grafo){
    // Iniciar el temporizador
    start_time = clock();

    // 2. Algoritmo k-conexo k {1,2,3,4}
    kalgoritmo(grafo);
    int k1,k2,k3,k4;

    k4 = iskconexo(grafo,4);
    if(k4 == 1)
	return 4;
    else
	k3 = iskconexo(grafo,3);

    if(k3 == 1)
	return 3;
    else
	k2 = iskconexo(grafo,2);

    if(k2 == 1)
	return 2;
    else
	k1 = iskconexo(grafo,1);

    if(k1 == 1)
	return 1;

    return -1;
} 

int main(void)
{
    // Imprimir interacciones
    printf("\n| Análsis de la conectividad en grafos |");

    // 0. Importar formato 
    char* input = importFormat();

    // 1. Formato a grafo
    graph* grafo = (graph*) malloc(sizeof(graph));
    readGraph(grafo,input);
    printf("\nGrafo importado, ruta: %s",RUTA_ARCHIVO);

    // 1.5 Print opciones usuario
    int consulta = -1;
    int k = -1;
    int con = -1;
    char comando[] = "\n0. Cerrar programa\n1. Grado máximo\n2. Grado mínimo\n3. Conexidad\n4. K-Conexo\n5. Matriz Adyacencia\n6. Cantidad de aristas\n7. Cantidad de vértices\n8. COMANDOS\n9. LIMPIAR PANTALLA\n";
    printf("%s",comando);
    while(consulta == -1){

	printf("\n| Ingrese comando: ");
	int result = scanf("%d",&consulta);
	while(result != 1){
	    while (getchar() != '\n');
	    printf("\n| Ingrese comando: ");
	    result = scanf("%d",&consulta);
	}

	switch(consulta){
	    case 0:
	    	break;
	    case 1:
		int gradoMax = grade(grafo,"MAX"); 
		printf("\nGrado maximo: %d\n",gradoMax);
	    	break;
	    case 2:
		int gradoMin = grade(grafo,"MIN"); 
		printf("\nGrado minimo: %d\n",gradoMin);
	    	break;
	    case 3:
	    	if(con == -1)
		    con = conexo(grafo);
		if(con == 1)
		    printf("\nEl grafo es conexo!\n");
		else
		    printf("\nEl grafo no es conexo!\n");
	    	break;
	    case 4:
	    	if(k == -1){
		    k = Consulta4(grafo);
		    clock_t end_time = clock();
		    // Calcular el tiempo transcurrido
		    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
		    printf("\nTiempo transcurrido: %.2f segundos\n", elapsed_time);
		}

		for(int i = k; i >= 1;i--){
		    if(k != -1)
			printf("\nEl grafo es %d-Conexo!\n",i);
		    else
			printf("\nEl grafo no tiene k-conexidad para k e {1,2,3,4}\n");
		}
	    	break;
	    case 5:
		printAdyGraph(grafo);
	    	break;
	    case 6:
		printf("\nLa cantidad de aristas: %d\n",grafo->E);
	    	break;
	    case 7:
		printf("\nLa cantidad de vertices: %d\n",grafo->V);
	    	break;
	    case 8:
		printf("%s\n",comando);
	    	break;
	    case 9:
		// Limpiar la pantalla
		    system("clear");
		break;
	    default:
		consulta = -1;
	    	break;
	}

	if(consulta == 0)
	    break;
	else
	    consulta = -1;
    }

    // 5. Liberar memoria
    if(k != -1)
	clearResults();
    clearGraph(grafo);
    clearFormat();

    return 0;
}
