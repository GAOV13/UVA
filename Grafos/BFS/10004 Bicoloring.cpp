#include <bits/stdc++.h>

#define endl '\n'
#define vvi vector<vector<int> >
#define si stack<int>
#define vi vector<int>
#define qi queue<int>

using namespace std;

int main(){
    int n;
    cin >> n;
    while(n){
        int m;
        cin >> m;
        vvi grafo(n, vi(0, 0));
        vi visitado(n, 0);
        vi padre(n, -1);
        while(m--){
            int nodo1, nodo2;
            cin >> nodo1 >> nodo2;
            grafo[nodo1].push_back(nodo2);
            grafo[nodo2].push_back(nodo1);
        }

        qi cola;
        int col = 0;
        cola.push(0);
        visitado[0] = 1;
        bool ver = true;
        while(!cola.empty()){
            int nodo = cola.front(); cola.pop();
            int color_actual = (visitado[nodo]%2) + 1;
            for(int i = 0; i < grafo[nodo].size(); ++i){
                int key = grafo[nodo][i];
                if(!visitado[key]){
                    visitado[key] = color_actual;
                    padre[key] = nodo;
                    cola.push(key);
                }

                else if(visitado[padre[key]] == color_actual){
                    ver = false;
                    break;
                }
            }
        }

        if(ver) cout << "BICOLORABLE." << endl;

        else cout << "NOT BICOLORABLE." << endl;
        
        cin >> n;
    }
}
