#include <iostream>
#include <algorithm>
#include <vector>

#define vi vector<unsigned int>
#define endl '\n'

using namespace std;

int main(){
    vi lista;
    int num;
    while(cin >> num)
        lista.push_back(num);
    int tam = lista.size();
    int j;
    for(int i = 0; i < tam; ++i){
        for(j = i - 1; j >= 0; j--)
            if(lista[j] < lista[i])
                break;
        int temp = lista[j + 1];
        lista[j + 1] = lista[i];
        for(int k = j + 2; k <= i; ++k){
            int temp2 = lista[k];
            lista[k] = temp;
            temp = temp2;
        }
        if(i%2 == 0) cout << lista[i/2] << endl;
        else cout << (lista[i/2] + lista[(i/2) + 1])/2 << endl;
    } 
    return 0;
}