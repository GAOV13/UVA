#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char list[60][63];
	char numero[600];
	char d;
	int i, j, k, fil, col, n;
	int ver;
	fgets(numero, 15, stdin);
	sscanf(numero, "%d", &n);
	while(n--){
		fgets(numero, 2, stdin);
		fgets(numero, 15, stdin);
		sscanf(numero, "%d %d", &fil, &col);
		for(i = 0; i < fil; i++){
			fgets(list[i], col + 3, stdin);
		}
		fgets(numero, 15, stdin);
		sscanf(numero, "%d %d", &i, &j);
		i--; j--;
		ver = 1;
		d = 'N';
		while(ver){
			fgets(numero, 598, stdin);
			for(k = 0; k < strlen(numero); k++){
				if(numero[k] == ' '){
					while(numero[k] == ' ') k++;
				}
				
				if(numero[k] == 'Q'){
					ver = 0;
					break;
				}
				
				else if(numero[k] == 'R'){
					if(d == 'N') d = 'E';
					
					else if(d == 'E') d = 'S';
					
					else if(d == 'S') d = 'W';
					
					else if(d == 'W') d = 'N';
				}
				
				else if(numero[k] == 'L'){
					if(d == 'N') d = 'W';
					
					else if(d == 'W') d = 'S';
					
					else if(d == 'S') d = 'E';
					
					else if(d == 'E') d = 'N';
				}
				
				else if(numero[k] == 'F'){
					if(d == 'N'){
						if(i - 1 >= 0){
							if(list[i - 1][j] == ' ') i--;
						}
					}
					
					else if(d == 'E'){
						if(j + 1 < col){
							if(list[i][j + 1] == ' ') j++;
						}
					}
					
					else if(d == 'S'){
						if(i + 1 < fil){
							if(list[i + 1][j] == ' ') i++;
						}
					}
					
					else if(d == 'W'){
						if(j - 1 >= 0){
							if(list[i][j - 1] == ' ') j--;
						}
					}
				}	
			}
		}
		printf("%d %d %c\n", i + 1, j + 1, d);
		if(n) printf("\n");
	}
	return 0;
}

