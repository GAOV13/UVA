#include <iostream>
#include <map>

#define endl '\n'
#define mlii map<long long int, int>

using namespace std;

int main(){
    int cd1, cd2;
    cin >> cd1 >> cd2;
    while(cd1 || cd2){
        mlii lista;
        int dev = 0;
        for(int i = 0; i < cd1 + cd2; ++i){
            long long int k;
            cin >> k;
            ++lista[k];
            if(lista[k] == 2) ++dev;
        }
        cout << dev << endl;
        cin >> cd1 >> cd2;
    }
    return 0;
}
