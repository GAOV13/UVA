#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>

#define endl '\n'
#define psi pair<string, int>
#define mci map<char, int>

using namespace std;

psi devolver(string str){
    stringstream stream(str);
    string temp, dev = "";
    mci listado;
    int n = 0;
    while(getline(stream, temp, ' ')){
        for(int i = 0; i < temp.size(); ++i){
            if((temp[i] >= 65 && temp[i] <= 90) || (temp[i] >= 97 && temp[i] <= 122)){
                int num = ++listado[temp[i]];
                if(num > n){
                    dev = temp[i];
                    n = num;
                }

                else if(num == n) dev += temp[i];
            }
        }
    }

    sort(dev.begin(), dev.end());
    psi par = make_pair(dev, n);
    return par;
}

int main(){
    string temp;
    while(getline(cin, temp)){
        psi par = devolver(temp);
        cout << par.first << " " << par.second << endl;
    }
    return 0;
}
