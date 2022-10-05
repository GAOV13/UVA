#include <bits/stdc++.h>

#define vvi vector<vector<int> >
#define vi vector<int>
#define vs vector<string>
#define msi map<string, int>
#define endl '\n'

using namespace std;

vi temp;
vs dev;
msi string_numero;
vs numero_string;

void all_topo_sort(vvi &grafo, vi &invertices, vi &visitados){
    bool ver = false;
    for(int i = 0; i < invertices.size(); ++i){
        if(invertices[i] == 0 && !visitados[i]){
            for(int j = 0; j < grafo[i].size(); ++j){
                int k = grafo[i][j];
                --invertices[k];
            }
        
            temp.push_back(i);
            visitados[i] = 1;
            all_topo_sort(grafo, invertices, visitados);

            temp.pop_back();
            visitados[i] = 0;
            for(int j = 0; j < grafo[i].size(); ++j){
                int k = grafo[i][j];
                ++invertices[k];
            }
            ver = true;
        }
    }

    if(!ver){
        string temp1 = "";
        for(int i = 0; i < temp.size(); ++i) temp1 += numero_string[temp[i]]; 

        dev.push_back(temp1);
    }
}

void topo_sort_aux(vvi &grafo, vi &invertices){
    vi visitados(invertices.size(), 0);
    temp.clear();
    dev.clear();

    all_topo_sort(grafo, invertices, visitados);
}

vs lectura(string str){
    stringstream stream(str);
    string lect;
    vs retorna;
    while(getline(stream, lect, ' ')) retorna.push_back(lect);
    
    return retorna;
}

int main(){
    string lect;
    bool ver = false;
    while(getline(cin, lect)){
        if(ver) cout << endl;

        ver = true;
        int num = 0;
        string_numero.clear();
        numero_string.clear();
        vs elementos = lectura(lect);
        for(int i = 0; i < elementos.size(); ++i){
            string_numero[elementos[i]] = num++;
            numero_string.push_back(elementos[i]);
        }

        getline(cin, lect);
        elementos = lectura(lect);
        vvi grafo(num);
        vi invertices(num);
        for(int i = 0; i < elementos.size(); i += 2){
            string ini = elementos[i], fin = elementos[i + 1];
            int ini_i = string_numero[ini], fin_i = string_numero[fin];
            ++invertices[fin_i];
            grafo[ini_i].push_back(fin_i);
        }

        topo_sort_aux(grafo, invertices);
        sort(dev.begin(), dev.end());
        for(int i = 0; i < dev.size(); ++i) cout << dev[i] << endl;
    }   
    return 0;
}
