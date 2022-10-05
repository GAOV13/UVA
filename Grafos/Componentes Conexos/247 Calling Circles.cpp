#include <bits/stdc++.h>

#define msvs map<string, vector<string>>
#define vs vector<string>
#define vvs vector<vector<string> >
#define msi map<string, int>
#define endl '\n'

using namespace std;

vvs dev;
vs temp;
vs fin_tempo;

void dfs_aux(msvs &grafo, msi &visitados, string u){
    for(int i = 0; i < grafo[u].size(); ++i){
        string j = grafo[u][i];
        if(!visitados[j]++)
            dfs_aux(grafo, visitados, j);
    }
    temp.push_back(u);
}

void dfs(msvs &grafo){
    msi visitados;
    for(auto itr = grafo.begin(); itr != grafo.end(); ++itr)
        visitados[itr->first] = 0;
    
    fin_tempo.clear();
    for(auto itr = visitados.begin(); itr != visitados.end(); ++itr){
        if(!(itr->second)){
            dfs_aux(grafo, visitados, itr->first);
        }
    }
    fin_tempo = temp;
    return;
}

void kosaraju(msvs &grafo, vs &tempo){
    msi visitados;
    msvs grafo_transpuesto;
    for(auto itr = grafo.begin(); itr != grafo.end(); ++itr){
        grafo_transpuesto[itr->first];
        for(int j = 0; j < itr->second.size(); ++j){
            grafo_transpuesto[itr->second[j]].push_back(itr->first);
        }
    }

    for(auto itr = grafo.begin(); itr != grafo.end(); ++itr)
        visitados[itr->first] = 0;
    
    dev.clear();
    for(int i = tempo.size() - 1; i >= 0; --i){
        temp.clear();
        if(!visitados[tempo[i]]++){
            dfs_aux(grafo_transpuesto, visitados, tempo[i]);
            dev.push_back(temp);
        }
    }
}

int main(){
    int n, conec;
    int casos = 0;
    cin >> n >> conec;
    msvs grafo;
    while(n || conec){
        if(casos) cout << endl;

        string ini, fin;
        grafo.clear();
        dev.clear();
        temp.clear();
        fin_tempo.clear();
        for(int i = 0; i < conec; ++i){
            cin >> ini >> fin;
            grafo[ini].push_back(fin);
            grafo[fin];
        }
        
        dfs(grafo);
        kosaraju(grafo, fin_tempo);
        cout << "Calling circles for data set " << ++casos << ":" << endl;
        for(int i = 0; i < dev.size(); ++i){
            if(dev[i].size()) cout << dev[i][0];

            for(int j = 1; j < dev[i].size(); ++j)
                cout << ", " << dev[i][j];

            cout << endl;
        }
        cin >> n >> conec;
    }
    return 0;
}
