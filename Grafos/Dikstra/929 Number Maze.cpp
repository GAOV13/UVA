#include <bits/stdc++.h>

#define vvi vector<vector<int> >
#define vi vector<int>
#define pq priority_queue<pair<int, pair<int, int> > >
#define ppii pair<int, pair<int, int> >
#define pii pair<int, int>
#define endl '\n'

using namespace std;

int x[4] = {-1, 0, 1, 0};
int y[4] = {0, 1, 0, -1};

void dikstra(vvi &grafo_peso, vvi &dist){
    dist[0][0] = grafo_peso[0][0];
    pq cola;
    cola.push(make_pair(dist[0][0] * -1, make_pair(0, 0)));
    while(!cola.empty()){
        ppii par = cola.top(); cola.pop();
        int distancia = par.first * -1;
        int i = par.second.first, j = par.second.second;
        if(distancia == dist[i][j]){
            for(int k = 0; k < 4; ++k){
                if(i + x[k] >= 0 && i + x[k] < grafo_peso.size() && j + y[k] >= 0 && j + y[k] < grafo_peso[i].size()){
                    if(dist[i + x[k]][j + y[k]] == -1 || dist[i][j] + grafo_peso[i + x[k]][j + y[k]] < dist[i + x[k]][j + y[k]]){
                        dist[i + x[k]][j + y[k]] = dist[i][j] + grafo_peso[i + x[k]][j + y[k]];
                        cola.push(make_pair(dist[i + x[k]][j + y[k]]* - 1, make_pair(i + x[k], j + y[k])));
                    }
                }
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    while(n--){
        int fila, col;
        cin >> fila >> col;
        vvi grafo_peso(fila, vi(col));
        vvi dist(fila, vi(col, -1));
        for(int i = 0; i < fila; ++i){
            for(int j = 0; j < col; ++j){
                cin >> grafo_peso[i][j];
            }
        }

        dikstra(grafo_peso, dist);
        cout << dist[fila - 1][col - 1] << endl;
    }
    return 0;
}
