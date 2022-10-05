#include <bits/stdc++.h>

#define vi vector<long long int>
#define vvi vector<vector<long long int> >
#define vvvi vector<vector<vector<long long int> > >
#define endl '\n'

using namespace std;

vi generar_primos(){
    vi primos;
    vi temp(1121);
    for(int i = 2; i < 1121; ++i){
        if(!temp[i]){
            primos.push_back(i);
            for(int j = 2*i; j < 1121; j = j + i){
                temp[j] = 1;
            }
        }
    }
    return primos;
}

long long int back(int num, int index, int cant, vi &primos, vvvi &dic){
    long long int ans = 0;
    if(dic[num][index][cant] != -1) ans = dic[num][index][cant];
    else{
        if(!cant && !num) ans = 1;
        else if(!cant && num) ans = 0;
        else if(index >= primos.size()) ans = 0;
        else if(primos[index] > num) ans = 0;
        else ans = back(num, index + 1, cant, primos, dic) + back(num - primos[index], index + 1, cant - 1, primos, dic);
        dic[num][index][cant] = ans; 
    }
    return ans;
}

int main(){
    int n, m;
    vi primos = generar_primos();
    vvvi dic(1121, vvi(primos.size() + 1, vi(15, -1)));
    while(cin >> n >> m, n || m){
        cout << back(n, 0, m, primos, dic) << endl;
    }
    return 0;
}