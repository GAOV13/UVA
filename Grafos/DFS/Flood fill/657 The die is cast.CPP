#include <bits/stdc++.h>

#define vs vector<string>
#define vp vector<pair<int, int> >
#define vi vector<int>

#define endl '\n'

using namespace std;

int ejex[4] = {0, 1, 0, -1};
int ejey[4] = {1, 0, -1, 0};
vp temp;

void dfs(vs &grafo, int i, int j, int &tamf, int &tamc, char c, int &val){
    grafo[i][j] = '.';
    if(c == 'X'){
        for(int k = 0; k < 4; ++k){
            int x = j + ejex[k], y = i + ejey[k];
            if(x >= 0 && x < tamc && y >= 0 && y < tamf){
                if(grafo[y][x] == 'X')
                    dfs(grafo, y, x, tamf, tamc, c, val);
                else if(grafo[y][x] == '*')
                    temp.push_back(make_pair(y, x));
            }    
        } 
    }

    else{
        for(int k = 0; k < 4; ++k){
            int x = j + ejex[k], y = i + ejey[k];
            if(x >= 0 && x < tamc && y >= 0 && y < tamf){
                if(grafo[y][x] == 'X')
                    dfs(grafo, y, x, tamf, tamc, 'X', ++val);
                else if(grafo[y][x] == '*')
                    dfs(grafo, y, x, tamf, tamc, '*', val);
            }
        }
    }
}



int main(){
    int fil, col, casos = 0;
    while(cin >> col >> fil, fil && col){
        vs grafo(fil);
        vi dev;
        temp.clear();
        for(int i = 0; i < fil; ++i) cin >> grafo[i];

        for(int i = 0; i < fil; ++i){
            for(int j = 0; j < col; ++j){
                if(grafo[i][j] == 'X'){
                    int num = 1;
                    dfs(grafo, i, j, fil, col, 'X', num);
                    for(int k = 0; k < temp.size(); ++k)
                        dfs(grafo, temp[k].first, temp[k].second, fil, col, '*', num);
                    if(num <= 6) dev.push_back(num);
                }
            }
        }

        sort(dev.begin(), dev.end());
        cout << "Throw " << ++casos << endl;
        for(int i = 0; i < dev.size(); ++i){
            if(i) cout << " ";

            cout << dev[i];
        }
        cout << "\n" << endl;
    }
    return 0;
}