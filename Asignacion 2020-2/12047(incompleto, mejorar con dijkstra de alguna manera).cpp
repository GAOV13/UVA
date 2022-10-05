#include <bits/stdc++.h>

#define vvpii vector<vector<pair<int, int> > >
#define vpii vector<pair<int, int> >
#define pii pair<int, int>
#define endl '\n'

using namespace std;

int resp;

void dfs(int &peso, int acum, vvpii &grafo, int indice, int maximo, int &fin, int it){
    if(acum > peso) return;

    if(indice == fin){
        resp = resp < maximo ? maximo : resp;
        return;
    }

    if(it == 10) return;

    for(int i = 0; i < grafo[indice].size(); ++i){
        int m = grafo[indice][i].second;
        m = m > maximo ? m : maximo;
        dfs(peso, acum + grafo[indice][i].second, grafo, grafo[indice][i].first, m, fin, it + 1);
    }
}

int main(){
    int n;
    cin >> n;
    while(n--){
        int nodos, rutas, ini, fin, presupuesto;
        cin >> nodos >> rutas >> ini >> fin >> presupuesto;
        vvpii grafo(nodos + 1);
        for(int i = 0; i < rutas; ++i){
            int inicio, dest, peso;
            cin >> inicio >> dest >> peso;
            pii par = make_pair(dest, peso);
            grafo[inicio].push_back(par);
        }
        resp = -1;
        dfs(presupuesto, 0, grafo, ini, 0, fin, 0);
        cout << resp << endl;
    }
    return 0;
}
