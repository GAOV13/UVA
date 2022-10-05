#include <iostream>
#include <vector>

#define endl '\n'
#define vi vector<int>
#define vvi vector<vector<int> >

using namespace std;

void tabulacion(vvi &tab, int n, int c, vi &B, vi &W){
    for(int i = 1; i < n; ++i){
        for(int j = 1;  j < c; ++j){
            if(W[i-1] > j) tab[i][j] = tab[i-1][j];
            else tab[i][j] = max(B[i-1] + tab[i-1][j-W[i-1]], tab[i-1][j]);
        }
    }
}

int suma(int n, int c, vi &B, vi &W, vi &lista){
    vvi tab(n+1, vi(c+1, 0));
    tabulacion(tab, n+1, c+1, B, W);
    int ans = 0;
    for(int i = 0; i < lista.size(); ++i)
        ans += tab[n][lista[i]];
    return ans;
}

int main(){
    int T, n, m, maxi;
    cin >> T;
    while(T--){
        cin >> n;
        vi B(n), W(n);
        for(int i = 0; i < n; ++i)
            cin >> B[i] >> W[i];
        cin >> m;
        vi lista(m);
        maxi = 0;
        for(int i = 0; i < m; ++i){
            cin >> lista[i];
            maxi = max(maxi, lista[i]);
        }
        cout << (suma(n, maxi, B, W, lista)) << endl;
    }
    return 0;
}