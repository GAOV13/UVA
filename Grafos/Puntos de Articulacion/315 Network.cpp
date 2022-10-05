#include <bits/stdc++.h>

#define vvi vector<vector<int> >
#define vi vector<int>
#define si set<int>
#define endl '\n'

using namespace std;

si cant;

void tarjan_apaux(vvi &grafo, vi &visitados, vi &low, vi &padre, int u, int &t){
    visitados[u] = low[u] = ++t;
    int conec = 0;
    for(int i = 0; i < grafo[u].size(); ++i){
        int w = grafo[u][i];
        if(!visitados[w]){
            conec++;
            padre[w] = u;
            tarjan_apaux(grafo, visitados, low, padre, w, t);
            low[u] = min(low[u], low[w]);
            if(padre[u] && low[w] >= visitados[u]) cant.insert(u);
        }

        else if(w != padre[u]) low[u] = min(low[u], visitados[w]);
    }

    if(!padre[u] && conec > 1) cant.insert(u);
}

void tarjan_apoints(vvi &grafo){
    int tam = grafo.size(), t = 0;
    vi visitados(tam, 0), padre(tam, 0), low(tam, 0);
    for(int i = 1; i < tam; ++i){
        if(!visitados[i])
            tarjan_apaux(grafo, visitados, low, padre, i, t);
    }
}

int string_numero(string str){
    stringstream stream(str);
    int n;
    stream >> n;
    return n;
}

vi lectura(string str){
    vi temp;
    stringstream stream(str);
    int i = 0;
    while(getline(stream, str, ' ')){
        if(i == 0) i = string_numero(str);

        else temp.push_back(string_numero(str));
    }
    temp.push_back(i);
    return temp;
}

int main(){
    int n;
    while(cin >> n, n){
        cin.ignore();
        string temp;
        vvi grafo(n + 1);
        getline(cin, temp);
        while(temp != "0"){
            vi aristas = lectura(temp);
            int ini = aristas[aristas.size() - 1];
            aristas.pop_back();
            for(int i = 0; i < aristas.size(); ++i){
                int fin = aristas[i];
                grafo[fin].push_back(ini);
                grafo[ini].push_back(fin);
            }
            getline(cin, temp);
        }
        
        cant.clear();
        tarjan_apoints(grafo);
        cout << cant.size() << endl;
    }
    return 0;
}
