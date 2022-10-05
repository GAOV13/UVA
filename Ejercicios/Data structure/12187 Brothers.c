#include <stdio.h>

int ejex[4] = {1, 0, -1, 0};
int ejey[4] = {0, -1, 0, 1};

void cambiar(int fil, int col, int N, int kingdom1[100][100], int kingdom2[100][100]){
    int i, j, k;
    int x, y, val;
    for(i = 0; i < fil; ++i){
        for(j = 0; j < col; ++j){
            for(k = 0; k < 4; ++k){
                x = j + ejex[k];
                y = i + ejey[k];
                if(y >= 0 && y < fil && x >= 0 && x < col){
                    val = (kingdom1[i][j] + 1)%N;
                    if(val == kingdom1[y][x])
                        kingdom2[y][x] = kingdom1[i][j];
                }
            }
        }
    }
}

void imprimir(int fil, int col, int kingdom[100][100]){
    int i, j;
    for(i = 0; i < fil; ++i){
        printf("%d", kingdom[i][0]);
        for(j = 1; j < col; ++j)
            printf(" %d", kingdom[i][j]);
        printf("\n");
    }
}

int main(){
    int N, R, C, K;
    int kingdom1[100][100], kingdom2[100][100];
    int i, j;
    while(scanf("%d %d %d %d", &N, &R, &C, &K), N){
        for(i = 0; i < R; ++i){
            for(j = 0; j < C; ++j){
                scanf("%d", &kingdom1[i][j]);
                kingdom2[i][j] = kingdom1[i][j];
            }
        }
        while(K--){
            cambiar(R, C, N, kingdom1, kingdom2);
            for(i = 0; i < R; ++i)
                for(j = 0; j < C; ++j)
                    kingdom1[i][j] = kingdom2[i][j];
        }
        imprimir(R, C,  kingdom1);
    }
    return 0;
}