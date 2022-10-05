#include <bits/stdc++.h>

#define endl '\n'
#define vs vector<string>
#define vi vector<int>

using namespace std;

vi ejex = {1, 1, 0, -1, -1, -1, 0, 1};
vi ejey = {0, -1, -1, -1, 0, 1, 1, 1};

void dfs(vs &grafo, int i, int j, int &tamf, int &tamc){
    for(int k = 0; k < 8; k++){
        int x = j + ejex[k], y = i + ejey[k];
        if(y >= 0 && y < tamf && x >= 0 && x < tamc && grafo[y][x] == '@'){
            grafo[y][x] = '*';
            dfs(grafo, y, x, tamf, tamc);
        }
    }
}

int main(){
    int n, m;
    while(cin >> n >> m, n && m){
        int dev = 0;
        vs grafo(n);
        for(int i = 0; i < n; ++i) cin >> grafo[i];

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grafo[i][j] == '@'){
                    ++dev;
                    dfs(grafo, i, j, n, m);
                }
            }
        }
        cout << dev << endl;
    }
    return 0;
}