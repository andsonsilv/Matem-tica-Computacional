#include<stdio.h>
#include<math.h>

float maximo(int n, float vetor[10]){
	float max = vetor[1];	
	for(int i = 2; i <= n; i++){
		if(fabs(vetor[i]) >= max){
			max = fabs(vetor[i]);
		}
	} 
	return max;
}

int main(){

	int k = 1,n, iteracao;
	

	float a[10][10],x[10], e;

	float soma, temp, erro, maior;
	//temp é o x' temporário, lembrei do processo iterativo para saber calcular
	//erro é o erro, precisão 

	scanf("%d",&n) ;

	//Introduce los coeficientes de las ecuaciones
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n+1; j++){
			scanf("%f",&a[i][j]);
		}
	}

	//vetor base, necessário para fazer o x'^(k+1)
	float aux = 0.0;
	for(int i = 1; i <= n; i++){
		scanf("%f",&aux);		
		x[i] = aux;
	}
	scanf("%f", &e);
	scanf("%d", &iteracao);
	float max;

	//processo interativo
	do{
		printf("ITERACAO %d",k);			
		maior = 0;
		max = maximo(n, x);
		for(int i = 1; i <= n; i++){
			soma = 0;
			for(int j = 1; j <= n; j++){
				if(j != i){
					soma = soma + a[i][j] * x[j];
				}
			}
			temp = (a[i][n+1]-soma) / a[i][i];
			erro = fabs(x[i] - temp);
			if(erro > maior){
				maior = erro;
			}
			x[i] = temp;
			printf("\nx[%d] = %f ", i-1, x[i]);
		}
		printf("\n");
		k++;
	}while(((maior/max) > e) || ((k-1) == iteracao));
	

 	return 0;

} 
