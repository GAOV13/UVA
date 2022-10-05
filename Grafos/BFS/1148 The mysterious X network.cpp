#include <bits/stdc++.h>

#define endl '\n'
#define vvi vector<vector<int> >
#define vi vector<int>
#define pii pair<int, int>
#define qpii queue<pair<int, int> >

using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        int tam;
        cin >> tam;
        vvi grafo(tam, vector<int>(0));
        for(int i = 0; i < tam; ++i){
            int quien, cant;
            cin >> quien >> cant;
            for(int j = 0; j < cant; ++j){
                int num;
                cin >> num;
                grafo[quien].push_back(num);
            }
        }

        vi visitado(tam, 0);
        int nodo_ini, nodo_fin;
        cin >> nodo_ini >> nodo_fin;
        ++visitado[nodo_ini];
        pii par = make_pair(nodo_ini, -1);
        qpii cola;
        cola.push(par);
        while(!cola.empty()){
            pii temp = cola.front(); cola.pop();
            if(temp.first == nodo_fin){
                visitado[nodo_fin] = temp.second;
                break;
            }

            for(int i = 0; i < grafo[temp.first].size(); ++i){
                int aux = grafo[temp.first][i];
                if(visitado[aux] == 0){
                    ++visitado[aux];
                    par.first = aux; par.second = temp.second + 1;
                    cola.push(par);
                }
            }
        }

        cout << nodo_ini << " " << nodo_fin << " " << visitado[nodo_fin] << endl; 
        if(n) cout << endl;
    }
    return 0;
}
