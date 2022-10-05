#include <bits/stdc++.h>

#define mss map<string, string>
#define msi map<string, int>
#define spsi set<pair<string, int> >
#define psi pair<string, int>
#define vpsi vector<pair<string ,int> >
#define endl '\n'

using namespace std;

int main(){
    int mut, ini, fin, pasos;
    while(cin >> mut >> ini >> fin >> pasos, mut || ini || fin || pasos){
        bool ver = false;
        mss mutaciones;
        msi cadena_cant;
        spsi cadena_cura;
        vpsi cadena;
        for(int i = 0; i < mut; ++i){
            string a, b;
            cin >> a >> b;
            if(mutaciones[a] != "" && mutaciones[a] != b) ver = true;

            else mutaciones[a] = b;
        }

        for(int i = 0; i < ini; ++i){
            string temp;
            int cant;
            cin >> temp >> cant;
            psi par = make_pair(temp, cant);
            cadena.push_back(par);
            cadena_cant[temp] = cant;
        }

        for(int i = 0; i < fin; ++i){
            string temp;
            int cant;
            cin >> temp >> cant;
            psi par = make_pair(temp, cant);
            cadena_cura.insert(par);
        }

        if(ver) cout << "Protein mutations are not deterministic" << endl;

        else{
            int n = 0;
            while(n <= pasos){
                if(cadena_cura.size() == cadena.size()){
                    spsi temp(cadena_cura.begin(), cadena_cura.end());
                    temp.insert(cadena.begin(), cadena.end());
                    if(temp.size() == cadena_cura.size()) break;
                }

                for(int i = 0; i < cadena.size(); ++i){
                    string key = cadena[i].first;
                    if(mutaciones[key] != ""){
                        string valor = mutaciones[key];
                        cadena_cant[key] -= cadena[i].second;
                        cadena_cant[valor] += cadena[i].second;
                    }
                }

                cadena.clear();
                for(msi::iterator itr = cadena_cant.begin(); itr != cadena_cant.end(); ++itr){
                    if(itr->second){
                        psi par = make_pair(itr->first, itr->second);
                        cadena.push_back(par);
                    }
                }
                ++n;
            }

            if(n == pasos + 1) cout << "Nostalgia for Infinity is doomed" << endl;

            else cout << "Cure found in " << n << " mutation(s)" << endl;
        }
    }
    return 0;
}
