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
    int num;
    vi criba;
    erastotenes(1299709, criba);
    while(cin >> num, num){
        if(binary_search(criba.begin(), criba.end(), num))
            cout << 0 << endl;
        else{
            vi::iterator itrI = lower_bound(criba.begin(), criba.end(), num), itrE;
            itrE = itrI--;
            cout << (*itrE) - (*itrI) << endl;
        }
    }
    return 0;
}