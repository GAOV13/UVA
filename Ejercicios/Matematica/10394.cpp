#include <bits/stdc++.h>

#define endl '\n'
#define vb vector<bool>
#define vi vector<int>
#define TAM 20000000
#define vpii vector<pair<int, int> >
#define lli long long int

using namespace std;

void erastotenes(int tam, vi &criba){
    ++tam;
    vb primos(tam);
    for(lli i = 4; i < tam; i += 2)
        primos[i] = false;
    int newTam = sqrt((double)tam);
    for(int i = 3; i <= newTam; i += 2){
        if(primos[i]){
            for(int j = i*i; j < tam; j += i)
                primos[j] = false;
        }
    }
    criba.push_back(2);
    for(int i = 3; i < tam; i+=2){
        if(primos[i])
            criba.push_back(i);
    }
}

int main(){
    vi criba(TAM + 1);
    erastotenes(TAM, criba);
    int tam = 0, num;
    vpii mem(100000);
    while(cin >> num){
        if(tam < num){
            
        }
    }
    return 0;
}