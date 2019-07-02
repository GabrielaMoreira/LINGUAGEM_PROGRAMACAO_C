/*
	AMANDA CARVALHEIRO DOS SANTOS		RA: 0030481721003
	GABRIELA CRISTINA MOREIRA FRANCO	RA: 0030481721009
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int vogais(char letra){
	if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u')
		return 1;
	else
		return 0;
}
int main(){
	char real[21], jogo[21];
	int tamReal,tamJogo, cont2, contReal, contJogo, qtdeTestes, cont;
	
	scanf("%d",&qtdeTestes);
	
	for(cont = 0;cont < qtdeTestes;cont++){	
		scanf("%s %s", real ,jogo);
		
		tamReal = strlen(real);
		tamJogo = strlen(jogo);
	
		if(tamReal == tamJogo){
			for(cont2 = 0;cont2 < tamReal;cont2++)
			{
				contReal = vogais(real[cont2]);
				contJogo = vogais(jogo[cont2]);
			
				if(contReal != contJogo){
					printf("No\n");
					break;
				}
				if (contReal == 0){
					if(real[cont2] == jogo[cont2]){
						printf("Yes\n");
						break;
					}
				}
				if(cont2 !=(tamReal-1)){
					printf("No\n");
					break;
				}
			}
		}
		else
			printf("No\n");
	}
	return 0;
}