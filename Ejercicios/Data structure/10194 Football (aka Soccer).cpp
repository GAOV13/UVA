#include <bits/stdc++.h>

#define endl '\n'
#define msvT map<string, vector<Team> >
#define vT vector<Team>

using namespace std;

class Team{
    public:
        string nombre;
        int golesF;
        int golesC;
        int difGol;
        int ganados;
        int perdidos;
        int empatados;
        int puntos;
        int partidos;

        Team(string nombre){
            this->nombre = nombre;
            golesF = golesC = difGol = 0;
            ganados = perdidos = empatados = 0;
            puntos = partidos = 0;
        }
};

int stringANumero(string str){
    stringstream stream(str);
    int n;
    stream >> n;
    return n;
}

void quitar(string str, msvT &map){
    stringstream stream(str);
    string temp, name1, name2, sera;
    int i = 0, gol1, gol2;
    while(getline(stream, temp, '#')){
        if(i == 0) name1 = temp;

        else if(i == 1){
            int j = 0;
            stringstream stream1(temp);
            while(getline(stream1, sera, '@')){
                if(j == 0) gol1 = stringANumero(sera);

                else gol2 = stringANumero(sera);
                
                ++j;
            }
        }

        else if(i == 2) name2 = temp;

        ++i;
    }

    int difg1 = gol1 - gol2, difg2 = gol2 - gol1;
    map[name1][0].golesF += gol1;
    map[name1][0].golesC += gol2;
    map[name1][0].difGol += difg1;
    map[name2][0].golesF += gol2;
    map[name2][0].golesC += gol1;
    map[name2][0].difGol += difg2;
    ++map[name1][0].partidos;
    ++map[name2][0].partidos;
    if(gol1 > gol2){
        ++map[name1][0].ganados;
        ++map[name2][0].perdidos;
        map[name1][0].puntos += 3;
    }

    else if(gol1 < gol2){
        ++map[name2][0].ganados;
        ++map[name1][0].perdidos;
        map[name2][0].puntos += 3;
    }

    else{
        ++map[name2][0].empatados;
        ++map[name1][0].empatados;
        ++map[name1][0].puntos;
        ++map[name2][0].puntos;
    }
}

bool compare(Team t1, Team t2){
    if(t1.puntos != t2.puntos) return t1.puntos > t2.puntos;

    else if(t1.ganados != t2.ganados) return t1.ganados > t2.ganados;

    else if(t1.difGol != t2.difGol) return t1.difGol > t2.difGol;

    else if(t1.golesF != t2.golesF) return t1.golesF > t2.golesF;

    else if(t1.partidos != t2.partidos) return t1.partidos < t2.partidos;

    char c1, c2;
    int tam = t1.nombre.size() > t2.nombre.size() ? t2.nombre.size() :t1.nombre.size();
    for(int i = 0; i < tam; ++i){
        c1 = t1.nombre[i]; c2 = t2.nombre[i];
        if(c1 >= 97 && c1 <= 122) c1 -= 32;

        if(c2 >= 97 && c2 <= 122) c2 -= 32;

        if(c1 != c2) return c1 < c2;
    }

    return t1.nombre.size() < t2.nombre.size();
}

int main(){
    int n, m;
    cin >> n;
    cin.ignore();
    while(n--){
        int casos = 0;
        msvT mapa;
        vT lista;
        msvT::iterator itr;
        string name, temp;
        getline(cin, name);
        cin >> m;
        cin.ignore();
        
        while(m--){
            getline(cin, temp);
            Team t(temp);
            mapa[temp].push_back(t);
        }

        cin >> m;
        cin.ignore();
        while(m--){
            getline(cin, temp);
            quitar(temp, mapa);
        }
    
        for(itr = mapa.begin(); itr != mapa.end(); ++itr) lista.push_back(itr->second[0]);
    
        sort(lista.begin(), lista.end(), compare);

        cout << name << endl;
        for(int i = 0; i < lista.size(); ++i){
            printf("%d) ", ++casos);
            cout << lista[i].nombre;
            printf(" %dp, %dg ",  lista[i].puntos, lista[i].partidos);
            printf("(%d-%d-%d), ", lista[i].ganados, lista[i].empatados, lista[i].perdidos);
            printf("%dgd ", lista[i].difGol);
            printf("(%d-%d)\n", lista[i].golesF, lista[i].golesC);
        } 
        
        if(n) cout << endl;
    }
    return 0;
}