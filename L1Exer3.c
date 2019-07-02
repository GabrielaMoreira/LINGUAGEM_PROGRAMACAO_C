/*
	AMANDA CARVALHEIRO DOS SANTOS		RA: 0030481721003
	GABRIELA CRISTINA MOREIRA FRANCO	RA: 0030481721009
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

int main(){
	int cont, qtdeTestes, tamRa, cont2;
	char Ra_Antigo[9], Ra_Novo[14];
	
	scanf("%d", &qtdeTestes);

	for(cont = 0;cont < qtdeTestes;cont++){
		scanf("%s", Ra_Antigo);
		tamRa = strlen(Ra_Antigo);
		
		Ra_Novo[0] = '0';
		Ra_Novo[1] = '0';
		Ra_Novo[2] = '3';
		Ra_Novo[6] = Ra_Antigo[2];
		Ra_Novo[7] = Ra_Antigo[3];
		Ra_Novo[8] = Ra_Antigo[4];
		Ra_Novo[10] = Ra_Antigo[5];
		Ra_Novo[11] = Ra_Antigo[6];
		Ra_Novo[12] = Ra_Antigo[7];
		
		for(cont2 = 0;cont2 < tamRa;cont2++){
			if(Ra_Antigo[0] == 'A' && Ra_Antigo[1] == 'D'){
				Ra_Novo[3] = '0';
				Ra_Novo[4] = '4';
				Ra_Novo[5] = '8';
				Ra_Novo[9] = '1';
			}
			else if(Ra_Antigo[0] == 'A' && Ra_Antigo[1] == 'N'){
				Ra_Novo[3] = '0';
				Ra_Novo[4] = '4';
				Ra_Novo[5] = '8';
				Ra_Novo[9] = '3';
			}
			else if(Ra_Antigo[0] == 'S' && Ra_Antigo[1] == 'D'){
				Ra_Novo[3] = '0';
				Ra_Novo[4] = '6';
				Ra_Novo[5] = '1';
				Ra_Novo[9] = '1';
			}
			else if(Ra_Antigo[0] == 'L' && Ra_Antigo[1] == 'T'){
				Ra_Novo[3] = '0';
				Ra_Novo[4] = '7';
				Ra_Novo[5] = '4';
				Ra_Novo[9] = '2';
			}
			else if(Ra_Antigo[0] == 'P' && Ra_Antigo[1] == 'L'){
				Ra_Novo[3] = '0';
				Ra_Novo[4] = '8';
				Ra_Novo[5] = '0';
				Ra_Novo[9] = '2';
			}
			else if(Ra_Antigo[0] == 'P' && Ra_Antigo[1] == 'D'){
				Ra_Novo[3] = '0';
				Ra_Novo[4] = '9';
				Ra_Novo[5] = '9';
				Ra_Novo[9] = '1';
			}
			else if(Ra_Antigo[0] == 'P' && Ra_Antigo[1] == 'N'){
				Ra_Novo[3] = '0';
				Ra_Novo[4] = '9';
				Ra_Novo[5] = '9';
				Ra_Novo[9] = '3';
			}
			else if(Ra_Antigo[0] == 'O' && Ra_Antigo[1] == 'D'){
				Ra_Novo[3] = '1';
				Ra_Novo[4] = '0';
				Ra_Novo[5] = '0';
				Ra_Novo[9] = '1';
			}
			else if(Ra_Antigo[0] == 'O' && Ra_Antigo[1] == 'N'){
				Ra_Novo[3] = '1';
				Ra_Novo[4] = '0';
				Ra_Novo[5] = '0';
				Ra_Novo[9] = '3';
			}
		}
		printf("%s\n", Ra_Novo);
	}
	return 0;
}