/*
	Autores: 	AMANDA CARVALHEIRO DOS SANTOS		RA: 0030481721003
				GABRIELA CRISTINA MOREIRA FRANCO	RA: 0030481721009
	
	Exercicio 4 da lista 2.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

#define TRUE	0
#define FALSE	1

int* Converte_Numero(char*, int*);
int Verifica_NumerosIguais(int*);
int Verifica_PrimeiroDigito(int*);
int Verifica_SegundoDigito(int*);

struct registro{
	int codigo;
	char nome[21];
	char stringCPF[15];
	char sexo, estadoCivil;	
};

int main(){
	FILE *arquivo;
	struct registro aluno;
	int numeroCPF[11];
	int* posicaoCPF;	
	int numerosIguais, primeiroDigito, segundoDigito;
		
	arquivo = fopen ("Alunos02.dat", "r");
	
	if (arquivo == NULL)
    {
        printf("Nao foi possivel abrir o arquivo!\n");
        return 0;
    }
	
	while(fread(&aluno, sizeof(struct registro), 1, arquivo))
	{
		posicaoCPF = Converte_Numero(aluno.stringCPF, numeroCPF);
		numerosIguais = Verifica_NumerosIguais(posicaoCPF);
			
		if(numerosIguais == TRUE)
			printf("CPF INVALIDO - TODOS OS DIGITOS REPETIDOS\n");
		else
		{
			primeiroDigito = Verifica_PrimeiroDigito(posicaoCPF);
			segundoDigito = Verifica_SegundoDigito(posicaoCPF);
				
			if(primeiroDigito == numeroCPF[9] && segundoDigito == numeroCPF[10])
				printf("CPF VALIDO\n");
			else
			{
				printf("CPF INVALIDO - ESPERADO: %d%d\tENCONTRADO: %d%d\n",	primeiroDigito, segundoDigito, numeroCPF[9], numeroCPF[10]);
			}
		}			
	}
	
	fclose(arquivo);
	
return 0;
}

int* Converte_Numero(char* stringCPF, int* numeroCPF)
{
	int cont, cont2;
	
	for(cont2 = 0, cont = 0; cont < 15; cont++)
	{
		if(stringCPF[cont] != '.' && stringCPF[cont] != '-')
		{
			numeroCPF[cont2] = stringCPF[cont] - '0';
			cont2++;
		}
	}
	numeroCPF[11] = '\0';	
	
	return numeroCPF;
}

int Verifica_NumerosIguais(int* numeroCPF)
{
	int cont, igual;
	igual = 0;
	
	for(cont = 1; cont < 11; cont++)
	{
		if(numeroCPF[cont-1] == numeroCPF[cont])
			igual++;	
	}
	
	if(igual == 10)
		return TRUE;
	else
		return FALSE;
}

int Verifica_PrimeiroDigito(int* numeroCPF)
{
	int cont, digitoVerificador1;
	digitoVerificador1 = 0;
	
	for(cont = 0; cont < 9; cont++)
		digitoVerificador1 = digitoVerificador1 +  numeroCPF[cont] * (cont + 1);
					
	digitoVerificador1 = digitoVerificador1 % 11;
	if(digitoVerificador1 == 10)
		digitoVerificador1 = 0;	
	
	return digitoVerificador1;
}

int Verifica_SegundoDigito(int* numeroCPF)
{
	int cont, digitoVerificador2;
	digitoVerificador2 = 0;
	
	for(cont = 11; cont > 1; cont--)
		digitoVerificador2 = digitoVerificador2 + numeroCPF[11 - cont] * cont;		
		
	digitoVerificador2 = (digitoVerificador2 * 10) % 11;
	if(digitoVerificador2 == 10)
		digitoVerificador2 = 0;	
	
	return digitoVerificador2;
}