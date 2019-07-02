/*
	AMANDA CARVALHEIRO DOS SANTOS		RA: 0030481721003
	GABRIELA CRISTINA MOREIRA FRANCO	RA: 0030481721009
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

#define TRUE	0
#define FALSE	1

int main(){
	char numCPF[14];
	char numFormatado[11];
	int digitosCPF[11];
	int cont, cont2, igual, invalido, digitoVerificador1, digitoVerificador2;	
	
	while(scanf("%s", numCPF), strcmp(numCPF,"000.000.000-00") != 0)
	{
		igual = 0;
		digitoVerificador1 = 0;
		digitoVerificador2 = 0;
		invalido = FALSE;	
		
		for(cont2 = 0, cont = 0; cont < 14; cont++)/* ------------------------------------- Formata-Retira Ponto e Traco*/
		{
			if(numCPF[cont] != '.' && numCPF[cont] != '-')
			{
				numFormatado[cont2] = numCPF[cont];			
				cont2++;
			}			
		}
		numFormatado[11] = '\0';		
		
		
		for(cont = 1; cont <= 10; cont++)/* ------------------------------------------------- Verificao Numeros Iguais*/
		{
			if(numFormatado[cont-1] == numFormatado[cont])
				igual++;	
		}	
		if(igual == 10)
			invalido = TRUE;		
			
		if(invalido != TRUE)
		{			
			for(cont = 0; cont < 11; cont++)/* ------------------------------------------------ Caracter para Inteiro*/
				digitosCPF[cont] = numFormatado[cont] - '0';		
			digitosCPF[11] = '\0';
			
			
			//1)Validação primeiro digito verificador
			for(cont2 = 1, cont = 0; cont < 9; cont++, cont2++)
				digitoVerificador1 = digitoVerificador1 + cont2 * digitosCPF[cont];
					
			digitoVerificador1 = digitoVerificador1 % 11;
			if(digitoVerificador1 == 10)
				digitoVerificador1 = 0;
				
			//2)Validação segundo digito verificador
			for(cont2 = 11, cont = 0; cont < 10; cont++, cont2--)
			{
				digitoVerificador2 = digitoVerificador2 + cont2 * digitosCPF[cont];
					
			}
			digitoVerificador2 = (digitoVerificador2 * 10) % 11;
			if(digitoVerificador2 == 10)
				digitoVerificador2 = 0;
		}
				
		if(invalido == TRUE)
			printf("CPF Informado Invalido\n");
		else if(digitoVerificador1 != digitosCPF[9] || digitoVerificador2 != digitosCPF[10])
			printf("Invalido -Esperado: %d%d, Encontrado: %d%d\n", digitoVerificador1, digitoVerificador2, digitosCPF[9], digitosCPF[10]);
		else
			printf("Valido\n");
	}
	
return 0;
}