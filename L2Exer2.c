/*
	Autores: 	AMANDA CARVALHEIRO DOS SANTOS		RA: 0030481721003
				GABRIELA CRISTINA MOREIRA FRANCO	RA: 0030481721009
	
	Exercicio 2 da lista 2.
*/
#include <stdio.h>
#include <stdlib.h>

//Função da media 
float media (int n, float *numeros){
  int cont;
  double media, soma = 0;
  
  for (cont = 0; cont < n; cont++)
    soma = soma + numeros[cont];    
   
  media = soma / n;
   
  return media;
}

//Função da variância
float variancia(int n,double m, float *num){
	int cont2;
	double variancia, soma;
	soma = 0;
	for(cont2 = 0;cont2 < n;cont2++)
		soma = ((num[cont2] - m) * (num[cont2] - m)) + soma;
	
	variancia = soma/n;
	return variancia;
}

int main (){
	int i, qtde; 
	double media_numeros;
	double variancia_numeros;
  
	scanf("%d", &qtde);
	float numero[qtde];
	
	for (i = 0; i < qtde; i++)
		scanf("%f", &numero[i]);
   
	media_numeros = media(qtde,numero);  
	variancia_numeros = variancia(qtde,media_numeros,numero);
   
	printf("Media: %.4f       Variancia: %.4f\n", media_numeros, variancia_numeros);
 
  return 0;
}