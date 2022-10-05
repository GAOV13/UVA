#include <bits/stdc++.h>

#define endl '\n'
#define vs vector<string>

using namespace std;

vs crear_lista(string str){
    stringstream stream(str);
    vs lista;
    while(getline(stream, str, ' ')){
        if(str != "") lista.push_back(str);
    }
    return lista;
}

int string_numero(string str){
    stringstream stream(str);
    int n;
    stream >> n;
    return n;
}

int main(){
    int n;
    string temp;
    cin >> n;
    cin.ignore();
    while(n--){
        cin.ignore();
        getline(cin, temp);
        vs indices = crear_lista(temp);
        getline(cin, temp);
        vs numeros = crear_lista(temp);
        vs dev(indices.size());
        for(int i = 0; i < indices.size(); ++i){
            int num = string_numero(indices[i]) - 1;
            dev[num] = numeros[i];
        }

        for(int i = 0; i < indices.size(); ++i)
            cout << dev[i] << endl;
        
        if(n) cout << endl;
    }
    return 0;
}