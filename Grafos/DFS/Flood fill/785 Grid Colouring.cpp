#include <bits/stdc++.h>

#define endl '\n'
#define vs vector<string>

using namespace std;

int ejex[4] = {0, 1, 0, -1};
int ejey[4] = {-1, 0, 1, 0};

void dfs(vs &grafo, int i, int j, char c){
    grafo[i][j] = c;
    for(int k = 0; k < 4; ++k){
        int x = j + ejex[k], y = i + ejey[k];
        if(y >= 0 && y < grafo.size()){
            if(x >= 0 && x < grafo[y].size() && grafo[y][x] == ' ')
                dfs(grafo, y, x, c);
        }
    }
}

int main(){
    string temp;
    char pared;
    while(getline(cin, temp)){
        vs grafo;
        for(int i = 0; i < temp.size(); ++i){
            if(temp[i] != ' '){
                pared = temp[i];
                break;
            }
        }
        grafo.push_back(temp);
        while(getline(cin, temp)){
            if(temp[0] == '_') break;

            grafo.push_back(temp);
        }

        for(int i = 0; i < grafo.size(); ++i){
            for(int j = 0; j < grafo[i].size(); ++j){
                if(grafo[i][j] != ' ' && grafo[i][j] != pared){
                    char c = grafo[i][j];
                    dfs(grafo, i, j, c);
                }
            }
        }

        for(int i = 0; i < grafo.size(); ++i){
            for(int j = 0; j < grafo[i].size(); ++j)
                cout << grafo[i][j];
            cout << endl;
        }
        cout << temp << endl;
    }
    return 0;
}