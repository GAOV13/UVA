#include <bits/stdc++.h>

#define endl '\n'
#define vs vector<string>
#define msi map<string, int>
#define msvs map<string, vector<string> >
#define qs queue<string>

using namespace std;

void separar(string str, string &ini, string &fin){
    stringstream stream(str);
    stream >> ini;
    stream >> fin;
    cout << ini << " " << fin << " ";
}

void hacerMapa(vs &lista, msvs &mapa, int &tam){
    for(int i = 0; i < tam - 1; ++i){
        for(int j = i + 1; j < tam; ++j){
            if(lista[i].size() == lista[j].size()){
                int n = 0;
                for(int k = 0; k < lista[i].size() && n <= 1; ++k){
                    if(lista[i][k] != lista[j][k]) ++n;
                }

                if(n == 1){
                    mapa[lista[i]].push_back(lista[j]);
                    mapa[lista[j]].push_back(lista[i]);
                }
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    while(n--){
        string inicio, fin, temp;
        vs lista;
        while(cin >> temp, temp != "*") lista.push_back(temp);
        
        cin.ignore();
        msvs mapa;
        int tam = lista.size();
        hacerMapa(lista, mapa, tam);
        while(getline(cin, temp) && temp != ""){
            msi visitado;
            separar(temp, inicio, fin);
            visitado[inicio] = 1;
            qs cola; cola.push(inicio);
            while(!cola.empty()){
                temp = cola.front(); cola.pop();
                if(temp == fin) break;
                
                for(int i = 0; i < mapa[temp].size(); ++i){
                    string nodo = mapa[temp][i];
                    if(!visitado[nodo]){
                        visitado[nodo] = visitado[temp] + 1;
                        cola.push(nodo);
                    }
                }
            }

            cout << visitado[fin] - 1 << endl;
        }
        if(n) cout << endl;
    }
    return 0;
}