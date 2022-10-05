#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
#include <iterator>

#define endl '\n'
#define vpss vector<pair<string, string> >
#define pss pair<string, string> 
#define msvs map<string, vector<string> >

using namespace std;

string quitarPala(string str){
    stringstream stream(str);
    string dev = "";
    while(getline(stream, str, ' ')){
        dev += str;
    }
    sort(dev.begin(), dev.end());

    return dev;
}

int main(){
    int n;
    cin >> n;
    cin.ignore();
    cin.ignore();
    while(n--){
        string temp;
        msvs mapa;
        while(getline(cin, temp) && temp != ""){
            string key = quitarPala(temp);
            mapa[key].push_back(temp);
        }

        vpss resp;
        msvs::iterator itr;
        for(itr = mapa.begin(); itr != mapa.end(); ++itr){
            if(itr->second.size() > 1){
                sort(itr->second.begin(), itr->second.end());
                for(int i = 0; i < itr->second.size() - 1; ++i){
                    for(int j = i + 1; j < itr->second.size(); ++j){
                        pss par = make_pair(itr->second[i], itr->second[j]);
                        resp.push_back(par);
                    }
                }
            }
        }

        sort(resp.begin(), resp.end());
        for(int i = 0; i < resp.size(); ++i){
            cout << resp[i].first << " = " << resp[i].second << endl;
        }    
        
        if(n) cout << endl;
    }
}
