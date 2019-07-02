/*
	Autores: 	AMANDA CARVALHEIRO DOS SANTOS		RA: 0030481721003
				GABRIELA CRISTINA MOREIRA FRANCO	RA: 0030481721009
	
	Exercicio 3 da lista 2.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

#define	TRUE	0
#define FALSE	1

double Calcula_MetodoA();
double Calcula_MetodoB();

int main(){
	double respMetodaA, respMetodoB;
	
	respMetodaA = Calcula_MetodoA();
	respMetodoB = Calcula_MetodoB();
	printf("Metodo A: %.10lf \nMetodo B: %.10lf\n", respMetodaA, respMetodoB);
	
return 0;
}

double Calcula_MetodoA(){
	int denominador, operacao, cont;
	double soma;
	
	soma = 0;
	denominador = 1;
	operacao = FALSE;
	
	for(cont = 0; cont < 51; cont++)
	{
		if(operacao == FALSE)
		{
			soma = soma + (1/(pow(denominador, 3)));
			operacao = TRUE;			
		}
		else
		{
			soma = soma - (1/(pow(denominador, 3)));
			operacao = FALSE;
		}
		denominador = denominador + 2;
	}
	
	soma = soma * 32;
	soma = pow(soma, 1/3.0);
	return soma;
}

double Calcula_MetodoB(){
	int denominador, operacao;
	double soma;
	
	soma = 0;
	denominador = 1;
	operacao = FALSE;
	
	while(0.0001 <= 4.0/denominador)
	{
		if(operacao == FALSE)
		{
			soma = soma + 4.0 / denominador;
			operacao = TRUE;			
		}
		else
		{			
			soma = soma - 4.0 / denominador;
			operacao = FALSE;			
		}
		denominador = denominador + 2;
	}
	
	return soma;
}