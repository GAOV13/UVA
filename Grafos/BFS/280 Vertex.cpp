#include <bits/stdc++.h>

#define vvi vector<vector<int> >
#define vi vector<int>
#define qi queue<int>
#define endl '\n'

using namespace std;

int main(){
    int n;
    cin >> n;
    while(n){
        vvi grafo(n + 1);
        int m;
        cin >> m;
        while(m){
            int nodo;
            cin >> nodo;
            while(nodo){
                grafo[m].push_back(nodo);
                cin >> nodo;
            }
            cin >> m;
        }

        cin >> m;
        for(int i = 0; i < m; ++i){
            vi visitado(n + 1, 0);
            int nodo_busqueda;
            cin >> nodo_busqueda;
            qi cola;
            cola.push(nodo_busqueda);
            while(!cola.empty()){
                int u = cola.front(); cola.pop();
                for(int j = 0; j < grafo[u].size(); ++j){
                    int key = grafo[u][j];
                    if(!visitado[key]){
                        ++visitado[key];
                        cola.push(key);
                    }
                }
            }

            int cant = 0;
            vi dev;
            for(int j = 1; j < n + 1; ++j){
                if(!visitado[j]){
                    dev.push_back(j);
                    ++cant;
                }
            }

            cout << cant;
            for(int j = 0; j < dev.size(); ++j){
                cout << " " << dev[j];
            }
            cout << endl;
        }
        cin >> n;
    }
    return 0;
}