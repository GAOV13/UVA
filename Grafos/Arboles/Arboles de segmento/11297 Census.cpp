#include <bits/stdc++.h>

#define vi vector<int>
#define vvp vector<vector<pair<int, int> > >
#define vp vector<pair<int, int> >
#define pii pair<int, int>
#define endl '\n'

using namespace std;

void creacion(vvp &arbol, vi &info, int v, int l, int r, int &indice){
    if(l == r) arbol[indice][v] = make_pair(info[l], info[l]);
    
    else{
        int m = l + ((r - l) >> 1);
        creacion(arbol, info, (2 * v) + 1, l, m, indice);
        creacion(arbol, info, 2 * (v + 1), m + 1, r, indice);
        arbol[indice][v] = make_pair(max(arbol[indice][(2 * v) + 1].first, arbol[indice][2 * (v + 1)].first), 
                                     min(arbol[indice][(2 * v) + 1].second, arbol[indice][2 * (v + 1)].second));
    }
}

int consultaMax(vvp &arbol, int v, int L, int R, int l, int r, int &indice){
    int ans = -1;
    if(l > r) ans = 0;

    else if(l == L && r == R) ans = arbol[indice][v].first;

    else{
        int m = L + ((R - L) >> 1);
        ans = max(consultaMax(arbol, (2 * v) + 1, L, m, l, min(r, m), indice), consultaMax(arbol, 2 * (v + 1), m + 1, R, max(l, m + 1), r, indice));
    }

    return ans;
}

int consultaMin(vvp &arbol, int v, int L, int R, int l, int r, int &indice){
    int ans = 2147483647;
    if(l > r) ans = 2147483647;

    else if(l == L && r == R) ans = arbol[indice][v].second;

    else{
        int m = L + ((R - L) >> 1);
        ans = min(consultaMin(arbol, (2 * v) + 1, L, m, l, min(r, m), indice), consultaMin(arbol, 2 * (v + 1), m + 1, R, max(l, m + 1), r, indice));
    }

    return ans;
}

void update(vvp &arbol, int v, int l, int r, int &pos, int &h, int &indice){
    if(l == r) arbol[indice][v] = make_pair(h, h);

    else{
        int m = l + ((r - l) >> 1);
        if(pos <= m) update(arbol, (2 * v) + 1, l, m, pos, h, indice);

        else update(arbol, 2 * (v + 1), m + 1, r, pos, h, indice);
        arbol[indice][v] = make_pair(max(arbol[indice][(2 * v) + 1].first, arbol[indice][2 * (v + 1)].first), 
                                     min(arbol[indice][(2 * v) + 1].second, arbol[indice][2 * (v + 1)].second));
    }
}

int main(){
    int n, m;
    cin >> n;
    vvp arbol(n, vp(4*n, make_pair(0, 2147483647)));
    for(int i = 0; i < n; ++i){
        vi lectura(n);
        for(int j = 0; j < n; ++j) cin >> lectura[j];
        
        creacion(arbol, lectura, 0, 0, n - 1, i);
    }

    cin >> m;
    while(m--){
        char c;
        cin >> c;
        if(c == 'q'){
            int i_ini, i_fin, j_ini, j_fin;
            int maxi = 0, mini = 2147483647;
            cin >> i_ini >> j_ini >> i_fin >> j_fin;
            for(int i = i_ini - 1; i < i_fin; ++i){
                maxi = max(maxi, consultaMax(arbol, 0, 0, n - 1, j_ini - 1, j_fin - 1, i));
                mini = min(mini, consultaMin(arbol, 0, 0, n - 1, j_ini - 1, j_fin - 1, i));
            }
            
            cout << maxi << ' ' << mini << endl;
        }

        else{
            int fila, col, val;
            cin >> fila >> col >> val;
            update(arbol, 0, 0, n - 1, --col, val, --fila);
        }
    }

    return 0;
}
