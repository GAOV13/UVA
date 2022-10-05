#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <queue>
#include <iterator>

#define endl '\n'
#define pii pair<int, int>
#define grafo map<int, vector<int> >
#define mipi map<int, pair<int, int> >
#define pii pair<int, int>

using namespace std;

int main(){
    int n, num = 0;
    cin >> n;
    while(n){
        grafo base_datos;
        mipi visitado;
        for(int i = 0; i < n; ++i){
            int nod1, nod2;
            cin >> nod1 >> nod2;
            base_datos[nod1].push_back(nod2);
            base_datos[nod2].push_back(nod1);
            visitado[nod1].first = 0; visitado[nod2].first = 0;
            visitado[nod1].second = 1; visitado[nod2].second = 1;
        }

        int start_node, ttl;
        cin >> start_node >> ttl;
        while(start_node || ttl){
            queue<pair<int, int> > cola;

            pii par = make_pair(start_node, ttl);
            ++visitado[start_node].first;
            cola.push(par);
            while(!cola.empty()){
                //cout << "hi";
                par = cola.front(); cola.pop();
                
                for(int i = 0; i < base_datos[par.first].size(); ++i){
                    int aux = base_datos[par.first][i];
                    if(visitado[aux].first == 0 && par.second - 1 >= 0){
                        pii temp = make_pair(aux, par.second - 1);
                        cola.push(temp);
                        ++visitado[aux].first;
                    }
                }
            }

            int cont = 0;
            mipi::iterator itr;
            for(itr = visitado.begin(); itr != visitado.end(); ++itr){
                //cout << itr->first << "->" << itr->second << endl;
                if(itr->second.first == 0 && itr->second.second == 1) ++cont;
                
                itr->second.first = 0;
            } 

            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", ++num, cont, start_node, ttl);
            cin >> start_node >> ttl;
        }

        cin >> n;
    }
    return 0;
}