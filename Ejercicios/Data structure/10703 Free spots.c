#include <stdio.h>

int main(){
    int W, H, N;
    int x1, x2, y1, y2;
    int matriz[500][500];
    int i, j, k;
    int conteo;
    while(scanf("%d %d %d", &W, &H, &N), W && H){
        for(i = 0; i < W; ++i)
            for(j = 0; j < H; ++j)
                matriz[i][j] = 1;
        
        while(N--){
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            if(x1 > x2){
                k = x1;
                x1 = x2;
                x2 = k;
            }
            if(y1 > y2){
                k = y1;
                y1 = y2;
                y2 = k;
            }
            for(i = x1 - 1; i < x2; ++i)
                for(j = y1 - 1; j < y2; ++j)
                    matriz[i][j] = 0;
        }

        conteo = 0;
        for(i = 0; i < W; ++i)
            for(j = 0; j < H; ++j)
                if(matriz[i][j])
                    ++conteo;

        if(!conteo) printf("There is no empty spots.\n");
        else if(conteo == 1) printf("There is one empty spot.\n");
        else printf("There are %d empty spots.\n", conteo);
    }
    return 0;
}