#include <bits/stdc++.h>

#define endl '\n'
#define vvvi vector<vector<vector<int> > >
#define qU queue<Ubi>

using namespace std;

class Ubi{
    public:
        int x;
        int y;
        int z;
        Ubi(){
            x = y = z = 0;
        }

        Ubi(int x, int y, int z){
            this->x = x;
            this->y = y;
            this->z = z;
        }

        void operator =(const Ubi &p1){
            this->x = p1[0];
            this->y = p1.y;
            this->z = p1.z;
        }
};

int main(){
    int niv, fil, col;
    cin >> niv >> fil >> col;
    while(niv){
        Ubi inicio, fin, temp;
        vvvi visitados(niv, vector<vector<int> >(fil, vector<int>(col, -1)));
        for(int i = 0; i < niv; ++i){
            for(int j = 0; j < fil; ++j){
                string temp;
                cin >> temp;
                for(int k = 0; k < col; ++k){
                    if(temp[k] == '.') ++visitados[i][j][k];

                    else if(temp[k] == 'S'){
                        visitados[i][j][k] = 1;
                        inicio[0] = i;
                        inicio.y = j;
                        inicio.z= k;
                    }

                    else if(temp[k] == 'E'){
                        ++visitados[i][j][k];
                        fin[0] = i;
                        fin.y = j;
                        fin.z = k;
                    }
                }
            }
        }
        
        qU cola;
        cola.push(inicio);
        while(!cola.empty()){
            temp = cola.front(); cola.pop();
            if(temp[0] == fin[0] && temp.y == fin.y && temp.z == fin.z) break;

            for(int i = 0; i < 6; ++i){
                bool ver = false;
                int x = temp[0], y = temp.y, z = temp.z;
                if(i == 0){
                    x -= 1;
                    if(x >= 0 && visitados[x][y][z] == 0) ver = true;
                }

                else if(i == 1){
                    x += 1;
                    if(x < niv && visitados[x][y][z] == 0) ver = true;
                }
                

                else if(i == 2){
                    y -= 1;
                    if(y >= 0 && visitados[x][y][z] == 0) ver = true;
                }

                else if(i == 3){
                    y += 1;
                    if(y < fil && visitados[x][y][z] == 0) ver = true;
                }

                else if(i == 4){
                     z -= 1;
                    if(z >= 0 && visitados[x][y][z] == 0) ver = true;
                }

                else if(i == 5){
                    z += 1;
                    if(z < col && visitados[x][y][z] == 0) ver = true;
                }

                if(ver){
                    visitados[x][y][z] = visitados[temp[0]][temp.y][temp.z] + 1;
                    Ubi met(x, y, z);
                    cola.push(met);
                }
            }
        }

        if(visitados[fin[0]][fin.y][fin.z]) cout << "Escaped in " << visitados[fin[0]][fin.y][fin.z] - 1 << " minute(s)." << endl;

        else cout << "Trapped!" << endl;

        cin >> niv >> fil >> col;
    }
    return 0;
}
