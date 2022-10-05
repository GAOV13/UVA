#include <bits/stdc++.h>

#define vvi vector<vector<int> >
#define vi vector<int>
#define qi queue<int>

using namespace std;

vi topo_sort_kahn(vvi &grafo, vi &invertices){
    vi lista;
    qi cola;
    for(int i = 1; i < invertices.size(); ++i)
        if(!invertices[i]) cola.push(i);
    
    while(!cola.empty()){
        int u = cola.front(); cola.pop();
        lista.push_back(u);
        for(int i = 0; i < grafo[u].size(); ++i){
            int j = grafo[u][i];
            if(--invertices[j] == 0) cola.push(j);
        }
    }

    return lista;
}

int main(){
    int n, m;
    while(cin >> n >> m, n){
        vvi grafo(n + 1);
        vi invertices(n + 1, 0);
        for(int i = 0; i < m; ++i){
            int ini, fin;
            cin >> ini >> fin;
            ++invertices[fin];
            grafo[ini].push_back(fin);
        }

        vi dev = topo_sort_kahn(grafo, invertices);
        
        cout << dev[0];
        for(int i = 1; i < dev.size(); ++i) cout << " " << dev[i];

        cout << endl;
    }
    return 0;
}
