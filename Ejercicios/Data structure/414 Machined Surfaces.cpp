#include <bits/stdc++.h>

using namespace std;

int main(){
    string cadena;
    int vacios[13];
    int n, i, j, cant, mini;
    while(cin >> n, n){
        mini = 25;
        cin.ignore();
        for(i = 0; i < n; ++i){
            getline(cin, cadena);
            cant = 0;
            for(int j = 0; j < 25; ++j)
                if(cadena[j] == ' ')
                    ++cant;
            mini = cant < mini ? cant : mini;
            vacios[i] = cant;
        }

        cant = 0;
        for(int i = 0; i < n; ++i)
            cant += vacios[i] - mini;
        printf("%d\n", cant);
    }
}
