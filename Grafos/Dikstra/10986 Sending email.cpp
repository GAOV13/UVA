#include <bits/stdc++.h>

#define endl '\n'
#define vvpii vector<vector<pair<int, int> > >
#define vpii vector<pair<int, int> >
#define vi vector<int>
#define pqpii priority_queue<pair<int, int> >
#define pii pair<int, int>

using namespace std;

int main(){
    int n, caso = 0;
    cin >> n;
    while(n--){
        int cant, conec, inicio, fin;
        cin >> cant >> conec >> inicio >> fin;
        vvpii grafo(cant, vpii(0));
        vi camino_mas_corto(cant, (1 << 30));
        camino_mas_corto[inicio] = 0;
        vi visitado(cant, 0);
        for(int i = 0; i < conec; ++i){
            int nodo1, nodo2, tam;
            cin >> nodo1 >> nodo2 >> tam;
            pii par = make_pair(nodo2, tam);
            grafo[nodo1].push_back(par);
            par.first = nodo1;
            grafo[nodo2].push_back(par);
        }
        pqpii cola;
        pii par = make_pair(0, inicio);
        cola.push(par);
        while(!cola.empty()){
            par = cola.top(); cola.pop();
            if(!visitado[par.second]){ 
                ++visitado[par.second];
                if(par.second == fin) break;
                
                int nodo = par.second;
                for(int i = 0; i < grafo[nodo].size(); ++i){
                    pii temp = grafo[nodo][i];
                    int dist = par.first * -1, key = temp.first;
                    if(dist + temp.second < camino_mas_corto[key]){
                        camino_mas_corto[key] = dist + temp.second;
                        temp.first = camino_mas_corto[key] * -1;
                        temp.second = key;
                        cola.push(temp);
                    }
                }
            }
        }
        cout << "Case #" << ++caso << ": ";
        if(visitado[fin]) cout << camino_mas_corto[fin] << endl;

        else cout << "unreachable" << endl;
    }
    return 0;
}
