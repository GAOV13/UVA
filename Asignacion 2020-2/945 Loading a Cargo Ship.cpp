#include <bits/stdc++.h>

// Aproximación con tuplas
#define vvi vector<vector<int> >
#define vi vector<int>
#define tiii tuple<int, int, int>
#define pqt priority_queue<tuple<int, int, int> >
// Aproximación con parejas lo que esta comentado
// #define pipii pair<int, pair<int, int> >
// #define pii pair<int, int>
// #define pqp priority_queue<pair<int, pair<int, int> > >
#define endl '\n'

using namespace std;

int main(){
    int n;
    int k = 0;
    while(cin >> n){
        int max = 0, peso = 0, peso_sin_cargar = 0, peso_carguero = 0;
        if(k++) cout << endl;

        //pqp cola;
        pqt cola;
        for(int i = 0; i < n; ++i){
            int tam;
            cin >> tam;
            tiii tupla = make_tuple(0, tam, (i + 1) * -1);
            // pii par1 = make_pair(tam, ((i + 1) * -1));
            // pipii par = make_pair(0, par1);
            cola.push(tupla);
            peso_carguero += tam;
        }

        vvi info(n + 1);
        int m;
        cin >> m;
        bool ver = true;
        
        for(int i = 0; i < m; ++i){
            int carga;
            cin >> carga;
            if(ver){
                // pipii temp = cola.top(); cola.pop();
                tiii temp = cola.top(); cola.pop();
                if(//temp.second.first - carga >= 0
                    get<1>(temp) - carga >= 0){
                    //int index = temp.second.second * -1;
                    int index = get<2>(temp) * -1;
                    info[index].push_back(carga);
                    // temp.second.first -= carga;
                    // temp.first += -1;
                    get<1>(temp) -= carga;
                    get<0>(temp) += -1; 
                    cola.push(temp);
                    //max = max < temp.first * -1 ? temp.first * -1 : max;
                    max = max < get<0>(temp) * -1 ? get<0>(temp) * -1 : max;
                    peso += carga;
                } 

                else{
                    ver = false;
                    peso_sin_cargar += carga;
                } 
            }

            else peso_sin_cargar += carga;
        }


        for(int j = max - 1; j >= 0; --j){
            if(j == max - 1 && info[1].size() < max){
                cout << ":";
            }

            else{
                cout << info[1][j];
            }
            for(int i = 2; i < n + 1; ++i){
                if(j ==  max - 1 && info[i].size() < max){
                    cout << " :";
                }

                else{
                    cout << ' ' << info[i][j];
                }
            }
            cout << endl;
        }

        int tam = 2*n - 1;
        for(int i = 0; i < tam; ++i) cout << "=";

        cout << endl;
        cout << "1";
        for(int i = 2; i < n + 1; ++i) cout << " " << i;

        cout << endl << endl;;
        cout << "cargo weight: " << peso << endl;
        cout << "unused weight: " << peso_carguero - peso << endl;
        cout << "unloaded weight: " << peso_sin_cargar << endl;
    }
    return 0;
}
