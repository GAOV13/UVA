#include <bits/stdc++.h>

#define vs vector<string>
#define vpii vector<pair<int, int> >
#define vvi vector<vector<int> >
#define vi vector<int>
#define pii pair<int, int>
#define qpii queue<pair<int, int> >
#define endl '\n'


using namespace std;

int ejex[4] = {0, 1, 0, -1};
int ejey[4] = {1, 0, -1, 0};
int num;

void bfs(vs &grafo, vvi &visitados, int i, int j, int &tami, int &tamj, char c){
    qpii cola;
    pii par = make_pair(i, j);
    cola.push(par);
    int temp;
    while(!cola.empty()){
        par = cola.front(); cola.pop();
        for(int k = 0; k < 4; k++){
            i = par.first + ejex[k];
            j = par.second + ejey[k];
            int vis = visitados[i - ejex[k]][j - ejey[k]];
            if(i < tami && i >= 0 && j < tamj && j >= 0){
                if(grafo[i][j] != '#'){
                    if(visitados[i][j] == -1 ||  vis + 1 < visitados[i][j]){
                        visitados[i][j] = vis + 1;
                        pii par1 = make_pair(i, j);
                        cola.push(par1);
                    }
                }
            }

            else if(c == 'J'){
                num = vis + 1;
                return;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    while(n--){
        int fil, col;
        cin >> fil >> col;
        vs grafo(fil);
        string temp;
        vpii fuego;
        pii ini;
        for(int i = 0; i < fil; ++i){
            cin >> temp;
            grafo[i] = temp;
            for(int j = 0; j < col; ++j){
                if(temp[j] == 'F'){
                    pii par = make_pair(i, j);
                    fuego.push_back(par);
                }

                else if(temp[j] == 'J') ini = make_pair(i, j);
            }
        }

        vvi visitados(fil, vi(col, -1));
        for(int i = 0; i < fuego.size(); ++i){
            visitados[fuego[i].first][fuego[i].second] = 0;
            bfs(grafo, visitados, fuego[i].first, fuego[i].second, fil, col, 'F');
        }

        num = 0;
        visitados[ini.first][ini.second] = 0;
        bfs(grafo, visitados, ini.first, ini.second, fil, col, 'J');
        if(num) cout << num << endl;

        else cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
