#include <iostream>
#include <sstream>
#include <map>

#define mcc map<char, char>
#define endl '\n'

using namespace std;

int stringANumero(string str){
    stringstream stream(str);
    int n;
    stream >> n;
    return n;
}

int main(){
    int n;
    string temp;
    getline(cin, temp);
    n = stringANumero(temp);
    getline(cin, temp);
    mcc codificador;
    while(n--){
        string cod1, cod2;
        codificador.clear();
        getline(cin, cod1);
        getline(cin, cod2);
        for(int i = 0; i < cod1.size(); ++i) codificador[cod1[i]] = cod2[i];

        cout << cod2 << endl;
        cout << cod1 << endl;
        bool ver = true;
        while(getline(cin, temp)){
            if(temp.size() == 0) break;
            
            else{
                for(int i = 0; i < temp.size(); ++i){
                    if((int)codificador[temp[i]] == 0){
                        codificador[temp[i]] = temp[i];
                    }

                    cout << codificador[temp[i]];
                }
                cout << endl;
            }
            
        }
        if(n) cout << endl;
    }
    return 0;
}
