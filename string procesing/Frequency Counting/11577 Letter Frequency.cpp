#include <iostream>
#include <map>
#include <sstream>
#include <algorithm>

#define endl '\n'
#define mci map<char, int>

using namespace std;

int stringANumero(string str){
    stringstream stream(str);
    int n;
    stream >> n;
    return n;
}

void toLower(char &x){
    x += 32;
}

string contarPalabras(mci &lista, string &str){
    stringstream stream(str);
    string temp;
    string dev = "";
    int num = 0;
    while(getline(stream, temp, ' ')){
        for(int i = 0; i < temp.size(); ++i){
            char x = temp[i];
            if(((int)x >= 97 && (int)x <= 122) || ((int)x >= 65 && (int)x <= 90)){
                if((int)x >= 65 && (int)x <= 90) toLower(x);
         
                ++lista[x]; 
                if(lista[x] > num){
                    num = lista[x];
                    dev = x;
                }

                else if(lista[x] == num) dev += x;
            }
        }
    }

    return dev;
}

int main(){
    int n;
    string temp;
    getline(cin, temp);
    n = stringANumero(temp);
    while(n--){
        mci lista;
        getline(cin, temp);
        string dev = contarPalabras(lista, temp);
        sort(dev.begin(), dev.end());
        cout << dev << endl;
    }
    return 0;
}