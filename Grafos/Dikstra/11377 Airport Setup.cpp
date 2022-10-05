#include <bits/stdc++.h>

#define vvi vector<vector<int> >
#define vi vector<int>
#define pqpii priority_queue<pair<int, int> >
#define pii pair<int, int>
#define endl '\n'

using namespace std;

bool dikstra(vvi &grafo, vi &visitados, vi &aeropuertos, int ini, int fin){
    pqpii cola;
    visitados[ini] = aeropuertos[ini];
    if(ini == fin) visitados[ini] = 0;

    cola.push(make_pair(visitados[ini] * -1, ini));
    while(!cola.empty()){
        pii par = cola.top(); cola.pop();
        int peso = par.first * -1, u = par.second;
        if(u == fin) return true;

        if(visitados[u] == peso){
            for(int i = 0; i < grafo[u].size(); ++i){
                int v = grafo[u][i];
                if(peso + aeropuertos[v] < visitados[v]){
                    visitados[v] = peso + aeropuertos[v];
                    cola.push(make_pair(visitados[v] * -1, v));
                }
            }
        }
    }

    return false;
}

int main(){
    int n, casos = 0;
    cin >> n; 
    while(n--){
        int nodos, conec, k;
        cin >> nodos >> conec >> k;
        vvi grafo(nodos + 1);
        vi aeropuertos(nodos + 1, 1);
        for(int i = 0; i < k; ++i){
            int temp;
            cin >> temp;
            aeropuertos[temp] = 0;
        }

        for(int i = 0; i < conec; ++i){
            int ini, fin;
            cin >> ini >> fin;
            grafo[ini].push_back(fin);
            grafo[fin].push_back(ini);
        }

        cout << "Case " << ++casos << ":" << endl;
        cin >> k;
        for(int i = 0; i < k; ++i){
            int ini, fin;
            cin >> ini >> fin;
            vi visitados(nodos + 1, 2147483647);
            int conteo = -1;
            if(dikstra(grafo, visitados, aeropuertos, ini, fin)) conteo = visitados[fin];

            cout << conteo << endl;
        }

        cout << endl;
    }
    return 0;
} 
