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
    vi criba(pow(2,15), true);
    erastotenes(pow(2,15), criba);
    while(cin >> num, num){
        int fin;
        int ans = 0;
        for(int i = 2; i <= num/2; ++i){
            fin = num-i;
            if(criba[fin] && criba[i])
                ++ans;
        }
        cout << ans << endl;
    }
    return 0;
}