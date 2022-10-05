#include <bits/stdc++.h>

#define endl '\n'
#define vvs vector<vector<string> >
#define vs vector<string>

using namespace std;

int main(){
    int n, m, casos = 0;
    cin >> n;
    while(n--){
        cin >> m;
        vvs lista;
        for(int i = 0; i < m; ++i){
            int cant; 
            cin >> cant;
            vs tem(m + 1, "0");
            for(int j = 0; j < cant; ++j){
                string s;
                cin >> s; 
                transform(s.begin(), s.end(), s.begin(), ::tolower);
                s[0] -= 32;
                int index = s[0] - 65;
                if(index < m) tem[index] = s;
            }
            tem[m] = "-";
            lista.push_back(tem);
        }

        vs contexto(m, "0");
        int cant = 0;
        int fila;
        fila = 0;
        while(cant != m){
            bool ver = false; 
            string temp = "";
            for(int i = 0; i < m; ++i){
                int cont = 0;

                if(lista[i][m] == "+") continue;

                for(int j = 0; j < m; ++j){
                    if(lista[i][j] != "0"){
                        ++cont;
                        if(cont == 1) temp = lista[i][j];

                        else break;
                    }
                }

                if(cont == 1){
                    ver = true;
                    fila = i;
                    break;
                }
            }

            for(int j = 0; j < m && !ver; ++j){
                int cont = 0;

                if(contexto[j] != "0") continue;

                for(int i = 0; i < m; ++i){
                    if(lista[i][j] != "0"){
                        ++cont;
                        fila = i;
                        if(cont == 1) temp = lista[i][j];

                        else break;
                    }
                }

                if(cont == 1){
                    ver = true;
                    break;
                }
            }

            if(ver){
                int index = temp[0] - 65;
                contexto[index] = temp;
                ++cant;
                vs remover(m + 1, "0");
                remover[m] = "+";
                lista[fila] = remover;
                for(int i = 0; i < m; ++i) lista[i][index] = "0";
            }
        }

        cout << "Case #" << ++casos << ":" << endl;
        for(int i = 0; i < m; ++i){
            cout << contexto[i] << endl;
        }
    }
    return 0;
}
