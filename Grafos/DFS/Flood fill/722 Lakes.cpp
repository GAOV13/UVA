#include <bits/stdc++.h>

#define endl '\n'
#define vs vector<string>

using namespace std;

int ejex[4] = {0, 1, 0, -1};
int ejey[4] = {1, 0, -1, 0};

void dfs(vs &grafo, int i, int j, int &tamf, int &tamc, int &num){
    grafo[i][j] = '1';
    for(int k = 0; k < 4; ++k){
        int x = j + ejex[k], y = i + ejey[k];
        if(x >= 0 && y >= 0 && x < tamc && y < tamf && grafo[y][x] == '0')
            dfs(grafo, y, x, tamf, tamc, ++num);
    }
}

int main(){
    int n;
    cin >> n;
    cin.ignore();
    cin.ignore();
    while(n--){
        vs grafo;
        string temp;
        int ini, fin;
        int tamf, tamc = 0;
        int num = 0;
        cin >> ini >> fin;
        cin.ignore();
        while(getline(cin, temp)){
            if(temp == "") break;

            grafo.push_back(temp);
        }
        tamf = grafo.size();
        if(tamf) tamc = grafo[0].size();

        dfs(grafo, ini - 1, fin - 1, tamf, tamc, ++num);
        cout << num << endl;
        if(n) cout << endl;
    }
    return 0;
}