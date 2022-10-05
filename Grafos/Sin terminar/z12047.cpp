#include <bits/stdc++.h>

#define vvpii vector<vector<pair<int, int> > >
#define vpii vector<pair<int, int> > 
#define pii pair<int, int> 

using namespace std;

int dev;

void back(vvpii &grafo, int max, int acum, int i, int &lim, int &llegada, int rep){
    if(acum > lim) return;

    if(i == llegada){
        dev = dev < max ? max : dev;
        return;
    }

    if(rep == 1000) return;

    if(!grafo[i].size()) return;

    for(int j = 0; j < grafo[i].size(); ++j){
        int max_new = grafo[i][j].second > max ? grafo[i][j].second : max;
        back(grafo, max_new, acum + grafo[i][j].second, grafo[i][j].first, lim, llegada, rep + 1);
    }

    return;
}


int main(){
    int t;
    cin >> t;
    while(t--){
        dev = -1;
        int n, m, inicio, fin, p;
        cin >> n >> m >> inicio >> fin >> p;
        vvpii grafo(n + 1, vpii(0));
        for(int i = 0; i < m; ++i){
            int a, b, precio;
            cin >> a >> b >> precio;
            pii pareja = make_pair(b, precio);
            grafo[a].push_back(pareja);
        }
        back(grafo, 0, 0, inicio, p, fin, 0);
        cout << dev << endl;
    }
    return 0;
}
