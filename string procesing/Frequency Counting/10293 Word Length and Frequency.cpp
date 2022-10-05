#include <bits/stdc++.h>

#define endl '\n'
#define mii map<int, int>

using namespace std;

void contar(mii &mapa, string str){
    stringstream stream(str);
    string temp;
    int contador = 0;
    while(getline(stream, temp, ' ')){
        contador = 0;
        for(int i = 0; i < temp.size(); ++i){
            if(((int)temp[i] >= 65 && (int)temp[i] <= 90) || ((int)temp[i] >= 97 && (int)temp[i] <= 122)){
                ++contador;
            }

            else if((int)temp[i] != 39 && (int)temp[i] != 45){
                ++mapa[contador];
                contador = 0;
            }
        }
        ++mapa[contador];
    }
}

int main(){
    string temp;
    mii mapa;
    mapa.clear();
    string t = "";
    while(getline(cin, temp)){
        if(temp[0] == '#'){
            contar(mapa, t);
            t = "";
            mii::iterator itr = mapa.begin();
            for(itr = mapa.begin(); itr != mapa.end(); ++itr){
                if(itr->first == 0) continue;

                cout << itr->first << " " << itr->second << endl;
            }

            cout << endl;
            mapa.clear();
        }

        else{
            if(t[t.size() - 1] != '-') t += ' ';

            t += temp;
        }
    }
    return 0;
}
