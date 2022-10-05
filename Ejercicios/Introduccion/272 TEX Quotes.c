#include <stdio.h>
#include <stdlib.h>

int main(){
	char x;
	int i = 0;
	while(scanf("%c", &x) != EOF){
		if(x == '\"'){
			if(i){
				printf("''");
				i = 0;
			}
			else{
				printf("``");
				i = 1;
			}
		}
		
		else printf("%c", x);
	}
	return 0;
}

