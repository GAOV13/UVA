#include <bits/stdc++.h>

#define vpii vector<pair<int, int> >
#define endl '\n'

using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        vpii lista(n);
        for(int i = 0; i < n; ++i){
            int L, W, H;
            cin >> L >> W >> H;
            lista[i] = make_pair(H, L*W*H);
        }
        sort(lista.begin(), lista.end());
        cout << lista[n - 1].second << endl;
    }
    return 0;
}