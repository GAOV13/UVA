#include <stdio.h>

int main(){
    int n, m;
    int cant, ver;
    int temp;
    int i, j;
    while(scanf("%d %d", &n, &m) != EOF){
        cant = 0;
        for(i = 0; i < n; ++i){
            ver = 1;
            for(j = 0; j < m; ++j){
                scanf("%d", &temp);
                if(!temp) ver = 0;
            }
            if(ver) ++cant;
        }
        printf("%d\n", cant);
    }
    return 0;
}