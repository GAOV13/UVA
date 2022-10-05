#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <map>

#define endl '\n'
#define mspsi map<string, pair<string, int> >
#define vs vector<string>

using namespace std;

void toLower(string &clave){
    for(int i = 0; i < clave.size(); ++i){
        if((int)clave[i] >= 65 && (int)clave[i] <= 90) clave[i] += 32;
    }
}

int main(){
    string temp;
    mspsi mapa;
    while(cin >> temp, temp != "#"){
        string clave = temp;
        toLower(clave);
        sort(clave.begin(), clave.end());
        mapa[clave].first = temp; ++mapa[clave].second;
    }

    mspsi::iterator itr;
    vs dev;
    for(itr = mapa.begin(); itr != mapa.end(); ++itr){
        if(itr->second.second == 1) dev.push_back(itr->second.first);
    }

    sort(dev.begin(), dev.end());
    for(int i = 0; i < dev.size(); ++i) cout << dev[i] << endl;
    return 0;
}
