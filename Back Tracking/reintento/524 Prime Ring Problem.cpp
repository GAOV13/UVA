#include <bits/stdc++.h>

#define vi vector<int>
#define vb vector<bool>
#define endl '\n'

using namespace std;

int n;
vb primos(33, true);

void criba(){
    for(int i = 4; i < 33; i+=2)
        primos[i] = false;
    for(int i = 3; i <= sqrt(33); i+=2){
        if(primos[i]){
            for(int j=i*i; j<33; j+=i)
                primos[j] = false;
        }
    }
}

void phi(vi &A, vi temp){
    if(temp.size() == n){
        if(primos[temp[n-1]+1]){
            cout << 1;
            for(int i = 1; i < n; ++i)
                cout << " " << temp[i];
            cout << endl;
        }
    }
    else{
        for(int i = 1; i < n; ++i){
            if(A[i] && primos[temp[temp.size()-1]+A[i]]){
                int t = A[i];
                temp.push_back(A[i]);
                A[i] = 0;
                phi(A, temp);
                temp.pop_back();
                A[i] = t;
            }
        }
    }
}

int main(){
    criba();
    int casos = 0;
    while(cin >> n){
        if(casos)
            cout << endl;
        cout << "Case " << ++casos << ":" << endl;
        vi A(n);
        for(int i = 0; i < n; ++i) A[i] = i+1;
        phi(A, vi(1,1)); 
    }
    return 0;
}