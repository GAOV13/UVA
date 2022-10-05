#include <bits/stdc++.h>

#define vvi vector<vector<int> >
#define vi vector<int>
#define endl '\n'

using namespace std;

void dfs(int u, vvi &grafo, vi &visitados){
    for(int i = 0; i < grafo[u].size(); ++i){
        int nodo = grafo[u][i];
        if(!visitados[nodo]){
            ++visitados[nodo];
            dfs(nodo, grafo, visitados);
        }
    }
}

int dfs_aux(vvi &grafo, vi &visitados){
    int num = 0;
    for(int i = 0; i < visitados.size(); ++i){
        if(!visitados[i]){
            ++num;
            dfs(i, grafo, visitados);
        }
    }
    return num;
}

int main(){
    bool ver = false;
    int n;
    cin >> n;
    cin.ignore();
    cin.ignore();
    while(n--){
        if(ver) cout << endl;

        ver = true;
        string temp;
        getline(cin, temp);
        vvi grafo((int)temp[0] - 64);
        vi visitados((int)temp[0] - 64);
        while(getline(cin, temp)){
            if(temp == "") break;

            int ini, fin;
            ini = (int)temp[0] - 65;
            fin = (int)temp[1] - 65;
            grafo[ini].push_back(fin);
            grafo[fin].push_back(ini);
        }
        
        cout << dfs_aux(grafo, visitados) << endl;
    }
}
