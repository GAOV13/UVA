#include <iostream>
#include <vector>
#include <queue>

#define qpii queue<pair<pair<int, int>, int> >
#define matriz vector<vector<int> >

using namespace std;


int main(){ 
    int fil, col;
    cin >> fil >> col;
    while(fil && col){
        matriz minas(fil, vector<int>(col, 0));
        int n;
        cin >> n;
        for(int k = 0; k < n; ++k){
            int i, j, m;
            cin >> i >> m;
            while(m--){
                cin >> j;
                minas[i][j] = -1;
            }
        }

        qpii cola;
        pair<int, int> ini, fin;
        pair<pair<int, int>, int> par;
        cin >> ini.first >> ini.second;
        cin >> fin.first >> fin.second;
        par.first.first = ini.first; par.first.second = ini.second;
        par.second = 0;
        cola.push(par);  
        while(!cola.empty()){
            pair<pair<int, int>, int> temp = cola.front(); cola.pop();
            if(temp.first.first == fin.first && temp.first.second == fin.second){
                minas[fin.first][fin.second] = temp.second;
                break;
            }

            for(int i = 0; i < 4; ++i){
                int i1 = temp.first.first, j1 = temp.first.second;
                if(i == 0){
                    if(i1 - 1 >= 0 && minas[i1 - 1][j1] == 0){
                        minas[i1 - 1][j1] = 1;
                        par.first.first = i1 - 1; par.first.second = j1;
                        par.second = temp.second + 1;
                        cola.push(par);
                    }

                }

                else if(i == 1){
                    if(j1 + 1 < col && minas[i1][j1 + 1] == 0){
                        minas[i1][j1 + 1] = 1;
                        par.first.first = i1; par.first.second = j1 + 1;
                        par.second = temp.second + 1;
                        cola.push(par);
                    }
                }

                else if(i == 2){
                    if(i1 + 1 < fil && minas[i1 + 1][j1] == 0){
                        minas[i1 + 1][j1] = 1;
                        par.first.first = i1 + 1; par.first.second = j1;
                        par.second = temp.second + 1;
                        cola.push(par);
                    }
                }

                else if(i == 3){
                    if(j1 - 1 >= 0 && minas[i1][j1 - 1] == 0){
                        minas[i1][j1 - 1] = 1;
                        par.first.first = i1; par.first.second = j1 - 1;
                        par.second = temp.second + 1;
                        cola.push(par);
                    }
                }
            } 
        }
        cout << minas[fin.first][fin.second] << endl;
        cin >> fil >> col;
    }
    return 0;
}
