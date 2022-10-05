#include <bits/stdc++.h>

#define endl '\n'
#define lli long long int
#define vi vector<int>
#define vb vector<bool>

using namespace std;

void erastotenes(lli tam, vi& criba){
    ++tam;
    vb primos(tam, true);
    criba.push_back(2);
    for (lli i=4; i<tam; i+=2){
        primos[i] = false;
    }
    lli newtam = sqrt(tam);
    for (lli i=3; i<=newtam; i+=2){
        if (primos[i]){
            for(lli j = i*i; j < tam; j += i)
                primos[j] = false;
        }
    }
    for(lli i = 3; i < tam; i+=2){
        if(primos[i])
            criba.push_back(i);
    }
}

int main(){
    int num, k;
    vi criba(1, 1);
    erastotenes(1000, criba);
    while(cin >> num >> k){
        vi::iterator itrE = upper_bound(criba.begin(), criba.end(), num);
        int tam = itrE - criba.begin();
        int inicio = ceil((double)tam/2);
        cout << num << " " << k << ":";
        for(int i = max(1, inicio-(k-1)); i <= inicio; ++i)
            cout << " " << criba[i-1];
        if(tam%2){
            for(int i = inicio; i < min(tam, inicio+(k-1)); ++i)
                cout << " " << criba[i];
        }
        else{
            for(int i = inicio; i < min(tam, inicio+(k)); ++i)
                cout << " " << criba[i];
        }
        cout << "\n" << endl;
    }
    return 0;
}