#include<stdlib.h>
#include<stdio.h>
#include<math.h>
int main()
{
        float **matrizAumentada,*temp, elemDiagonal, soma, multiplicador;
        int i,j,k,n,pivo;

        scanf("%d",&n);
//alocação de memória
        matrizAumentada = (float**)malloc(n*sizeof(float*));
        for(i = 0; i < n; i++)
            matrizAumentada[i] = (float*)malloc(n*sizeof(float));
        temp = (float*)malloc(n*sizeof(float));
//pegar elementos da matriz
        for(i = 0; i < n; i++)
            for(j = 0; j <=n; j++)
                scanf("%f",&matrizAumentada[i][j]);
//gerando a matriz escalar
       for(i = 0; i < n; i++){
            elemDiagonal = matrizAumentada[i][i];
//inicializando o pivo
            pivo = i;
//a partir do elemDiagonal, comparar qual maior elemento da coluna
            for(k = i+1; k < n; k++)
           	 if(fabs(elemDiagonal) < fabs(matrizAumentada[k][i])){
              	 elemDiagonal = matrizAumentada[k][i] ;
              	 pivo = k;
            }
//swaping da linha do maior elemento com a linha do elemDiagonal 
            for(j = 0; j <= n; j++){
                temp[j] = matrizAumentada[pivo][j];
                matrizAumentada[pivo][j] = matrizAumentada[i][j];
                matrizAumentada[i][j] = temp[j];
            }
//calculando matriz triangular
            for(j = (i+1) ;j < n; j++){
                multiplicador = matrizAumentada[j][i]/matrizAumentada[i][i];
                for(k = 0; k <= n; k++)
                    matrizAumentada[j][k] -= multiplicador*matrizAumentada[i][k];
            }
       }
//calculando valores das incognitas
        for( i = n-1; i >= 0; i--){
            soma = 0;
            for(j = i+1; j < n; j++)
                soma += matrizAumentada[i][j]*temp[j];
            temp[i] = (matrizAumentada[i][n]-soma)/matrizAumentada[i][i];
        }
        
        for( i = 0; i < n; i++){
            for(j = 0; j <= n; j++)
                printf("%.5f ",matrizAumentada[i][j]);
            printf("\n");
        }

        for(i = 0; i < n; i++)
        	printf("x[%d] = %.5f\n",i, temp[i]);
//desalocando memoria
        for(i = 0; i < n; i++)
            free(matrizAumentada[i]);
        free(matrizAumentada);
        free(temp);

    return 0;

}
