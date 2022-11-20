#include <stdio.h>
#include <stdlib.h>

void alocaMatriz(float ***matriz, int n, int inicial){
	*matriz = (float**)malloc(n*sizeof(float*));
	for(int i = 0; i < n; i++){
			(*matriz)[i] = (float*)malloc(n*sizeof(float));
			for(int j = 0; j < n; j++){
				(*matriz)[i][j] = inicial;
			}
		}
}

void fillMatrix(float ***matriz, int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			(*matriz)[i][j] = 0.0;
		}
	}
}

void imprimeMatrix(float ***matriz, int n){
	printf("\nMatriz: \n");
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			printf("%1.f ", (*matriz)[i][j]);
		}
		printf("\n");
	}
}

void freeMatrix(float ***matriz, int n){
	for(int i = 0; i < n; i++){
		free((*matriz)[i]);
	}
	free(*matriz);
}

int main(){
	int n;
	float **matriz;
	printf("Digite um valor que representara o numero de linhas e colunas de uma matriz quadrada: ");
	scanf("%d", &n);
	alocaMatriz(&matriz, n, 1.2);
	fillMatrix(&matriz, n);
	imprimeMatrix(&matriz, n);
	freeMatrix(&matriz, n);
	return 0;
}