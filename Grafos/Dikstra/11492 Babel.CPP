#include <bits/stdc++.h>

#define msi map<string, int>
#define mpi map<pair<string, int>, int>
#define vvp vector<vector<pair<int, string> > >
#define vp vector<pair<int, string> >
#define pqT priority_queue<tuple<int, int, string> >
#define endl '\n'
#define MAX 2147483647

using namespace std;

int disktra(vvp &grafo, mpi &visitados){
    int peso, u;
    string pal, ini;
    visitados[make_pair("$", 1)] = 0;
    pqT cola;
    cola.push(make_tuple(0, 1, "$"));
    while(!cola.empty()){
        tie(peso, u, pal) = cola.top(); cola.pop();
        if(u == 2) 
            return peso * -1;
        peso *= -1;
        if(peso == visitados[make_pair(pal, u)]){
            for(int i = 0; i < grafo[u].size(); ++i){
                int v = grafo[u][i].first;
                string temp = grafo[u][i].second;
                if(temp[0] != pal[0] && peso + temp.size() < visitados[make_pair(temp, v)]){
                    visitados[make_pair(temp, v)] = peso + temp.size();
                    cola.push(make_tuple((peso + temp.size()) * -1, v, temp));
                }
            }
        }
    }
    return 0;
}

int main(){
    int n, tam, res;
    string ini, fin, pal;
    string salida, llegada;
    while(cin >> n, n){
        msi info;
        mpi visitados;
        vvp grafo(3);
        cin >> salida >> llegada;
        tam = 1;
        info[salida] = tam++;
        info[llegada] = tam++;
        for(int i = 0; i < n; i++){
            cin >> ini >> fin >> pal;
            int ini_i, fin_i;
            if(info[ini]) 
                ini_i = info[ini];
            else{
                ini_i = tam;
                info[ini] = tam++;
                grafo.push_back(vp());
            }
            if(info[fin]) 
                fin_i = info[fin];
            else{
                fin_i = tam;
                info[fin] = tam++;
                grafo.push_back(vp());
            }
            visitados[make_pair(pal, ini_i)] = MAX;
            visitados[make_pair(pal, fin_i)] = MAX;
            grafo[ini_i].push_back(make_pair(fin_i, pal));
            grafo[fin_i].push_back(make_pair(ini_i, pal));
        }
        res = disktra(grafo, visitados);
        if(!res) 
            cout << "impossivel" << endl;
        else 
            cout << res << endl;
    }
    return 0;
}
