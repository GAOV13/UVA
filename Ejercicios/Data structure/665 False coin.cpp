#include <iostream>
#include <vector>

#define vi vector<int>
#define endl '\n'

using namespace std;

void llenar(int ini, int fin, vi &lista, vi &temp){
    for(int i = ini; i < fin; ++i)
        lista[temp[i] - 1] = 1;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        int tam, m;
        cin >> tam >> m;
        vi listaM(tam), listam(tam);
        for(int i = 0; i < m; ++i){
            int p;
            cin >> p;
            vi temp(2*p);
            for(int j = 0; j < 2*p; ++j) cin >> temp[j];
            string str;
            cin >> str;
            if(str == "<"){
                llenar(0, p, listaM, temp);
                llenar(p, 2*p, listam, temp);
            }
            else if(str == ">"){
                llenar(p, 2*p, listaM, temp);
                llenar(0, p, listam, temp);
            }
            else{
                llenar(0, 2*p, listaM, temp);
                llenar(0, 2*p, listam, temp);
            }
        }
        int conteo = 0, num = 0;
        bool ver1 = false, ver2 = false;
        for(int i = 0; i < tam; ++i){
            if(!listaM[i]) ver1 = true;
            if(!listam[i]) ver2 = true;
        }

        for(int i = 0; i < tam; ++i){
            if(ver1 && ver2){
                if(!listaM[i] && !listam[i]){
                    if(++conteo > 1) break;
                    else num = i + 1;
                }
            }

            else if(ver1){
                if(!listaM[i]){
                    if(++conteo > 1) break;
                    else num = i + 1;
                }
            }

            else if(ver2){
                if(!listam[i]){
                    if(++conteo > 1) break;
                    else num = i + 1;
                }
            }
        }

        if(conteo == 1) cout << num << endl;
        else cout << 0 << endl;
        if(n) cout << endl;
    }
    return 0;
}