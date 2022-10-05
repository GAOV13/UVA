#include <bits/stdc++.h>

#define endl '\n'
#define vi vector<int>
#define qs queue<string>

using namespace std;

int stringANumero(string str){
    stringstream stream(str);
    int n;
    stream >> n;
    return n;
}

string quitar(string str){
    stringstream stream(str);
    string temp = "";
    while(getline(stream, str, ' ')) temp += str;
    
    return temp;
}

int main(){
    int n;
    cin >> n;
    cin.ignore();
    while(n--){
        int inii, fini;
        string ini, fin, temp;
        getline(cin, temp);
        ini = quitar(temp);
        inii = stringANumero(ini);
        getline(cin, temp);
        fin = quitar(temp);
        fini = stringANumero(fin);
        int m;
        cin >> m;
        cin.ignore();
        vi visitados(10000, 0);
        for(int i = 0; i < m; ++i){
            int indice;
            getline(cin, temp);
            temp = quitar(temp);
            indice = stringANumero(temp);
            --visitados[indice];
        }


        qs cola;
        cola.push(ini);
        visitados[inii] = 1;
        if(visitados[fini] == -1) cout << -1 << endl;
        else{
            while(!cola.empty()){
                string num = cola.front(); cola.pop();
                if(num == fin) break; 

                for(int i = 0; i < 8; ++i){
                    bool ver = false;
                    string sera = num;
                    int k;
                    if(i == 0){
                        sera[0] += 1;
                        if(sera[0] == 58) sera[0] = 48;

                        k = stringANumero(sera);
                        if(!visitados[k]) ver = true;
                    }

                    else if(i == 1){
                        sera[0] -= 1;
                        if(sera[0] == 47) sera[0] = 57;

                        k = stringANumero(sera);
                        if(!visitados[k]) ver = true;
                    }

                    else if(i == 2){
                        sera[1] += 1;
                        if(sera[1] == 58) sera[1] = 48;

                        k = stringANumero(sera);
                        if(!visitados[k]) ver = true;
                    }

                    else if(i == 3){
                        sera[1] -= 1;
                        if(sera[1] == 47) sera[1] = 57;

                        k = stringANumero(sera);
                        if(!visitados[k]) ver = true;
                    }

                    else if(i == 4){
                        sera[2] += 1;
                        if(sera[2] == 58) sera[2] = 48;

                        k = stringANumero(sera);
                        if(!visitados[k]) ver = true;
                    }

                    else if(i == 5){
                        sera[2] -= 1;
                        if(sera[2] == 47) sera[2] = 57;

                        k = stringANumero(sera);
                        if(!visitados[k]) ver = true;
                    }

                    else if(i == 6){
                        sera[3] += 1;
                        if(sera[3] == 58) sera[3] = 48;

                        k = stringANumero(sera);
                        if(!visitados[k]) ver = true;
                    }

                    else if(i == 7){
                        sera[3] -= 1;
                        if(sera[3] == 47) sera[3] = 57;

                        k = stringANumero(sera);
                        if(!visitados[k]) ver = true;
                    }

                    if(ver){
                        int k1 = stringANumero(num);
                        visitados[k] = visitados[k1] + 1;
                        cola.push(sera);
                    }
                }
            }
            cout << visitados[fini] - 1 << endl;
        }
        cin.ignore();
    }
    return 0;
}
