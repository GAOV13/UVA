#include <bits/stdc++.h>

#define mci map<char, int>
#define vc vector<char>
#define vs vector<string>
#define vvi vector<vector<int> >
#define vi vector<int>
#define endl '\n'

using namespace std;

vi lista;
vs dev;
mci string_numero;
vc numero_string;

void all_topo_sort(vvi &grafo, vi &invertices, vi &visitados){
    bool ver = false;
    for(int i = 0; i < invertices.size(); ++i){
        if(!invertices[i] && !visitados[i]){
            for(int j = 0; j < grafo[i].size(); ++j){
                int k = grafo[i][j];
                --invertices[k];
            }

            lista.push_back(i);
            ++visitados[i];
            all_topo_sort(grafo, invertices, visitados);

            lista.pop_back();
            --visitados[i];
            for(int j = 0; j < grafo[i].size(); ++j){
                int k = grafo[i][j];
                ++invertices[k];
            }
            ver = true;
        }
    }

    if(!ver){
        string temp  = "";
        for(int i = 0; i < lista.size(); ++i) temp += numero_string[lista[i]];

        if(temp.size()) dev.push_back(temp);
    }
}

void aux_all_topo_sort(vvi &grafo, vi &invertices){
    vi visitados(invertices.size(), 0);

    dev.clear();
    lista.clear();
    all_topo_sort(grafo, invertices, visitados);
}

vs lectura(string str){
    stringstream stream(str);
    vs temp;
    while(getline(stream, str, ' ')) temp.push_back(str);

    return temp;
}

int main(){
    int n;
    bool ver = false;
    cin >> n;
    cin.ignore();
    while(n--){
        if(ver) cout << endl;

        string_numero.clear();
        numero_string.clear();
        ver = true;
        cin.ignore();
        string temp;
        getline(cin, temp);
        vs elementos = lectura(temp);
        int num = 0;
        for(int i = 0; i < elementos.size(); ++i){
            string_numero[elementos[i][0]] = num++;
            numero_string.push_back(elementos[i][0]);
        }

        vi invertices(num, 0);
        vvi grafo(num);
        getline(cin, temp);
        elementos = lectura(temp);
        for(int i = 0; i < elementos.size(); ++i){
            char ini = elementos[i][0], fin = elementos[i][2];
            int ini_n = string_numero[ini], fin_n = string_numero[fin];
            grafo[ini_n].push_back(fin_n);
            ++invertices[fin_n];
        }

        aux_all_topo_sort(grafo, invertices);
        if(!dev.size()) cout << "NO" << endl;

        else{
            sort(dev.begin(), dev.end());
            for(int i = 0; i < dev.size(); ++i){
                cout << dev[i][0];
                for(int j = 1; j < dev[i].size(); ++j) cout << " " << dev[i][j];

                cout << endl;
            }
        }
    }
    return 0;
}
