#include <iostream>
#include <vector>
#include <algorithm>

#define vP vector<Persona>
#define P Persona
#define endl '\n'

using namespace std;

class Persona{
    public:
        string nombre;
        int dia, mes, ano;

        void setear(string nombre, int dia, int mes, int ano){
            this->nombre = nombre;
            this->dia = dia;
            this->mes = mes;
            this->ano = ano;
        };

        
};

bool compare(P p1, P p2){
    if(p1.ano != p2.ano)
        return p1.ano < p2.ano;
    else if(p1.mes != p2.mes)
        return p1.mes < p2.mes;
    else 
        return p1.dia < p2.dia;
}

int main(){
    int n;
    while(cin >> n){
        vP lista(n);
        for(int i = 0; i < n; ++i){
            string nombre;
            int dia, mes, ano;
            cin >> nombre >> dia >> mes >> ano;
            lista[i].setear(nombre, dia, mes, ano);
        }
        sort(lista.begin(), lista.end(), compare);
        cout << lista[n - 1].nombre << endl;
        cout << lista[0].nombre << endl;
    }
    return 0;
}
