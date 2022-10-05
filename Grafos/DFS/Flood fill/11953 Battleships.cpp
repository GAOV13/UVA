#include <bits/stdc++.h>

#define endl '\n'
#define vs vector<string>
#define vi vector<int>

using namespace std;

vi ejex = {1, 0, -1, 0};
vi ejey = {0, -1, 0, 1};

void dfs(vs &grafo, int i, int j, int &tam, bool &ver){
    if(grafo[i][j] == 'x') ver = true;
    grafo[i][j] = '.';
    for(int k = 0; k < 4; ++k){
        int x = j + ejey[k], y = i + ejex[k];
        if(x >= 0 && x < tam && y >= 0 && y < tam){
            if(grafo[y][x] == 'x' || grafo[y][x] == '@') dfs(grafo, y, x, tam, ver);
        }
    }
}

int main(){
    int n, m, casos = 0;
    cin >> n;
    while(n--){
        cin >> m;
        vs grafo(m);
        int dev = 0;
        for(int i = 0; i < m; ++i) cin >> grafo[i];

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < m; ++j){
                if(grafo[i][j] != '.'){
                    bool ver = false;
                    dfs(grafo, i, j, m, ver);
                    if(ver) ++dev;
                }
            }
        }
        cout << "Case " << ++casos << ": " << dev << endl;
    }
    return 0;
}