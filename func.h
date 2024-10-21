typedef struct graph{
    int V; // Cantidad de vértices
    int E; // Cantidad de aristas

    int** ady;

}graph;

int readGraph(graph*);
