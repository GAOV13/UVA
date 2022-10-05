#include <bits/stdc++.h>

#define mpA map<pair<pair<int, int>, int>, vector<Arista> >
#define pqA priority_queue<Arista>
#define vvpii vector<vector<pair<int, int> > >
#define vA vector<Arista>
#define pii pair<int, int>
#define endl '\n'

using namespace std;

class Arista{
    public:
        int id;
        int ini;
        int fin;
        int vel;
        int peso;
        int padre;
    
    Arista(int id, int ini, int fin, int vel, int peso, int padre){
        this->id = id;
        this->ini = ini;
        this->fin = fin;
        this->peso = peso;
        this->padre = padre;
        this->vel = vel;
    }
};

bool operator<(const Arista &a1, const Arista &a2){
    return a1.peso > a2.peso;
}

int prim(vvpii &grafo, vA &info, int ini, int fin){
    mpA mapa;
    pqA cola;
    for(int i = 0; i < grafo[ini].size(); ++i){
        int v = grafo[ini][i].first, vel = grafo[ini][i].second;
        int id = info.size();
        Arista a(id, ini, v, vel, 0, -1);
        mapa[make_pair(make_pair(ini, v), vel)].push_back(a);
        info.push_back(a);
        cola.push(a);
    }

    while(!cola.empty()){
        Arista a = cola.top(); cola.pop();
        if(a.fin == fin) return a.id;
        
        int u = a.ini, v = a.fin, vel = a.vel;
        if(a.peso == mapa[make_pair(make_pair(u, v), vel)][0].peso){
            for(int i = 0; i < grafo[v].size(); ++i){
                int w = grafo[v][i].first, velF = grafo[v][i].second;
                if(w == u) continue;

                int peso = max(vel, velF) - min(vel, velF);
                if(!mapa[make_pair(make_pair(v, w), velF)].size()){
                    int id = info.size();
                    Arista a1(id, v, w, velF, peso, a.id);
                    mapa[make_pair(make_pair(v, w), velF)].push_back(a1);
                    info.push_back(a1);
                    cola.push(a1);
                }

                else{
                    Arista *a1 = &mapa[make_pair(make_pair(v, w), velF)][0];
                    if(peso < a1->peso){
                        int id = a1->id;
                        a1->peso = peso;
                        a1->padre = a.id;
                        info[id].padre = a.id;
                        info[id].peso = peso;
                        cola.push(Arista(a1->id, v, w, velF, peso, a.id));
                    }
                }
            }
        }
    }
    return 0;
}

int main(){
    int n, roads;
    while(cin >> n >> roads){
        vvpii grafo(n + 1);
        vA info;
        int ini, fin;
        for(int i = 0; i < roads; ++i){
            int vel;
            cin >> ini >> fin >> vel;
            grafo[ini].push_back(make_pair(fin, vel));
            grafo[fin].push_back(make_pair(ini, vel));
        }

        int costi, costf;
        cin >> costi >> costf;
        int k;
        cin >> k;
        while(k--){
            cin >> ini >> fin;
            int padre = prim(grafo, info, ini, fin);
            int dev = costi + costf;
            while(padre != -1){
                dev += info[padre].peso;
                padre = info[padre].padre;
            }
            cout << dev << endl;
        }
    }
    return 0;
}
