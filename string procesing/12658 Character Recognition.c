#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char cadena[5][41];
    int n, i;
    scanf("%d", &n);
    for(i = 0; i < 5; ++i) scanf("%s", cadena[i]);

    for(i = 0; i < 4*n; i += 4){
        if(cadena[1][i + 1] == '*') printf("1");
        else if(cadena[3][i] == '*') printf("2");
        else printf("3");
    }
    printf("\n");
    return 0;
}
