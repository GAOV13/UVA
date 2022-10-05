#include <stdio.h>

int main(){
    int n, m, caso = 0;
    int ver, conteo, num;
    char info;
    scanf("%d", &n);
    while(n--){
        scanf("%d\n", &m);
        conteo = 0;
        ver = 1;
        num = 1;
        while(m--){
            scanf("%c\n", &info);
            if(info != 'W') ++conteo;
            else conteo = 0;
            if(conteo >= 3) ver = 0;
            else if(ver) ++num;
        }
        printf("Case %d: ", ++caso);
        if(ver) printf("Yay! Mighty Rafa persists!\n");
        else printf("%d\n", num);

    }
    return 0;
}