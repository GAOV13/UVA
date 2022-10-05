#include <stdio.h>

int main(){
	int casos = 1;
	int devices[20], estado[20];
	int aparatos, switches, capacidad, max, suma;
	int i, j, ver;
	
	scanf("%d %d %d", &aparatos, &switches, &capacidad);
	while(aparatos && switches && capacidad){
		max = 0;
		for(i = 0; i < aparatos; i++){
			scanf("%d", &devices[i]);
			estado[i] = -1;
		}
		
		suma = 0;
		ver = 1;
		for(j = 0; j < switches; j++){
			scanf("%d", &i);
			if(ver){
				if(estado[i - 1] == -1){
					estado[i - 1] = 1;
					suma += devices[i - 1];
					max = suma > max ? suma : max;
					if(max > capacidad){
						ver = 0;	
						}
				}
				else{
					estado[i - 1] = -1;
					suma -= devices[i - 1];
				}
			}	
		}
		
		if(ver){
			printf("Sequence %d\n"
                "Fuse was not blown.\n"
					 "Maximal power consumption was %d amperes.\n", casos++, max);
		}
		else{
			printf("Sequence %d\n"
					 "Fuse was blown.\n", casos++);
		}
	
		scanf("%d %d %d", &aparatos, &switches, &capacidad);
		printf("\n");
	}
	return 0;
}

