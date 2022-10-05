#include <bits/stdc++.h>

#define endl '\n'
#define pii pair<int, int>
#define qppi queue<pair<int, int> >
#define vi vector<int>

using namespace std;

int main(){
    int ini, lleg, cantb;
    int n = 0;
    cin >> ini >> lleg >> cantb;
    while(cantb){
        vi visitado(10000, -1);
        vi cantbo(cantb);
        for(int i = 0; i < cantb; ++i) cin >> cantbo[i];

        qppi cola;
        pii par = make_pair(ini, 0);
        visitado[ini] = 0;
        cola.push(par);
        while(!cola.empty()){
            pii temp = cola.front(); cola.pop();
            if(temp.first == lleg){
                visitado[lleg] = temp.second;
                break;
            }

            for(int i = 0; i < cantb; ++i){
                int num = temp.first + cantbo[i];
                num = num % 10000;
                if(visitado[num] == -1){
                    visitado[num] = 1;
                    par.first = num; par.second = temp.second + 1;
                    cola.push(par);
                }
            }
        }
        cout << "Case " << ++n << ": ";  
        if(visitado[lleg] == -1) cout << "Permanently Locked";

        else cout << visitado[lleg];

        cout << endl;
         
        cin >> ini >> lleg >> cantb;
    }
    return 0;
}
