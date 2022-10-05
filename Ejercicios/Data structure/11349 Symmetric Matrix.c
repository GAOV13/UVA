#include <stdio.h>

int main(){
    long long int matrix[100][100];
    long long int zero = 0;
    int tam, i, j, n;
    int flag, caso = 0;
    char basura1[2], basura2[2];
    scanf("%d", &n);
    while(n--){
        scanf("%s %s %d", basura1, basura2, &tam);
        for(i = 0; i < tam; ++i)
            for(j = 0; j < tam; ++j)
                scanf("%lli", &matrix[i][j]);
        
        flag = 1;
        for(i = 0; i <= tam/2 && flag; ++i){
            for(j = 0; j < tam && flag; ++j){
                if(matrix[i][j] != matrix[tam - 1 - i][tam - 1- j])
                    flag = 0;
                if(matrix[i][j] < zero || matrix[tam - 1 - i][tam - 1- j] < zero)
                    flag = 0;
            }
        }

        printf("Test #%d: ", ++caso);
        if(flag) printf("Symmetric.\n");
        else printf("Non-symmetric.\n");
    }
    return 0;
}