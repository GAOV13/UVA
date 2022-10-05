#include <iostream>
#include <map>
#include <vector>
#include <sstream>

#define endl '\n'
#define mss map<string, string>
#define msi map<string, int>
#define vs vector<string>

using namespace std;

int stringANumero(string str){
    stringstream stream(str);
    int n;
    stream >> n;
    return n;
}

int main(){
    string temp;
    int n;
    getline(cin, temp);
    n = stringANumero(temp);
    while(n--){
        getline(cin, temp);
        int m;
        getline(cin, temp);
        m = stringANumero(temp);
        mss listado;
        while(m--){
            string temp1;
            getline(cin, temp);
            getline(cin, temp1);
            listado[temp] = temp1;
        }
        getline(cin, temp);
        m = stringANumero(temp);
        vs sera;
        msi verificar;
        int max = 0;
        while(m--){
            getline(cin, temp);
            int num = ++verificar[temp];
            if(num > max && listado[temp].size() != 0){
                sera.clear();
                sera.push_back(temp);
                max = num;
            }
            else if(num == max && listado[temp].size() != 0) sera.push_back(temp);
        }

        if(sera.size() != 1) cout << "tie" << endl;

        else cout << listado[sera[0]] << endl;

        if(n) cout << endl;
    }
    return 0;
}
