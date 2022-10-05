#include <stdio.h>

const double LIM = 125.0;
const double PESO = 7.0;
const double LIML = 56.0;
const double LIMW = 45.0;
const double LIMD = 25.0;

int main(){
    int n;
    double length, width, depth;
    double kg;
    int ver, cant = 0;
    scanf("%d", &n);
    while(n--){
        ver = 0;
        scanf("%lf %lf %lf %lf", &length, &width, &depth, &kg);
        if(kg > PESO) ver = 0;
        else if(length <= LIML && width <= LIMW && depth <= LIMD) ver = 1;
        else if((length + width + depth <= LIM)) ver = 1;

        if(ver) ++cant;
        
        printf("%d\n", ver);
    }
    printf("%d\n", cant);
    return 0;
}
