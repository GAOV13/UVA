#include <iostream>
#include <vector>
#include <set>

#define endl '\n'
#define vlli vector<long long int>
#define slli set<long long int>
#define lli long long int

using namespace std;

int main(){
    int cd1, cd2;
    cin >> cd1 >> cd2;
    while(cd1 || cd2){
        vlli lista;
        slli todos;
        for(int i = 0; i < cd1 + cd2; ++i){
            long long int k;
            cin >> k;
            lista.push_back(k);
            todos.insert(k);
        }
        cout << lista.size() - todos.size() << endl;
        cin >> cd1 >> cd2;
    }
    return 0;
}
