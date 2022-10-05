#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>

#define matriz vector<vector<char> >
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
    while(n--){
        getline(cin, temp);
        int m = sqrt(temp.size());
        if(m * m != temp.size()) cout << "INVALID" << endl;

        else{
            int k = 0;
            matriz lista(m, vector<char>(m, '0'));
            for(int i = 0; i < m; ++i){
                for(int j = 0; j < m; ++j){
                    lista[i][j] = temp[k++];
                }
            }

            for(int j = 0; j < m; ++j){
                for(int i = 0; i < m; ++i){
                    cout << lista[i][j];
                }
            }
            cout << endl;
        }
    }
    return 0;
}
