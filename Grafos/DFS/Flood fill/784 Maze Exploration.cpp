#include <bits/stdc++.h>

#define endl '\n'
#define vs vector<string>

using namespace std;

int ejex[4] = {0, 1, 0, -1};
int ejey[4] = {1, 0, -1, 0};

void dfs(vs &grafo, int i, int j){
    grafo[i][j] = '#';
    for(int k = 0; k < 4; ++k){
        int x = j + ejex[k], y = i + ejey[k];
        if(y >= 0 && y < grafo.size()){
            if(x >= 0 && x < grafo[y].size() && grafo[y][x] == ' ')
                dfs(grafo, y, x);
        }
    }
}

int main(){
    int n;
    cin >> n;
    cin.ignore();
    while(n--){
        string temp;
        bool ver = true;
        vs grafo;
        while(ver){
            getline(cin, temp);
            if(temp[0] == '_') ver = false;

            else grafo.push_back(temp);
        }

        ver = true;
        for(int i = 0; i < grafo.size() && ver; ++i){
            for(int j = 0; j < grafo[i].size() && ver; ++j){
                if(grafo[i][j] == '*'){
                    ver = false;
                    dfs(grafo, i, j);
                }
            }
        }

        for(int i = 0; i < grafo.size(); ++i){
            for(int j = 0; j < grafo[i].size(); ++j){
                cout << grafo[i][j];
            }
            cout << endl;
        }
        cout << temp << endl;
    }
    return 0;
}