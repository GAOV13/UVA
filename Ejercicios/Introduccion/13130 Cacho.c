#include <stdio.h>

int main(){
    int a, b, n;
    int i, ver;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &a);
        ver = 1;
        for(i = 0; i < 4; ++i){
            scanf("%d", &b);
            if(a + 1 != b ) ver = 0;
            
            a = b;
        }
        if(ver) printf("Y");

        else printf("N");

        printf("\n");
    }
    return 0;
}