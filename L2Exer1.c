/*
	Autores: 	AMANDA CARVALHEIRO DOS SANTOS		RA: 0030481721003
				GABRIELA CRISTINA MOREIRA FRANCO	RA: 0030481721009
	
	Exercicio 1 da lista 2.
*/
#include<stdio.h>

#define TRUE 0
#define FALSE 1

//Função descobre se é numero primo
int primo (int numero) {
	int cont;
	
	if(numero == 0 || numero == 1)
		return 0;
	if(numero == 2)
		return 1;
	for(cont = 2; cont < numero; cont++) {
		if (numero % cont != 0)
			continue;
		else 
			return 0;
	}
	return 1;
}

//Função descobre se é numero triangular
int triangular(int numero){
	int cont, numTriangular;
	
	numTriangular = 1;
	
	for(cont = 2;numTriangular < numero;cont++)
		numTriangular = numTriangular + cont;
	if(numero == numTriangular)
		return TRUE;
	else
		return FALSE;
}

//Função descobre se é fibonacci e de que posição
int fibonacci(int numero){
    
    if(numero == 0) 
		return 0;
    if(numero == 1) 
		return 1;
    else 
		return fibonacci(numero - 1) + fibonacci(numero - 2);
}
int main(){
	int numero, nPrimo, nTriangular, nFibonacci;	
	
	while(scanf("%d", &numero), numero != -999){
		nPrimo = primo(numero);
		nTriangular = triangular(numero);
		nFibonacci = fibonacci(numero);
		
		if(nPrimo == 1)
			printf("O número é primo\n");	
		else
			printf("O número não é primo\n");
		
		if(nTriangular == FALSE)
			printf("O número não é triangular\n");
		else
			printf("O número é triangular\n");
		if(nFibonacci == 0)
			printf("O número não é fibonacci\n");
		else
			printf("O número é Fibonacci, e ele é o termo: %d\n", fibonacci(numero));
	}	
	return 0;
}