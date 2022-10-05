#include <bits/stdc++.h>

#define endl '\n'
#define vvi vector<vector<int> >
#define vi vector<int>
#define pii pair<int, int>
#define qpii queue<pair<int, int> >

using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        int per, comb;
        cin >> per >> comb;
        vvi grafo(per);
        for(int i = 0; i < comb; i++){
            int p1, p2;
            cin >> p1 >> p2;
            grafo[p1].push_back(p2);
            grafo[p2].push_back(p1);
        }
        
        vi visitado(per, 0);
        --visitado[0];
        pii par = make_pair(0, 0);
        qpii cola;
        cola.push(par);
        while(!cola.empty()){
            pii temp = cola.front(); cola.pop();
            for(int i = 0; i < grafo[temp.first].size(); ++i){
                int aux = grafo[temp.first][i];
                if(visitado[aux] == 0){
                    visitado[aux] = temp.second + 1;
                    par.first = aux; par.second = temp.second + 1;
                    cola.push(par);
                }
            }
        }

        for(int i = 1; i < per; ++i) cout << visitado[i] << endl;
        
        if(n) cout << endl;
    }
    return 0;
}
