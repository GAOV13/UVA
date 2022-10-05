#include <bits/stdc++.h>

#define endl '\n'
#define vs vector<string>

using namespace std;

int ejex[4] = {0, 1, 0, -1};
int ejey[4] = {1, 0, -1, 0};

void dfs(vs &grafo, int i, int j, int &tamf, int &tamc, int &dev){
    grafo[i][j] = '#';
    bool ver = true;
    for(int k = 0; k < 4 && ver; ++k){
        int x = j + ejex[k], y = i + ejey[k];
        if(grafo[y][x] == 'T') ver = false;
    }

    for(int k = 0; k < 4 && ver; ++k){
        int x = j + ejex[k], y = i + ejey[k];
        if(grafo[y][x] == '.')
            dfs(grafo, y, x, tamf, tamc, dev);
        else if(grafo[y][x] == 'G')
            dfs(grafo, y, x, tamf, tamc, ++dev);
    }
}

int main(){
    int col, fil;
    while(cin >> col >> fil){
        vs grafo(fil);
        for(int i = 0; i < fil; ++i) cin >> grafo[i];

        bool ver = true;
        for(int i = 1; i < fil && ver; ++i){
            for(int j = 1; j < col && ver; ++j){
                if(grafo[i][j] == 'P'){
                    ver = false;
                    int dev = 0;
                    dfs(grafo, i, j, fil, col, dev);
                    cout << dev << endl;
                }
            }
        }
    }
    return 0;
}