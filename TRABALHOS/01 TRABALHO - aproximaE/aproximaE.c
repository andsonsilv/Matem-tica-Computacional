#include<stdio.h>

int main(void){
	/* para N = 0, não existe erro relativo */	
	int N = 0;
	double f, EAnt = 1.0;
	for(int i = 1; i <= N; i++){
		f = 1;
		for(int j = 1; j <= i; j++){
			f = f * j;
		}
		EAnt = EAnt + 1.0/f;
	}
	

	/* para outros N, a ideia é ir salvando os erros relativos e comparando com variavel ErrRelM */

	double ErrRelM, ErrRel;
	scanf("%lf", &ErrRelM);
	int controle = 0; 
	N = 1;
	while(controle == 0){
		double E = 1.0;
		for(int i = 1; i <= N; i++){
			f = 1;
			for(int j = 1; j <= i; j++){
				f = f * j;
			}
			E = E + 1.0/f;
		}

		ErrRel = (E - EAnt)/E;

		
		if(ErrRel < ErrRelM){
			controle = 1;
			printf("%.15lf\n", E);
		}else{
			EAnt = E;
			N++;
		}

	}
	return 0;
}
