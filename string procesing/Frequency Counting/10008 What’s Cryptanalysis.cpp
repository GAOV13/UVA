#include <iostream>
#include <map>
#include <iterator>
#include <queue>
#include <sstream>

#define endl '\n'
#define mci map<char, int>
#define priii priority_queue<pair<int, int> >
#define pii pair<int, int>

using namespace std;

void toUpper(char &c){
    c -= 32;
}

void hacerCola(mci &lista, priii &cola){
    mci::iterator itr;
    for(itr = lista.begin(); itr != lista.end(); ++itr){
        int tam = itr->second, num = (int)itr->first;
        num *= -1;
        pii par = make_pair(tam, num);
        cola.push(par);
    }
}

void leerDatos(string &str, mci &lista){
    stringstream stream(str);
    string temp;
    while(getline(stream, temp, ' ')){
        for(int i = 0; i < temp.size(); ++i){
            if(temp[i] >= 65 && temp[i] <= 90) ++lista[temp[i]];
            
            else if(temp[i] >= 97 && temp[i] <= 122){
                toUpper(temp[i]);
                ++lista[temp[i]];
            }
        }
    }
}

void imprimir(priii &cola){
    while(!cola.empty()){
        cout << (char)(cola.top().second * -1) << " " << cola.top().first << endl;
        cola.pop();
    }
}

int stringANumero(string str){
    stringstream stream(str);
    int n;
    stream >> n;
    return n;
}

int main(){
    int n;
    string temp;
    mci lista;
    priii cola;
    getline(cin, temp);
    n = stringANumero(temp);
    while(n--){
        getline(cin, temp);
        leerDatos(temp, lista);
    }

    hacerCola(lista, cola);
    imprimir(cola);
    return 0;
}
