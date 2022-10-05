#include <stdio.h>

int main(){
    int B, S, casos = 0;
    int min, t, i;
    scanf("%d %d", &B, &S);
    while(B || S){
        scanf("%d", &min);
        for(i = 1; i < B; ++i){
            scanf("%d", &t);
            if(t < min) min = t;
        }
        for(i = 0; i < S; ++i) scanf("%d", &t);;
        printf("Case %d: ", ++casos);
        if(B > S) printf("%d %d\n", B-S, min);
        else printf("0\n");
        scanf("%d %d", &B, &S);
    }
}