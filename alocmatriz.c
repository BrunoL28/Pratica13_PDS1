#include <stdio.h>
#include <stdlib.h>

void fillMatrix(float **matriz, int n){
	int i = 0, j = 0;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			matriz[i][j] = 0.0;
		}
	}
}

void imprimeMatrix(float **matriz, int n){
	int i = 0, j = 0;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf("%1.f ", matriz[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int n;
	printf("Digite um valor que representara o numero de linhas e colunas de uma matriz quadrada: ");
	scanf("%d", &n);
	float **matriz;
	matriz = (float**)malloc(n*sizeof(float*));
	int i = 0;
	for(i = 0; i < n; i++){
			matriz[i] = (float*)malloc(n*sizeof(float));
		}
	fillMatrix(matriz, n);
	printf("\nMatriz: \n");
	imprimeMatrix(matriz, n);
	for(i = 0; i < n; i++){
		free(matriz[i]);
	}
	free(matriz);
	return 0;
}