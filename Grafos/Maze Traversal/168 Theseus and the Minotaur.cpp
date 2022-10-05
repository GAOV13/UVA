#include <bits/stdc++.h>

#define mci map<char, int>
#define vc vector<char>
#define vvi vector<vector<int> >
#define vi vector<int>
#define si stack<int>
#define endl '\n'

using namespace std;

bool ver;
vi dev;

int lectura(vvi &grafo, vc &numero_string, mci &string_numero, int num, string str){
    stringstream stream(str);
    while(getline(stream, str, ';')){
        char ini = str[0];
        if(!string_numero[ini]){
            string_numero[ini] = num++;
            numero_string.push_back(ini);
            grafo.push_back(vi(0,0));
        }

        for(int i = 2; i < str.size(); ++i){
            char fin = str[i];
            if(!string_numero[fin]){
                string_numero[fin] = num++;
                numero_string.push_back(fin);
                grafo.push_back(vi(0,0));
            }
            int ini_n = string_numero[ini];
            int fin_n = string_numero[fin];
            grafo[ini_n].push_back(fin_n);
        }
    }
    return num;
}

void dfs(vvi &grafo, vi &visitados, int mino, int theseo, int &k){
    si pila;
    int i = 0;
    while(!ver){
        bool ver1 = true;
        if(i%k == 0 && i > 0){ 
            i = 0;
            visitados[theseo] = 2;
            dev.push_back(theseo);
        }

        else if(visitados[theseo] == 0) visitados[theseo] = 1;
        
        for(int index = 0; index < grafo[mino].size(); ++index){
            int j = grafo[mino][index];
            if(visitados[j] == 0){
                if(visitados[theseo] == 1) visitados[theseo] = 0;
                theseo = mino;
                mino = j;
                ++i;
                ver1 = false;
                break;
            }
        }

        if(ver1){
            ver = true;
            dev.push_back(mino);
        }
    }
}

int main(){
    string lect;
    cin >> lect;
    while(lect != "#"){
        lect.pop_back();
        char mino, theseo;
        int mino_n, theseo_n, k;
        vvi grafo(1);
        vc numero_string(1, '-');
        mci string_numero;
        int tam = lectura(grafo, numero_string, string_numero, 1, lect);
        vi visitados(tam, 0);
        cin >> mino >> theseo >> k;

        mino_n = string_numero[mino];
        theseo_n = string_numero[theseo];
        dev.clear();
        ver = false;
        dfs(grafo, visitados, mino_n, theseo_n, k);
        for(int i = 0; i < dev.size() - 1; ++i){
            if(i == 0) cout << numero_string[dev[i]];

            else cout << " " << numero_string[dev[i]];
        }

        if(dev.size() > 1) cout << " ";

        cout << '/' << numero_string[dev[dev.size() - 1]] << endl;
        cin >> lect;
    }
    return 0;
}
