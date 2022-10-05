#include <stdio.h>

int main(){
    int c, min, n;
    int ini, fin;
    int ver;
    scanf("%d", &c);
    while(c--){
        ver = 1;
        scanf("%d", &n);
        scanf("%d %d", &ini, &fin);
        min = ini-fin;
        while(--n){
            scanf("%d %d", &ini, &fin);
            if(min != (ini-fin))
                ver = 0;
        }
        if(ver)
            printf("yes\n");
        else
            printf("no\n");
        if(c)
            printf("\n");
    }
    return 0;
}