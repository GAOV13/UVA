#include <bits/stdc++.h>

#define vvi vector<vector<int> >
#define vi vector<int>
#define vs vector<string>
#define msi map<string, int>
#define pqi priority_queue<int>
#define endl '\n'

using namespace std;

vi topo_sort_kahn(vvi &grafo, vi &invertices){
    vi lista;
    pqi cola;
    for(int i = 0; i < invertices.size(); ++i)
        if(!invertices[i]) cola.push(i*-1);
    
    while(!cola.empty()){
        int u = cola.top(); cola.pop();
        u *= -1;
        lista.push_back(u);
        for(int i = 0; i < grafo[u].size(); ++i){
            int j = grafo[u][i];
            if(--invertices[j] == 0) cola.push(j * -1);
        }
    }
    return lista;
}

int main(){
    int n, casos = 0;
    while(cin >> n){
        int num = 0;
        msi string_numero;
        vs numero_string;
        while(n--){
            string temp;
            cin >> temp;
            string_numero[temp] = num++;
            numero_string.push_back(temp);
        }
        vi invertices(num, 0);
        vvi grafo(num);
        cin >> n;
        while(n--){
            string ini, fin;
            cin >> ini >> fin;
            int i = string_numero[ini], j = string_numero[fin];
            grafo[i].push_back(j);
            ++invertices[j];
        }

        vi dev = topo_sort_kahn(grafo, invertices);
        cout << "Case #" << ++casos << ": Dilbert should drink beverages in this order:";
        for(int i = 0; i < dev.size(); ++i) cout << " " << numero_string[dev[i]];

        cout << ".\n" << endl;
    }
    return 0;
}