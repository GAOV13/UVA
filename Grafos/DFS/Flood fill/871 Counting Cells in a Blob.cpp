#include <bits/stdc++.h>

#define endl '\n'
#define vs vector<string>

using namespace std;

int ejex[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int ejey[8] = {1, 1, 0, -1, -1, -1, 0, 1};

void dfs(vs &grafo, int i, int j, int &tamf, int &tamc, int &dev){
    grafo[i][j] = '0';
    for(int k = 0; k < 8; ++k){
        int x = j + ejex[k], y = i + ejey[k];
        if(x >= 0 && y >= 0 && x < tamc && y < tamf && grafo[y][x] == '1'){
            dfs(grafo, y, x, tamf, tamc, ++dev);
        }
    }
}

int main(){
    int n;
    cin >> n;
    cin.ignore();
    cin.ignore();
    while(n--){
        int fil, col = 0;
        string temp;
        vs grafo;
        while(getline(cin, temp)){
            if(temp == "") break;

            grafo.push_back(temp);
        }

        fil = grafo.size();
        if(fil)
            col = grafo[0].size();
        int num = 0;
        for(int i = 0; i < fil; ++i){
            for(int j = 0; j < col; ++j){
                if(grafo[i][j] == '1'){
                    int dev = 1;
                    dfs(grafo, i, j, fil, col, dev);
                    num = max(num, dev);
                }
            }
        }
        cout << num << endl;
        if(n) cout << endl; 
    }
    return 0;
}