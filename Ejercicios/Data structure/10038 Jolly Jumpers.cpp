#include <iostream>
#include <vector>
#include <cmath>

#define vi vector<int>
#define endl '\n'

using namespace std;

int main(){
    int n; 
    while(cin >> n){
        vi lista(n);
        for(int i = 0; i < n; ++i)
            cin >> lista[i];
        
        vi dev(n, 0);
        for(int i = 0; i < n - 1; ++i){
            int indice = abs(lista[i] - lista[i + 1]);
            if(indice < n) ++dev[indice];
        }

        bool ver = true;
        for(int i = 1; i < n && ver; ++i){
            if(!dev[i]) ver = false;
        }

        if(ver) cout << "Jolly" << endl;

        else cout << "Not jolly" << endl;
    }
}
