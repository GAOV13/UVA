#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
	char x;
	
	while(scanf("%c", &x) != EOF){
		if(x != '\n') x -= 7;
		
		printf("%c", x);
	}
	return 0;
}

