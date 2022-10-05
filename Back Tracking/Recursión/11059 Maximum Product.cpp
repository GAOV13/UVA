#include <iostream>
#include <vector>

#define endl '\n'
#define vill vector<long long int>
#define lli long long int
using namespace std;

void back(vill &lista, int indice, lli acum, lli &n, bool ver, int j){
    if(acum > n && j) n = acum;

    if(acum == 1) ver = true;

    if(!ver) return;

    else if(indice == lista.size() || acum == 0) return;

    back(lista, indice + 1, acum, n, false, j);
    back(lista, indice + 1, acum * lista[indice], n, true , j + 1);
}

int main(){
    int n, casos = 0;
    while(cin >> n){
        vill lista(n);
        for(int i = 0; i < n; ++i){
            int k;
            cin >> k;
            lista[i] = k;
        }

        lli n = 0;
        back(lista, 0, 1, n, true, 0);

        cout << "Case #" << ++casos << ": The maximum product is " << n << "." << endl << endl;
    }
}
