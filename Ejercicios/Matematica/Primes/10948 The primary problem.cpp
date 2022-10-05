#include <bits/stdc++.h>

#define endl '\n'
#define lli long long int
#define vb vector<bool>
#define TAM 1000000

using namespace std;

void erastotenes(int tam, vb &criba){
    ++tam;
    for(lli i = 4; i < tam; i += 2)
        criba[i] = false;
    int newTam = sqrt((double)tam);
    for(lli i = 3; i <= newTam; i += 2){
        if(criba[i]){
            for(lli j = i*i; j < tam; j += i)
                criba[j] = false;
        }
    }
}

int main(){
    vb criba(TAM + 1, true);
    erastotenes(TAM, criba);
    int num;
    while(cin >> num, num){
        bool ver = true;
        cout << num << ":" << endl;
        if(criba[2] && criba[num-2]){
            cout << 2 << "+" << num-2 << endl;
            ver = false;
        }
        for(int i = 3; i <= num/2 && ver; i += 2){
            if(criba[i] && criba[num-i]){
                cout << i << "+" << num-i << endl;
                ver = false;
            }
        }
        if(ver)
            cout << "NO WAY!" << endl;
    }
    return 0;
}