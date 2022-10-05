#include <bits/stdc++.h>

#define endl '\n'
#define lli long long int
#define vi vector<bool>

using namespace std;

void erastotenes(lli tam, vi& criba){
    for (lli i=4; i<tam; i+=2){
        criba[i] = false;
    }
    lli newtam = sqrt(tam);
    for (lli i=3; i<=newtam; i+=2){
        if (criba[i]){
            for(lli j = i*i; j < tam; j += i)
                criba[j] = false;
        }
    }
}

int main(){
    int num;
    vi criba(1000000, true);
    erastotenes(1000000, criba);
    while(cin >> num, num){
        int fin;
        bool ver = true;
        for(int i = 2; i < num && ver; ++i){
            fin = num-i;
            if(criba[fin] && criba[i]){
                cout << num << " = " << i << " + " << fin << endl;
                ver = false;
            }
        }
    }
    return 0;
}