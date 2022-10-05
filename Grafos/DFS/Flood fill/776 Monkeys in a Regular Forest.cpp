#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>

#define vvi vector<vector<int> >
#define vi vector<int>
#define vvs vector<vector<string> >
#define vs vector<string>
#define endl '\n'

using namespace std;

int ejex[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int ejey[8] = {1, 1, 0, -1, -1, -1, 0, 1};

void dfs(int i, int j, int num, int &tami, int &tamj, vvi &visitado, vvs &info){
    for(int indice = 0; indice < 8; ++indice){
        if(j + ejey[indice] < tamj && j + ejey[indice] >= 0 && i + ejex[indice] < tami && i + ejex[indice] >= 0){
            if(info[i][j] == info[i + ejex[indice]][j + ejey[indice]] && !visitado[i + ejex[indice]][j + ejey[indice]]){
                visitado[i + ejex[indice]][j + ejey[indice]] = num;
                dfs(i + ejex[indice], j + ejey[indice], num, tami, tamj, visitado, info);
            }
        }
    }
}


void dfs_aux(int i, int j, int &tami, int &tamj, vvi &visitado, vvs &info){
    int num = 0;
    for(int i = 0; i < tami; ++i){
        for(int j = 0; j < tamj; ++j){
            if(!visitado[i][j]){
                visitado[i][j] = ++num;
                dfs(i, j, num, tami, tamj, visitado, info);
            }
        }
    }
}

vi digitos(vvi &visitado, int tami, int tamj){
    vi digits_list(tamj, 0);
    for(int j = 0; j < tamj; ++j){
        int digits = 0;
        for(int i = 0; i < tami;  ++i){
            int num = floor(log10(visitado[i][j])) + 1;
            digits = num > digits ? num : digits;
        }
        digits_list[j] = digits;
    }
    return digits_list;
}

void imprimir(vvi &visitado, vi &digitos, int tami, int tamj){
    for(int i = 0; i < tami; ++i){
        int num = floor(log10(visitado[i][0])) + 1;
        while(digitos[0] - num > 0){
            cout << " ";
            ++num;
        }
        cout << visitado[i][0];
        for(int j = 1; j < tamj; ++j){
            cout << " ";
            int num = floor(log10(visitado[i][j])) + 1;
            while(digitos[j] - num > 0){
                cout << " ";
                ++num;
            }
            cout << visitado[i][j];
        }
        cout << endl;
    }
    cout << "%" << endl;
}

int main(){
    string temp;
    vvi visitados;
    vvs info;
    int tami, tamj;
    while(getline(cin, temp)){
        if(temp != "%"){
            vs llenar;
            stringstream stream(temp);
            while(getline(stream, temp, ' ')) llenar.push_back(temp);
            
            info.push_back(llenar);
            vi temp1(llenar.size(), 0);
            visitados.push_back(temp1);
        }

        else{
            tami = visitados.size(); tamj = visitados[0].size();
            dfs_aux(0, 0, tami, tamj, visitados, info);
            vi digits = digitos(visitados, tami, tamj);
            imprimir(visitados, digits, tami, tamj);
            visitados.clear();
            info.clear();
        }
    }
    tami = visitados.size(); tamj = visitados[0].size();
    dfs_aux(0, 0, tami, tamj, visitados, info);
    vi digits = digitos(visitados, tami, tamj);
    imprimir(visitados, digits, tami, tamj);
    return 0;
}
