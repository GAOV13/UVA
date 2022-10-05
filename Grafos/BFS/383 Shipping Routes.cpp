#include <iostream>
#include <map>
#include <queue>
#include <vector>

#define endl '\n'
#define msi map<string, int>
#define msvs map<string, vector<string> >
#define qs queue<string>

using namespace std;

int main(){
    cout << "SHIPPING ROUTES OUTPUT\n" << endl;
    int cant, ruta, ship;
    int n, caso = 0;
    cin >> n;
    while(n--){
        cout << "DATA SET  " << ++caso << "\n" << endl;
        cin >> cant >> ruta >> ship;
        msvs mapa;
        string temp, ini, fin;
        for(int i = 0; i < cant; ++i){
            cin >> temp;
            mapa[temp].clear();
        }

        for(int i = 0; i < ruta; ++i){
            cin >> ini >> fin;
            mapa[ini].push_back(fin);
            mapa[fin].push_back(ini);
        }

        for(int i = 0; i < ship; ++i){
            int p;
            cin >> p;
            cin >> ini >> fin;
            msi visitado;
            ++visitado[ini];
            qs cola;
            cola.push(ini);
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

            if(visitado[fin]){
                p = p*(visitado[fin] - 1);
                p = p*100;
                cout << "$" << p << endl;
            }

            else cout << "NO SHIPMENT POSSIBLE" << endl;
        }
        cout << endl;
    }
    cout << "END OF OUTPUT" << endl;
    return 0;
}
