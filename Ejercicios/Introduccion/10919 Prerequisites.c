#include <stdio.h>
#include <stdlib.h>

int comparator(const void *num1, const void *num2){ 
    int *a, *b;
    a = (int *) num1;
    b = (int *) num2;
    return (*a - *b);
}

int busqueda(int dato, int tam, int *arreglo){
    int i, res = 1;
    int mini = 0, maxi = tam, medio;
    while(res){
        medio = (maxi + mini)/2;
        if(arreglo[medio] == dato) break;

        else if(medio == mini) res = 0;

        else if(arreglo[medio] > dato) maxi = medio;
        else mini = medio; 
    }
    return res;
}

int main(){
    int cursos, categoria;
    int obligatorio, cant;
    int ver, i, temp;
    int datos[100];
    while(scanf("%d", &cursos) && cursos){
        scanf("%d", &categoria);
        for(i = 0; i < cursos; ++i) scanf("%d", (datos + i));

        qsort(datos, cursos, sizeof(int), comparator);
        ver = 1;
        while(categoria--){
            scanf("%d %d", &cant, &obligatorio);
            for(i = 0; i < cant; ++i){
                scanf("%d", &temp);
                if(ver)
                    if(busqueda(temp, cursos, datos)) --obligatorio;
            }
            if(obligatorio > 0) ver = 0;
        }

        if(ver) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}