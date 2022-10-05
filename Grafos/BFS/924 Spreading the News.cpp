#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <iterator>

#define endl '\n'
#define mii map<int, int>
#define vi vector<int>
#define pii pair<int, int>

using namespace std;

int main(){
    int n, m;
    vector<vi> listado;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> m;
        vi temp;
        listado.push_back(temp);
        for(int j = 0; j < m; ++j){
            int k;
            cin >> k;
            listado[i].push_back(k);
        }
    }

    cin >> m;
    while(m--){
        int per;
        int bum = 0, cant = 0;
        cin >> per;
        vi visitados(n, 0);
        mii dias;
        dias[bum] = 0;
        visitados[per] = 1;
        queue<pair<int, int> > cola;
        pii pair = make_pair(per, 0);
        cola.push(pair);
        while(!cola.empty()){
            pair = cola.front(); cola.pop();
           //cout << pair.first << "->" << pair.second << endl;
            int aux, aux1 = pair.first, dia = pair.second;
            for(int i = 0; i < listado[aux1].size(); ++i){
                aux = listado[aux1][i];
                if(visitados[aux] == 0){
                    pair.first = aux; pair.second = dia + 1;
                    ++visitados[aux];
                    cola.push(pair);
                    ++dias[pair.second];
                }
            }
        }
        mii::iterator itr;
        for(itr = dias.begin(); itr != dias.end(); ++itr){
            if(cant < itr->second){
                cant = itr->second;
                bum = itr->first;
            }
        }

        if(bum == 0) cout << bum << endl;

        else cout << cant << " " << bum << endl;
    }
    return 0;
}