#include <bits/stdc++.h>

#define endl '\n'
#define vs vector<string>
#define vi vector<int>

using namespace std;

vi ejex = {-1, 0, 1, 0};
vi ejey = {0, 1, 0, -1};

void dfs(vs &grafo, int i, int j, char &c, int &contador, bool &ver){
    for(int k = 0; k < 4; ++k){
        int x = i + ejex[k], y = j + ejey[k];
        if(x >= 0 && x < 9 && y >= 0 && y < 9){
            if(grafo[x][y] == '.'){
                grafo[x][y] = '#';
                dfs(grafo, x, y, c, ++contador, ver);
            }

            else if(grafo[x][y] != '#' && grafo[x][y] != c) ver = false;
        }
    }
}

int main(){
    int n;
    cin >> n;
    while(n--){
        vs grafo(9);
        int b = 0, w = 0; 
        for(int i = 0; i < 9; ++i) cin >> grafo[i];

        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                if(grafo[i][j] == '.'){
                    int num = 1;
                    char c = '.';
                    if(j - 1 >= 0 && grafo[i][j - 1] != '.' && grafo[i][j - 1] != '#') c = grafo[i][j - 1];

                    if(j + 1 < 9 && grafo[i][j + 1] != '.' && grafo[i][j + 1] != '#') c = grafo[i][j + 1];

                    if(c != '.'){
                        grafo[i][j] = '#';
                        bool ver = true;
                        dfs(grafo, i, j, c, num, ver);
                        if(ver){
                            if(c == 'X') b += num;

                            else w += num;  
                        }
                    }
                }

                else if(grafo[i][j] == 'X') ++b;

                else if(grafo[i][j] == 'O') ++w;
            }
        }

        cout << "Black " << b << " White " << w << endl;
    }
    return 0;
}
