#include <bits/stdc++.h>

#define vvp vector<vector<pair<int, int> > >
#define endl '\n'

using namespace std;

void dfs(vvp &grafo, int u, int padre, int peso, int &dist, int &quien){
    for(int i = 0; i < grafo[u].size(); ++i){
        int v = grafo[u][i].first, temp = grafo[u][i].second;
        if(v != padre) dfs(grafo, v, u, peso + temp, dist, quien);
    }

    if(peso > dist){
        dist = peso;
        quien = u;
    }
}

int main(){
    string temp;
    bool ver = true;
    while(ver){
        vvp grafo(10001); 
        bool ver1 = true;
        while(getline(cin, temp)){
            if(temp == ""){
                ver1 = false;
                break;
            }
            stringstream stream(temp);
            int ini, fin, peso;
            stream >> ini >> fin >> peso;
            grafo[ini].push_back(make_pair(fin, peso));
            grafo[fin].push_back(make_pair(ini, peso));
        }
        if(ver1) ver = false;

        int dist = 0, quien = 0;
        dfs(grafo, 1, 0, 0, dist, quien);
        dfs(grafo, quien, 0, 0, dist, quien);
        cout << dist << endl;
    }
}
