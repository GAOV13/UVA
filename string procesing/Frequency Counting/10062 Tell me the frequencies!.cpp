#include <iostream>
#include <map>
#include <queue>
#include <iterator>

#define endl '\n'
#define mci map<char, int>
#define pqpii priority_queue<pair<int, int> >
#define pii pair<int, int>

using namespace std;

int main(){
    string temp;
    bool ver = false;
    while(getline(cin, temp)){
        if(ver) cout << endl;

        ver = true;
        mci lista;
        pqpii cola;
        for(int i = 0; i < temp.size(); ++i) ++lista[temp[i]];

        mci::iterator itr;
        for(itr = lista.begin(); itr != lista.end(); ++itr){
            pii par = make_pair(itr->second * -1, (int)itr->first);
            cola.push(par);
        }

        while(!cola.empty()){
            pii par = cola.top(); cola.pop();
            cout << par.second << " " <<par.first * -1 << endl;
        }
    }
}
