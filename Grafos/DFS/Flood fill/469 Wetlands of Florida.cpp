#include <bits/stdc++.h>

#define vvi vector<vector<int> >
#define vi vector<int>
#define vs vector<string>
#define pii pair<int, int>
#define endl '\n'

using namespace std;

int ejex[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int ejey[8] = {1, 1, 0, -1, -1, -1, 0, 1};

void dfs(vvi &visitados, vs &grafo, int i, int j, int &tami, int &tamj, int &num){
    for(int k = 0; k < 8; k++){
        if(i + ejex[k] < tami && i + ejex[k] >= 0 && j + ejey[k] < tamj && j + ejey[k] >= 0){
            if(!visitados[i + ejex[k]][j + ejey[k]] && grafo[i + ejex[k]][j + ejey[k]] == 'W'){
                ++num;
                ++visitados[i + ejex[k]][j + ejey[k]];
                dfs(visitados, grafo, i + ejex[k], j + ejey[k], tami, tamj, num);
            }
        }
    }
}

int stringANumero(string str){
    stringstream stream(str);
    int n;
    stream >> n;
    return n;
}

pii lectura(string str){
    stringstream stream(str);
    int i = 0;
    pii par;
    while(getline(stream, str, ' ')){
        if(!i++) par.first = stringANumero(str);

        else par.second = stringANumero(str);
    }
    return par;
}

int main(){
    int n;
    cin >> n;
    bool ver = false;
    cin.ignore();
    cin.ignore();
    while(n--){
        if(ver) cout << endl;

        ver = true;
        vs grafo;
        string temp;
        while(getline(cin, temp)){
            if((int)temp[0] >= 48 && temp[0] <= 57) break; 

            grafo.push_back(temp);
        }

        pii par = lectura(temp);
        int tami = grafo.size();
        int tamj = grafo[0].size();
        vvi visitados(tami, vi(tamj, 0));
        int num = 1;
        ++visitados[par.first - 1][par.second - 1];
        dfs(visitados, grafo, par.first - 1, par.second - 1, tami, tamj, num);
        cout << num << endl;
        while(getline(cin, temp)){
            if(temp == "") break;

            else{
                par = lectura(temp);
                visitados.clear();
                visitados.resize(tami);
                for(int i = 0; i < tami; ++i) visitados[i].resize(tamj);
                
                num = 1;
                ++visitados[par.first - 1][par.second - 1];
                dfs(visitados, grafo, par.first - 1, par.second - 1, tami, tamj, num);
                cout << num << endl;
            }
        }
    }
    return 0;
}
