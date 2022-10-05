#include <bits/stdc++.h>

using namespace std;

void bubleSort(int *lista, int tam){
    for(int i = 0; i < tam - 1; ++i){
        for(int j = i + 1; j < tam; ++j){
            if(lista[i] > lista[j] && lista[j]%2 == 1){
                int aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }
            else if(lista[i] < lista[j] && lista[j]%2 == 0){
                int aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }
        }
    }
}


int main(){
    int lista[10] = {4, 5, 2, 3, 7, 9, 7, 3, 1, 10};
    bubleSort(lista, 10);
    for(int i = 0; i < 10; ++i){
        cout << lista[i] << " ";
    }

    cout << endl;
    cout << lista << endl;
    printf("malparida vida");
}
