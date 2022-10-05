#include <bits/stdc++.h>

#define vvs vector<vector<char> >
#define vvi vector<vector<int> >
#define vvpii vector<vector<pair<int, int> > >
#define vpii vector<pair<int, int> >
#define pii pair<int, int>
#define vs vector<char>
#define vi vector<int>
#define endl '\n'

using namespace std;

int x, y;
int ini_x, ini_y;

bool ver;

void dfs(vvi &visitados, vvs &grafo, vvpii &padre,int i, int j, int &conteo){
    if(grafo[i][j] == '-') ver = true;

    if(grafo[i][j] == 'N'){
        if(visitados[i - 1][j]){
            ini_x = i - 1; ini_y = j;
            x = i; y = j;
            return;
        }
        padre[i - 1][j].first = i;
        padre[i - 1][j].second = j;
        visitados[i - 1][j] = 1;
        ++conteo;
        dfs(visitados, grafo, padre, i - 1, j, conteo);
    } 

    else if(grafo[i][j] == 'S'){
        if(visitados[i + 1][j]){
            ini_x = i + 1; ini_y = j;
            x = i; y = j;
            return;
        }
        padre[i + 1][j].first = i;
        padre[i + 1][j].second = j;
        visitados[i + 1][j] = 1;
        ++conteo;
        dfs(visitados, grafo, padre, i + 1, j, conteo);
    }

    else if(grafo[i][j] == 'E'){
        if(visitados[i][j+ 1]){
            ini_x = i; ini_y = j + 1;
            x = i; y = j;
            return;
        }
        padre[i][j+ 1].first = i;
        padre[i][j+ 1].second = j;
        visitados[i][j+ 1] = 1;
        ++conteo;
        dfs(visitados, grafo, padre, i, j + 1, conteo);
    }

    else if(grafo[i][j] == 'W'){
        if(visitados[i][j - 1]){
            ini_x = i; ini_y = j - 1;
            x = i; y = j;
            return;
        }
        padre[i][j - 1].first = i;
        padre[i][j - 1].second = j;
        visitados[i][j - 1] = 1;
        ++conteo;
        dfs(visitados, grafo, padre, i, j - 1, conteo);
    } 
}

int main(){
    int row, colum, entrance;
    while(cin >> row >> colum >> entrance, row && colum && entrance){
        vvs laberinto(row + 2, vs(colum + 2, '-'));
        vvi visitados(row + 2, vi(colum + 2, 0));
        vvpii padre(row + 2, vpii(colum + 2, make_pair(-1, -1)));
        for(int i = 1; i <= row; ++i){
            string temp;
            cin >> temp;
            for(int j = 0; j < colum; ++j) laberinto[i][j + 1] = temp[j]; 
        }

        int steps = 0, ciclo = 0;
        ver = false;
        x = y = ini_x = ini_y = 0;
        visitados[1][entrance] = 1;
        dfs(visitados, laberinto, padre, 1, entrance, steps);
        if(ver) cout << steps << " step(s) to exit" << endl;
        
        else{
            while(x != ini_x || y != ini_y){
                int temp1, temp2;
                temp1 = padre[x][y].first;
                temp2 = padre[x][y].second;
                x = temp1;
                y = temp2;
                --steps; ++ciclo;
            }
            cout << steps << " step(s) before a loop of " << ciclo + 1 << " step(s)" << endl;
        }
    }
    return 0;
}
