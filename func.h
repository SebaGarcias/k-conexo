typedef struct graph{
    int ready;

    int V; // Cantidad de vértices
    int E; // Cantidad de aristas
    int** ady;

}graph;

int readGraph(graph*,char*);
void printAdyGraph(graph*);
void clearGraph(graph*);
int kconexo(graph*,int);
int conexo(graph*);
int grade(graph*, char[3]);
