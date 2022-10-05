#include <bits/stdc++.h>

#define endl '\n'
#define vs vector<string>
#define vi vector<int>

using namespace std;

vi ejex = {0, 1, 1, 1, 0, -1, -1, -1};
vi ejey = {1, 1, 0, -1, -1, -1, 0, 1};

void dfs(vs &grafo, int i, int j, int &tam){
    grafo[i][j] = '0';
    for(int k = 0; k < 8; ++k){
        int x = j + ejey[k], y = i + ejex[k];
        if(x >= 0 && x < tam && y >= 0 && y < tam && grafo[y][x] == '1') dfs(grafo, y, x, tam);
    }
}

int main(){
    int n, casos = 0;
    while(cin >> n){
        vs grafo(n);
        int dev = 0;
        for(int i = 0; i < n; ++i) cin >> grafo[i];

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(grafo[i][j] == '1'){
                    ++dev;
                    dfs(grafo, i, j, n);
                }
            }
        }
        cout << "Image number " << ++casos << " contains " << dev << " war eagles." << endl;
    }
    return 0;
}