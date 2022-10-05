#include <bits/stdc++.h>

#define endl '\n'
#define lli long long int
#define pii pair<int, int>
#define vi vector<int>
#define vb vector<bool>
#define MAXIMO 1000000

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
    int L, U;
    vi criba(1, 1);
    erastotenes(MAXIMO, criba);
    while(cin >> L >> U){
        int tam;
        if(U > MAXIMO){
            if(U != L)
                tam = U - L + 2;
            else
                tam = 1;
        } 
        else tam = 0; 
        cout << tam;
        vb otros(tam, true);

        
        for(int i = 0; i < otros.size(); ++i){
            bool ver = true;
            for(int j = 1; j < criba.size() && ver; ++j){
                if(L+i % criba[j] == 0 and L+i != criba[j]){
                    cout << L + i << " ";
                    cout << criba[j] << endl;
                    otros[i] = false;
                    ver = false;
                }
            }
        }

        if(U <= MAXIMO){
            vi::iterator itrI = lower_bound(criba.begin(), criba.end(), L), itrE = upper_bound(criba.begin(), criba.end(), U);
            pii mini = make_pair(0, pow(2,30)), maxi = make_pair(0,0);
            if(itrI == itrE or itrI == itrE - 1)
                cout << "There are no adjacent primes." << endl;
            else{
                for(auto itr = itrI + 1; itr != itrE; ++itr){
                    if(*(itr)-*(itr - 1) < mini.second - mini.first)
                        mini = make_pair(*(itr - 1), *(itr));
                    if(*(itr)-*(itr - 1) > maxi.second - maxi.first)
                        maxi = make_pair(*(itr - 1), *(itr));
                }
                cout << mini.first << "," << mini.second << " are closest, " << maxi.first << "," << maxi.second << " are most distant." << endl;
            }
        }
        else{
            pii mini = make_pair(0, pow(2,30)), maxi = make_pair(0,0);
            int a = 0, b = 0;
            for(int i = 0; i < tam; ++i){
                if(otros[i]){
                    b = i + L;
                    if(a){
                        if(b-a < mini.second - mini.first)
                            mini = make_pair(b,a);
                        if(b-a > maxi.second - maxi.first)
                            maxi = make_pair(b,a);
                    }
                    a = b;
                }
            }
            if(make_pair(0, 0) == maxi)
                cout << "There are no adjacent primes." << endl;
            else
                cout << mini.first << "," << mini.second << " are closest, " << maxi.first << "," << maxi.second << " are most distant." << endl;
        }
    }
    return 0;
}