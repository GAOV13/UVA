#include <bits/stdc++.h>

#define vi vector<int>
#define endl '\n'

using namespace std;

int main(){
    int n;
    cin >> n;
    while(n){
        vi lista;
        long long int suma = 0;
        for(int i = 0; i < n; ++i){
            int m; 
            cin >> m;
            for(int j = 0; j < m; ++j){
                int num;
                cin >> num;
                vi::iterator itr = lower_bound(lista.begin(), lista.end(), num);
                lista.insert(itr, num);
            }
            vi::iterator itr = lower_bound(lista.begin(), lista.end(), 0);
            suma += lista[lista.size() - 1] - (*itr);
            lista.pop_back();
            (*itr) = -1;
        }
        cout << suma << endl;
        cin >> n;
    }
    return 0;
}
