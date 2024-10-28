typedef struct dot{
    int vertice;
    int eliminado;
}dot;

typedef struct graph{
    dot* v;
    int ready;

    int V; // Cantidad de vértices
    int E; // Cantidad de aristas
    int** ady;

}graph;

int readGraph(graph*,char*);
void printAdyGraph(graph*);
void clearGraph(graph*);
int iskconexo(graph*,int);
int kalgoritmo(graph*);
int conexo(graph*);
int grade(graph*, char[3]);
void clearResults();
