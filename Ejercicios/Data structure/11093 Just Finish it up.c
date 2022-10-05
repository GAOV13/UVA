#include <stdio.h>

int main(){
    int m, tam, casos = 0;
    int gas[100001], dist[100001];
    int i, ver, inicio;
    int cant;
    scanf("%d", &m);
    while(m--){
        scanf("%d", &tam);
        for(i = 0; i < tam; ++i) scanf("%d", gas + i);
        for(i = 0; i < tam; ++i) scanf("%d", dist + i);

        inicio = 0;
        i = 1;
        ver = 0;
        cant = gas[0];
        while(!ver && inicio < tam){
            if(cant - dist[i - 1] >= 0){
                cant = cant - dist[i - 1];
                if(i == tam) i = 0;
                if(i == inicio) ver = 1;
                else cant += gas[i++];
            }

            else{
                if(i > inicio){
                    inicio = i;
                    i = inicio + 1;
                    cant = gas[inicio];
                }
                else inicio = tam;
            }
        }

        printf("Case %d: ", ++casos);
        if(ver) printf("Possible from station %d\n", inicio + 1);

        else printf("Not possible\n");
    }
    return 0;
}