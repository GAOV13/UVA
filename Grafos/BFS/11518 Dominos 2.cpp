#include <bits/stdc++.h>

#define vvi vector<vector<int> >
#define vi vector<int>
#define qi queue<int>
#define endl '\n'

using namespace std;

int bfs(vvi &grafo, vi &visitados, vi manual){
    qi cola;
    int dev = 0, u, v;
    for(int i = 0; i < manual.size(); ++i){
        cola.push(manual[i]);
        if(!visitados[manual[i]]++) dev++;
    }

    while(!cola.empty()){
        u = cola.front(); cola.pop();
        for(int i = 0; i < grafo[u].size(); ++i){
            v = grafo[u][i];
            if(!visitados[v]++){
                cola.push(v);
                ++dev;
            }
        }
    }
    return dev;
}

int main(){
    int n;
    int nodos, aristas, man;
    cin >> n;
    while(n--){
        cin >> nodos >> aristas >> man;
        vvi grafo(nodos + 1);
        vi visitados(nodos + 1);
        vi manual(man);
        for(int i = 0; i < aristas; ++i){
            int u, v;
            cin >> u >> v;
            grafo[u].push_back(v);
        }

        for(int i = 0; i < man; ++i) cin >> manual[i];
        
        cout << bfs(grafo, visitados, manual) << endl;
    }

    return 0;
}