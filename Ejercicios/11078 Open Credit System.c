#include <stdio.h>

int main(){
    int n, tam, max, res, i, k;
    scanf("%d", &n);
    while(n--){
        res = -150001;
        scanf("%d %d", &tam, &max);
        for(i = 1; i < tam; ++i){
            scanf("%d", &k);
            res = res < max - k ? max - k : res;
            max = max < k ? k : max;
        }
        printf("%d\n", res);
    }
    return 0;
}
