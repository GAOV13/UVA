#include <bits/stdc++.h>

#define vi vector<int>
#define vvi vector<vector<int> >
#define endl '\n'

using namespace std;

int n, m;
bool ver;

void phi(vi &visitados, vi temp, vvi &grafo, int u){
    if(temp.size() == m+1){
        ver = true;
        cout << "(" << temp[0]+1;
        for(int i = 1; i <= m; ++i)
            cout << "," << temp[i]+1;
        cout << ")" << endl;
    }
    else{
        for(int i=0; i < n; ++i){
            if(grafo[u][i] && visitados[i]){
                visitados[i] = 0;
                temp.push_back(i);
                phi(visitados, temp, grafo, i);
                temp.pop_back();
                visitados[i] = 1;
            }
        }
    }
}

int main(){
    bool temp = false;
    while(cin >> n >> m){
        if(temp)
            cout << endl;
        temp = true;
        vvi grafo(n, vi(n));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j)
                cin >> grafo[i][j];
        }
        int t;
        cin >> t;
        vi visitados(n,1);
        visitados[0] = 0;
        ver = false;
        if(n > m)
            phi(visitados, vi(1,0), grafo, 0);
        if(!ver)
            cout << "no walk of length " << m << endl;
    }
    return 0;
}