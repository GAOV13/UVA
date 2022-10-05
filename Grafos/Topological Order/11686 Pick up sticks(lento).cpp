#include <bits/stdc++.h>

#define vvi vector<vector<int> >
#define vi vector<int>
#define qi queue<int>
#define endl '\n'

using namespace std;

int topo_sort_kahn(vvi &grafo, vi &invertices, vi &lista){
    int cant = 0;
    qi cola;
    lista.clear();
    for(int i = 1; i < invertices.size(); ++i)
        if(!invertices[i]) cola.push(i);
    
    while(!cola.empty()){
        int u = cola.front(); cola.pop();
        for(int i = 0; i < grafo[u].size(); ++i){
            int j = grafo[u][i];
            if(--invertices[j] == 0) cola.push(j);
        }
        ++cant;
        lista.push_back(u);
    }
    return cant;
}

int main(){
    int n, m;
    while(cin >> n >> m, n || m){
        vvi grafo(n + 1);
        vi invertices(n + 1, 0);
        while(m--){
            int ini, fin;
            cin >> ini >> fin;
            grafo[ini].push_back(fin);
            ++invertices[fin];
        }

        vi lista;
        int m = topo_sort_kahn(grafo, invertices, lista);
        if(m != n) cout << "IMPOSSIBLE" << endl;

        else
            for(int i = 0; i < m; ++i) cout << lista[i] << endl; 
    }
    return 0;
}
