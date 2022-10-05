#include<bits/stdc++.h>

#define vs vector<string>
#define endl '\n'

using namespace std;

vs rep;

string contarPalabras(string str){
    stringstream stream(str);
    string dev = "";
    while(getline(stream, str, ' ')) dev += str;

    sort(dev.begin(), dev.end());
    return dev;    
}

void back(vs &lista, string &temp, int i, string acum, int &n){
    if(i == temp.size()){
        if(acum.size()){
            vs::iterator itrb = lower_bound(lista.begin(), lista.end(), acum), itre;
            if(*(itrb) == acum){
                if(!binary_search(rep.begin(), rep.end(), acum)){
                    itre = upper_bound(itrb, lista.end(), acum);
                    n += itre - itrb;
                    rep.push_back(acum);
                    sort(rep.begin(), rep.end());
                }
            }

        }

        return;
    }

    if(acum.size() > 7) return;

    back(lista, temp, i + 1, acum, n);
    back(lista, temp, i + 1, acum + temp[i], n);
}

int main(){
    vs lista;
    string temp;
    getline(cin, temp);
    while(temp != "#"){
        sort(temp.begin(), temp.end());
        lista.push_back(temp);
        getline(cin, temp);
    }

    sort(lista.begin(), lista.end());
    getline(cin, temp);
    while(temp != "#"){
        rep.clear();
        temp = contarPalabras(temp);
        int num = 0;
        back(lista, temp, 0, "", num);
        cout << num << endl;
        getline(cin, temp);
    }
    return 0;
}