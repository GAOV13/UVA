#include <iostream>
#include <sstream>

#define endl '\n'

using namespace std;

int stringANumero(string str){
    stringstream stream(str);
    int n;
    stream >> n;
    return n;
}

string palabras(string str){
    stringstream stream(str);
    int i = 0;
    string dev = "", temp;
    while(getline(stream, temp, ' ')){
        if(temp.size() > i) dev += temp[i++];
    }
    return dev;
}

int main(){
    int n, num = 0;
    string temp;
    getline(cin, temp);
    n = stringANumero(temp);
    getline(cin, temp);
    while(n--){
        getline(cin, temp);
        cout << "Case #" << ++num << ":" << endl;
        while(temp.size() >= 1){
            cout << palabras(temp) << endl;
            getline(cin, temp);
        }
        if(n) cout << endl;
    }
    return 0;
}