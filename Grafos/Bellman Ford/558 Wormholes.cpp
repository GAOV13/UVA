#include <bits/stdc++.h>

#define vvpii vector<vector<pair<int, int> > >
#define pii pair<int, int>
#define vi vector<int>
#define qi queue<int>
#define endl '\n'

using namespace std;

bool belman_ford(vvpii &grafo){
    vi dist(grafo.size(), 2147483647);
    vi conteo(grafo.size());
    vi enCola(grafo.size());
    qi cola;
    dist[0] = 0;
    cola.push(0);
    while(!cola.empty()){
        int u = cola.front(); cola.pop();
        enCola[u] = 0;
        for(int i = 0; i < grafo[u].size(); ++i){
            pii par = grafo[u][i];
            if(dist[u] + par.second < dist[par.first]){
                dist[par.first] = dist[u] + par.second;
                if(!enCola[par.first]){
                    ++enCola[par.first];
                    cola.push(par.first);
                    ++conteo[par.first];
                    if(conteo[par.first] > grafo.size()) return true;
                }

            }
        }
    }
    return false;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        int nodo, m;
        cin >> nodo >> m;
        vvpii grafo(nodo);
        for(int i = 0; i < m; ++i){
            int ini, fin, dist;
            cin >> ini >> fin >> dist;
            grafo[ini].push_back(make_pair(fin, dist));
        }

        if(belman_ford(grafo)) cout << "possible" << endl;

        else cout << "not possible" << endl;
    }
    return 0;
}
