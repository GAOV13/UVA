#include <bits/stdc++.h>

#define endl '\n'
#define vs vector<string>
#define mci map<char, int>
#define pic pair<char, int>
#define vpic vector<pair<int, char> >

using namespace std;

int ejex[4] = {0, 1, 0, -1};
int ejey[4] = {1, 0, -1, 0};

bool comparador(pic par1, pic par2){
    if(par1.first == par2.first)
        return par1.second < par2.second;
    
    return par1.first > par2.first;
}

void dfs(vs &grafo, int i, int j, int &tamf, int &tamc, char &c){
    grafo[i][j] = '.';
    for(int k = 0; k < 4; ++k){
        int x = j + ejex[k], y = i + ejey[k];
        if(x >= 0 && x < tamc && y >= 0 && y < tamf && grafo[y][x] == c)
            dfs(grafo, y, x, tamf, tamc, c);
    }
}

int main(){
    int n, casos = 0;
    cin >> n;
    while(n--){
        int fil, col;
        cin >> fil >> col;
        vs grafo(fil);
        mci mapa;
        for(int i = 0; i < fil; ++i) cin >> grafo[i];

        for(int i = 0; i < fil; ++i){
            for(int j = 0; j < col; ++j){
                if(grafo[i][j] != '.'){
                    char c = grafo[i][j];
                    ++mapa[c];
                    dfs(grafo, i, j, fil, col, c);
                }
            }
        }

        vpic dev;
        for(mci::iterator itr = mapa.begin(); itr != mapa.end(); ++itr){
            pic par = make_pair(itr->second, itr->first);
            dev.push_back(par);
        }
        sort(dev.begin(), dev.end(), comparador);
        cout << "World #" << ++casos << endl;
        for(int i = 0; i < dev.size(); ++i)
            cout << dev[i].second << ": " << dev[i].first << endl;
    }
    return 0;
}