#include <stdio.h>
#include <stdlib.h>

//Prototipo de funciones
void generarTriangulo(int);


int main(){
	int n; 

	printf("%s\n", "Ingrese el nro de elementos");
	scanf("%d", &n);

	generarTriangulo(n);

	return 0;

}

void generarTriangulo(int n){
	
	int **matriz;
	int k,j;
	
	//Asignamos un puntero a la primera posicion de la matriz
	matriz = calloc(n, sizeof(int *));

  //Si no se pudo crear espacio en momeria
	if (matriz == NULL) exit(1);


	//Recorrer la memoria en base a la cantidad de elementos
	for (k = 0; k <= n; k++) {
		*(matriz + k) = calloc( k, sizeof(int));
		if (*(matriz + k) == NULL) exit(1);
	}

	//Agisna los datos al triangulo
	for (j = 0; j <= n; j++) {
		for (k = 0; k <= j; k++){
		 	if (k == 0 || j == k) { 
            	matriz[k][j] = 1; 
            } else { 
            	matriz[k][j] = (matriz[k][j - 1] + matriz[k - 1][j - 1]); 
            } 
		}
	}


	//Imprime triangulo
	for (j = 0; j <= n; j++) {
		for (k = 0; k <= j; k++) 
			printf("%hd\t", matriz[k][j]);
			putchar('\n');
	}


}


