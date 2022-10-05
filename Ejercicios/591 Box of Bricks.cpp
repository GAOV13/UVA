#include <bits/stdc++.h>

#define vi vector<int>
#define endl '\n'

using namespace std;

int main(){
    int n, casos = 0;
    while(cin >> n, n){
        vi lista(n);
        int sum = 0, cuo = 0, dev = 0;
        for(int i = 0; i < n; ++i){
            cin >> lista[i];
            sum += lista[i];
        }

        cuo = sum/n;
        sort(lista.begin(), lista.end());
        for(int i = lista.size() - 1; lista[i] > cuo; --i){
            dev += lista[i] - cuo;
        }

        cout << "Set #" << ++casos << endl;
        cout << "The minimum number of moves is " << dev << ".\n" << endl;
    }
    return 0;
}
