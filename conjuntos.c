#include <stdio.h>
#include <stdlib.h>

int factorial(int n){
    if(n == 1 || n == 0)
	return 1;

    return n * factorial(n-1);
}

int coefBinomial(int n, int m){
    return factorial(n)/(factorial(m) * factorial(n-m));
}

// Crea un conjunto que contiene desde 1 hasta n
int* conjunto(int n){
    int *aux = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
	aux[i] = i + 1;
    }

    return aux;
}

int** subconjuntoOrdenM(int* conjunto, int n,int m){
    //Formula conseguida luego de simplificar la suma de coefBinomial(n,i) para todo i e {1,2,3}
    int subTotal = (n*n*n + 5*n)/6;
    
    int** result = malloc(sizeof(int*) * (subTotal+1));
    result[0] = malloc(sizeof(int)); // GUARDAR TAMAÑO DE SUBTOTAL

    int offset = 0;
    int finalSize = 0;
    int* temp = malloc(sizeof(int)*m);
    for (int i = 0; i < subTotal + offset; i++) {
	
	for (int t = 0; t < m; t++) {
	    temp[t] = -1;
	}

        int pos = -1;
	for (int z = 0; z < n; z++) {
	    if((i+1) & (1 << z)){
		pos++;
		if(pos < m){
		    temp[pos] = conjunto[z];
		}
	    }
	}
	if(pos >= m){
	    offset++;
	    continue;
	}

	result[i-offset+1] = malloc(sizeof(int)*m);
	for (int t = 0; t < m; t++) {
	    if(temp[t] == -1)
		temp[t] = temp[t-1];
	    result[i-offset+1][t] = temp[t];
	}

	finalSize = i-offset+1;
    }
    free(temp);
    result = realloc(result,(finalSize+1)*sizeof(int*));
    result[0][0] = finalSize;
    return result;
}

void clearSubconjunto(int** sub){
    int size = sub[0][0];
    for (int i = 0; i < size +1; i++) {
	free(sub[i]);
    }
    free(sub);
}
