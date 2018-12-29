#include<stdio.h>
#include<math.h>

double expoente(double x, double eps, int maxiter){
	int iter;
	double sol, solold, num, den, ea;
	iter = 1;
	num = den = sol = ea = 1.0;
	printf("iter %d sol %e ea %e\n", iter, sol, ea);
	do{
		solold = sol;
		num *= x;
		den *= iter;
		sol += num/den;
		ea = fabs((sol-solold)/sol);
		iter++;
		printf("iter %d sol %e ea %e\n", iter, sol, ea);
	}while(ea > eps && iter < maxiter);
		
	return sol;
}

int main(){

	printf("%e\n", expoente(0.5, 0.0001, 10) );

	return 0;
}
