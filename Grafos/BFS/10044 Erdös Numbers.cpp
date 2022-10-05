#include <bits/stdc++.h>

#define endl '\n'
#define msvs map<string, vector<string> >
#define vs vector<string>
#define msi map<string, int>
#define ss stringstream
#define qs queue<string>

using namespace std;

vs descomponer(string str){
    ss stream(str);
    string temp;
    vs lista;
    while(getline(stream, temp, ':')){
        ss stream1(temp);
        string dato = "";
        int contador = 0;
        while(getline(stream1, temp, ',')){
            contador++;
            if(contador%2 == 1){
                dato = "";
                if(temp[0] != ' ') dato += temp[0];
                   
                for(int i = 1; i < temp.size(); ++i){
                       dato += temp[i];
                }
                dato += ','; 
            }

            else{
                dato += temp;
                lista.push_back(dato);
            }
        }
        break;
    }
    return lista;
}

void crear_conect(msvs &grafo, vs &lista, msi &visitado){
    for(int i = 0; i < lista.size() - 1; ++i){
        string temp = lista[i];
        visitado[temp] = -1;
        for(int j = i + 1; j < lista.size(); ++j){
            grafo[temp].push_back(lista[j]);
            grafo[lista[j]].push_back(temp);
        }
    }
    visitado[lista[lista.size() - 1]] = -1;
}

int main(){
    int n, caso = 0;
    cin >> n;
    while(n--){
        int lib, aut;
        msvs grafo;
        msi visitado;
        qs cola;
        cin >> lib >> aut;
        cin.ignore();
        while(lib--){
            string temp;
            getline(cin, temp);
            vs lista = descomponer(temp);
            crear_conect(grafo, lista, visitado);
        }

        visitado["Erdos, P."] = 0;
        cola.push("Erdos, P.");
        while(!cola.empty()){
            string temp = cola.front(); cola.pop();
            vs lista = grafo[temp];
            for(int i = 0; i < lista.size(); ++i){
                string temp1 = lista[i];
                if(visitado[temp1] == -1){
                    visitado[temp1] = visitado[temp] + 1;
                    cola.push(temp1);
                }
            }
        }

        cout << "Scenario " << ++caso << endl;
        while(aut--){
            string temp;
            getline(cin, temp);
            cout << temp << " ";
            int key = visitado[temp];
            if((key == -1 || key == 0) && temp != "Erdos, P.") cout << "infinity" << endl;

            else cout << key << endl;
        }
    }
}