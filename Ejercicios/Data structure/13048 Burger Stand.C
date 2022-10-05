#include <stdio.h>
#include <string.h>

int main(){
    int n, casos = 0;
    int tam, cant, i;
    int ver;
    char cadena[51];
    scanf("%d", &n);
    while(n--){
        scanf("%s", cadena);
        tam = strlen(cadena);
        cant = 0;
        for(i = 0; i < tam; ++i){
            ver = 1;
            if(cadena[i] == 'D' || cadena[i] == 'S' || cadena[i] == 'B')
                ver = 0;
            else if(i + 1 < tam && (cadena[i + 1] == 'B' || cadena[i + 1] == 'S'))
                ver = 0;
            else if(i + 2 < tam && cadena[i + 2] == 'B')
                ver = 0;
            else if(i - 1 >= 0 && cadena[i - 1] == 'S')
                ver = 0;
            if(ver) ++cant;
        }
        printf("Case %d: %d\n", ++casos, cant);
    }
    return 0;
}