#include <bits/stdc++.h>

#define endl '\n'
#define vs vector<string>
#define pci pair<int, char>
#define vpci vector<pair<int, char> >

using namespace std;

int ejex[4] = {0, 1, 0, -1};
int ejey[4] = {1, 0, -1, 0};


void dfs(vs &grafo, int i, int j, int &tamf, int &tamc, char &c, int &num){
    grafo[i][j] = '.';
    for(int k = 0; k < 4; ++k){
        int x = j + ejex[k], y = i + ejey[k];
        if(x >= 0 && y >= 0 && x < tamc && y < tamf && grafo[y][x] == c)
            dfs(grafo, y, x, tamf, tamc, c, ++num);
    }
}

int main(){
    int fil, col, casos = 0;
    while(cin >> fil >> col, fil && col){
        vs grafo(fil);
        vpci dev;
        for(int i = 0; i < fil; ++i) cin >> grafo[i];

        for(int i = 0; i < fil; ++i){
            for(int j = 0; j < col; ++j){
                if(grafo[i][j] != '.'){
                    char c = grafo[i][j];
                    int num = 1;
                    dfs(grafo, i, j, fil, col, c, num);
                    dev.push_back(make_pair(num * -1, c));
                }
            }
        }
        sort(dev.begin(), dev.end());
        cout << "Problem " << ++casos << ":" << endl;
        for(int i = 0; i < dev.size(); ++i)
            cout << dev[i].second << " " << -1 * dev[i].first << endl;
    }
    return 0;
}