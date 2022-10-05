#include <bits/stdc++.h>

#define endl '\n'
#define vs vector<string>
#define vi vector<int>

using namespace std;

vi ejex = {0, 1, 1, 1, 0, -1, -1, -1};
vi ejey = {1, 1, 0, -1, -1, -1, 0, 1};

int dfs(vs &grafo, int i, int j, int &tamf, int &tamc){
    grafo[i][j] = '.';
    int temp = 0;
    for(int k = 0; k < 8; ++k){
        int x = j + ejex[k], y = i + ejey[k];
        if(x >= 0 && x < tamc && y >= 0 && y < tamf && grafo[y][x] == '*')
            temp = dfs(grafo, y, x, tamf, tamc);
    }
    return 1 + temp;
}

int main(){
    int n, m;
    while(cin >> n >> m, n && m){
        vs grafo(n);
        int dev = 0;
        for(int i = 0; i < n; ++i) cin >> grafo[i];

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grafo[i][j] == '*'){
                    if(dfs(grafo, i, j, n, m) == 1) ++dev;
                }
            }
        }
        cout << dev << endl;
    }
    return 0;
}