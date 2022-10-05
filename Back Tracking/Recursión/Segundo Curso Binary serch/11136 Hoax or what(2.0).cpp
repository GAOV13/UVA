#include <bits/stdc++.h>

#define mi multiset<int>
#define endl '\n'

using namespace std;

int main(){
    int n;
    cin >> n;
    while(n){
        mi lista;
        long long int suma = 0;
       while(n--){
            int m; 
            cin >> m;
            while(m--){
                int num;
                cin >> num;
                lista.insert(num);
            }
            mi::iterator ini = lista.begin();
            mi::iterator fin = --lista.end();

            suma += *(fin) - *(ini);
            lista.erase(fin);
            lista.erase(ini);
        }
        cout << suma << endl;
        cin >> n;
    }
    return 0;
}
