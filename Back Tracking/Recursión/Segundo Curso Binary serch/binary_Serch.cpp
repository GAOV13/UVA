#include <iostream>
#include <vector>
#include <algorithm>

#define vi vector<int>
#define endl '\n'

using namespace std;

bool binaryS(vi &lista, int num, int low, int hi){
    int mid = (low + hi) >> 1; 
    if(low == mid){
        if(lista[mid] == num) return true;

        else return false;
    }
     
    if(lista[mid] <= num) return binaryS(lista, num, mid, hi);

    else return binaryS(lista, num, low, mid);
}

int upperS(vi &lista, int num, int low, int hi){
    int mid = (low + hi) >> 1; 
    if(low == mid) return hi;
    
    if(lista[mid] <= num) return upperS(lista, num, mid, hi);

    else return upperS(lista, num, low, mid);
}

int lowerS(vi &lista, int num, int low, int hi){
    int mid = (low + hi) >> 1;
    if(mid == low){ 
        if(lista[mid] == num) return mid; 

        else return mid + 1;
    }
    
    if(lista[mid] < num) return lowerS(lista, num, mid, hi);

    else return lowerS(lista, num, low, mid);
}

int main(){
    vi lista(1000);
    for(int i = 0; i < 1000; ++i) lista[i] = 2*i;
    
    sort(lista.begin(), lista.end());
    if(!binaryS(lista, 551, 0, 1000)) cout << "No" << endl;

    if(binaryS(lista, 340, 0, 1000)) cout << "Si" << endl;

    int it = upperS(lista, 44, 0, 1000);

    cout << lista[it - 1] << " es el valor buscado mientras que " << lista[it] << " es el valor entregado" << endl;

    it = upperS(lista, 2000, 0, 1000);
    cout << lista[it - 1] << " es el valor buscado mientras que " << lista[it] << " es el valor entregado" << endl;

    it = lowerS(lista, 42, 0, 1000);
    cout << lista[it] << " es el valor entregado y no " << lista[it - 1] << ", y tampoco " << lista[it + 1] << endl;

    it = lowerS(lista, 891, 0, 1000);
    cout << lista[it] << " es el valor entregado" << endl;
    return 0;
}