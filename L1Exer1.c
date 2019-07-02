/*
	AMANDA CARVALHEIRO DOS SANTOS		RA: 0030481721003
	GABRIELA CRISTINA MOREIRA FRANCO	RA: 0030481721009
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

struct registro{
	char semana[15]; 
}DiaDaSemana[8];

struct registro DiaDaSemana[] ={
	{"Domingo"},
	{"Segunda-Feira"},
	{"Terça-Feira"},
	{"Quarta-Feira"},
	{"Quinta-Feira"},
	{"Sexta-Feira"},
	{"Sábado"}
};

int main(){
	int dia, mes, ano, primeiroAno, segundoAno, mesAux, posicao, anoAux; 
	double diaSemana;
		
	while(scanf("%d %d %d", &dia, &mes, &ano), dia != 0 && mes != 0 && ano != 0)
	{
		diaSemana = 0;		
		
		if(mes>2)
		{
			mesAux = mes - 2;
			anoAux = ano;
		}			
		else
		{
			mesAux = mes + 10;
			anoAux = ano - 1;
		}
		
		primeiroAno = anoAux/100;
		segundoAno = anoAux%100;
		
		diaSemana = trunc(2.6 * mesAux - 0.1) + dia + segundoAno + (segundoAno/4) + (primeiroAno/4) - 2 * primeiroAno;
		posicao = (int)diaSemana;
		
		if(posicao < 0)
		{
			posicao = posicao/7;
			posicao = posicao + 7;
		}
		else
		{
			posicao = posicao%7;
		}	
				
		printf("%02d/%02d/%d: %s\n", dia, mes, ano, DiaDaSemana[posicao].semana);
	}
	
return 0;
}