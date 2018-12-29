#include <stdio.h>
#include <stdlib.h>


int main(){

	int n = 0;
	printf("----------------------------------------------------------------------\n");
	printf("Matematica Computacional\n");
	printf("Programa simples para resolver sistema pelo metodo de Gauss\n");
	printf("Digite o numero de variaveis do sistema:\n");
	scanf("%d",&n);
	float A[n][n+1];
	float x[n];
	float termo;
	float aux;
	printf("Digite os valores dos coeficientes e termos independentes do sistema\n");
	for(int i = 0; i < n; i++){
		for(int j = 0; j < (n+1); j++){
			printf("Valor do termo A(%d,%d)\n",i+1,j+1);
			scanf("%f",&A[i][j]);
		}		
	}
	printf("Matriz A:\n\n");
	for(int i = 0; i < n; i++){
		for(int j = 0; j < (n+1); j++){
			printf ("%f",A[i][j]);
			if(j ==n) printf("\n");
			else printf("\t");
		}
	}

	/* IMPLEMENTAÇÃO MÉTODO DE GAUSS */
	for(int k = 0; k <( n-1); k++){
		for(int i = (k+1); i < n; i++){
		/* MULTIPLICADORES*/
		aux = -1*(A[i][k]/A[k][k]);
			for(int j = 0; j < (n+1);j++){
				A[i][j]=(A[k][j]*aux)+A[i][j];
			}
		}
	printf("\n");
	printf("Matriz A Transformada em Gauss:\n\n");
		for(int i = 0; i < n; i++){
			for(int j = 0; j < (n+1); j++){
			printf("%f",A[i][j]);
			if(j==n) printf("\n");
			else printf("\t");
			}
		}
	}
	/* RESOLVENDO O SISTEMA */
	for(int i = 0; i < n; i++){
		termo = 0;
		int l = n-i;
		for(int j = l; j < n; j++){
			termo = termo + (x[j]*A[n-i-1][j]);
		}
	printf("\n");
	printf("termo = %f\n",termo);
	x[n-i-1] = (A[n-1-i][n]-termo) / A[n-i-1][n-i-1];
	printf("\n");	
	printf("Variavel: \n x %d = %13.2f\n",n-i,x[n-i-1]);
	}
	
	return 0;

}
