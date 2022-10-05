#include <bits/stdc++.h>

#define endl '\n'
#define TAM 10000000
#define vb vector<bool>
#define lli long long int
#define pii pair<int, int>

using namespace std;

void erastotenes(int tam, vb &criba){
    ++tam;
    for(lli i = 4; i < tam; i += 2)
        criba[i] = false;
    int newtam = sqrt((double)tam);
    for(lli i = 3; i <= newtam; i += 2){
        if(criba[i]){
            for(lli j = i*i; j < tam; j += i)
                criba[j] = false;
        }
    }
}

pii goldback_conjecture(int num, vb &criba){
    for(int i = 2; i < criba.size(); ++i){
        int fin = num-i;
        if(criba[i] && criba[fin])
            return make_pair(i, fin);
    }
    return make_pair(0, 0);
}

int main(){
    int N;
    vb criba(TAM + 1, true);
    erastotenes(TAM, criba);
    while(cin >> N){
        if(N < 8)
            cout << "Impossible." << endl;
        else{
            pii par;
            if (N%2 == 0){
                cout << 2 << " " << 2;
                par = goldback_conjecture(N-4, criba);
            }
            else{
                cout << 2 << " " << 3;
                par = goldback_conjecture(N-5, criba);
            }
            cout << " " << par.first << " " << par.second << endl;
        }
    }
    return 0;
}