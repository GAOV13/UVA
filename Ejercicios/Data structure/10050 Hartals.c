#include <stdio.h>

int main(){
    int n, tam, hartals;
    int temp, m, i;
    int dias[3651];
    scanf("%d", &n);
    while(n--){
        scanf("%d", &tam);
        for(i = 0; i <= tam; ++i) dias[i] = 0;

        scanf("%d", &m);
        hartals = 0;
        while(m--){
            scanf("%d", &temp);
            for(i = temp; i <= tam; i += temp){
                if(!dias[i]++ && (i % 7 != 0 && i % 7 != 6)) ++hartals;
            }
        }
        printf("%d\n", hartals);
    }
    return 0;
}