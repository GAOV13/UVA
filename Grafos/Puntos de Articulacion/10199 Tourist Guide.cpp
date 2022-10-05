#include <bits/stdc++.h>

#define vvi vector<vector<int> >
#define vi vector<int>
#define vs vector<string>
#define msi map<string, int>
#define ss set<string>
#define endl '\n'

using namespace std;

ss dev;

void tarjan_apaux(vvi &grafo, vi &visitados, vi &low, vi &padre, int u, int &t, vs &numString){
    visitados[u] = low[u] = ++t;
    int conec = 0;
    for(int i = 0; i < grafo[u].size(); ++i){
        int w = grafo[u][i];
        if(!visitados[w]){
            conec++;
            padre[w] = u;
            tarjan_apaux(grafo, visitados, low, padre, w, t, numString);
            low[u] = min(low[u], low[w]);
            if(padre[u] != -1 && low[w] >= visitados[u]) dev.insert(numString[u]);
        }

        else if(w != padre[u]) low[u] = min(low[u], visitados[w]);
    }

    if(padre[u] == -1 && conec > 1) dev.insert(numString[u]);
}

void tarjan_apoints(vvi &grafo, vs &numString){
    int tam = grafo.size(), t = 0;
    vi visitados(tam, 0), padre(tam, -1), low(tam, 0);
    for(int i = 0; i < tam; ++i){
        if(!visitados[i])
            tarjan_apaux(grafo, visitados, low, padre, i, t, numString);
    }
}

int main(){
    int n, casos = 0;
    while(cin >> n, n){
        if(casos) cout << endl;

        msi stringNum;
        vs numString(n);
        vvi grafo(n);
        for(int i = 0; i < n; ++i){
            string temp;
            cin >> temp;
            stringNum[temp] = i;
            numString[i] = temp;
        }

        int m;
        cin >> m;
        for(int i = 0; i < m; ++i){
            string ini, fin;
            cin >> ini >> fin;
            int ini_n = stringNum[ini], fin_n = stringNum[fin];
            grafo[ini_n].push_back(fin_n);
            grafo[fin_n].push_back(ini_n);
        }

        dev.clear();
        tarjan_apoints(grafo, numString);
        cout << "City map #" << ++casos << ": " << dev.size() << " camera(s) found" << endl;
        for(auto itr = dev.begin(); itr != dev.end(); ++itr)
            cout << *itr << endl;
    }
    return 0;
}