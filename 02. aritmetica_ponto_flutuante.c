//serve para encontrar o numero de digitos significativos

#include<stdio.h>

int main(){
	double eps = 1.0, eps1;
	do{
		eps = eps/2.0;
		eps1 = eps + 1.0;
	}while(eps1 > 1.0);
	printf("O seguinte valor vale zero \n");
	printf("%e \n", eps);
	
	return 0;
}
