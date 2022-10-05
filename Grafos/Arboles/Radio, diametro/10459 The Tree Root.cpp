#include <bits/stdc++.h>

#define vvi vector<vector<int> >
#define vi vector<int>
#define qi queue<int>
#define endl '\n'

using namespace std;

void dfs(vvi &tree, vi &padre, int u, int dist, int &distMax, int &nodoMax){
    for(int i = 0; i < tree[u].size(); ++i){
        int v = tree[u][i];
        if(v != padre[u]){
            padre[v] = u;
            dfs(tree, padre, v, dist + 1, distMax, nodoMax);
        }
    }

    if(dist > distMax){
        distMax = dist;
        nodoMax = u;
    }
}

vi bfs(vvi &tree, int u){
    vi visitados(tree.size()), dev;
    visitados[u] = 1;
    qi cola;
    int altura = 1;
    dev.push_back(u);
    cola.push(u);
    while(!cola.empty()){
        u = cola.front(); cola.pop();
        for(int i = 0; i < tree[u].size(); ++i){
            int v = tree[u][i];
            if(!visitados[v]){
                visitados[v] = visitados[u] + 1;
                cola.push(v);
                if(visitados[v] == altura) dev.push_back(v);

                else{
                    altura = visitados[v];
                    dev.clear();
                    dev.push_back(v);
                }
            }
        }
    }

    return dev;
}

int diametro(vvi &tree, vi &ruta){
    vi padre(tree.size());
    int distMax = 0, nodoMax = 0;
    dfs(tree, padre, 1, 0, distMax, nodoMax);
    fill(padre.begin(), padre.end(), 0);
    distMax = 0;
    dfs(tree, padre, nodoMax, 0, distMax, nodoMax);
    while(nodoMax != 0){
        ruta.push_back(nodoMax);
        nodoMax = padre[nodoMax];
    }

    return distMax;
}

int main(){
    int n, m, k;
    while(cin >> n){
        vvi tree(n + 1);
        for(int i = 1; i < n + 1; ++i){
            cin >> m;
            for(int j = 0; j < m; ++j){
                cin >> k;
                tree[i].push_back(k);
            }
        }
        vi ruta, mejores, peores;
        int dist = diametro(tree, ruta);
        mejores.push_back(ruta[(dist + 1)/2]);
        if(dist % 2 == 1) mejores.push_back(ruta[((dist + 1)/2) - 1]);

        for(int i = 0; i < mejores.size(); ++i){
            vi temp = bfs(tree, mejores[i]);
            peores.insert(peores.end(), temp.begin(), temp.end());
        }
        
        sort(mejores.begin(), mejores.end());
        sort(peores.begin(), peores.end());
        cout << "Best Roots  :";
        for(int i = 0; i < mejores.size(); ++i) cout << " " << mejores[i];

        cout << "\nWorst Roots :";
        for(int i = 0; i < peores.size(); ++i) cout << " " << peores[i];

        cout << endl;
    }
    return 0;
}