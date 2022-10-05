#include <bits/stdc++.h>

#define endl '\n'
#define vi vector<int>
#define vt vector<pair<vector<int>, string> >

using namespace std;

vi meses = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int cant_dias = 365;

bool compare(pair<vector<int>, string> p1, pair<vector<int>, string> p2){
    if(p1.first[0] != p2.first[0])
        return p1.first[0] < p2.first[0];
    else if(p1.first[1] != p2.first[1])
        return p1.first[1] < p2.first[1];
    else if(p1.first[2] != p2.first[2])
        return p1.first[2] > p2.first[2];
    else
        return p1.first[3] < p2.first[3];
}

int calculo(int dia, int mes, int mes2){
    int t = 0;
    if(mes2 == 12 and mes == 1) t += cant_dias;
    for(int i = 0; i < mes-1; ++i)
        t += meses[i];
    return t + dia;
}

void imprimir(vt &ans, int dia, int mes){
    printf("Today is: %2d %2d\n", dia, mes);
    for(int i = 0; i < ans.size(); ++i){
        if(ans[i].first[0] == 13) ans[i].first[0] = 1;
        printf(" %2d %2d ", ans[i].first[1], ans[i].first[0]);
        if(ans[i].first[2] == 0) printf("*TODAY* ");
        else{
            for(int j = 0; j < 7; ++j){
                if(ans[i].first[2]-- > 0) cout << "*";
                else cout << " ";
            }
            cout << " ";
        }
        cout << ans[i].second << endl;
    }
}

int main(){
    int anio, t = 0;
    cin >> anio;
    if(anio%4==0){
        ++meses[1];
        ++cant_dias;
    }
    char c;
    int dia, mes, prio;
    string temp;
    vt lista;
    while(cin >> c, c == 'A'){
        cin >> dia >> mes >> prio >> temp;
        string temp1;
        getline(cin, temp1);
        temp += temp1;
        vi t2 = {++t, dia, mes, prio};
        lista.push_back(make_pair(t2, temp));
    }

    bool ver = false;
    while(c == 'D'){
        if(ver) cout << endl;
        ver = true;
        cin >> dia >> mes;
        t = calculo(dia, mes, mes);
        vt ans;
        for(int i = 0; i < lista.size(); ++i){
            int dia1 = lista[i].first[1], mes1 = lista[i].first[2];
            int t1 = calculo(dia1, mes1, mes);
            if(t1 > t){
                if(mes == 12 and mes1 == 1) mes1 = 13;
                int p = lista[i].first[3]-(t1-t-1);
                if(p > 0){
                    vi mier = {mes1, dia1, p, lista[i].first[0]};
                    ans.push_back(make_pair(mier, lista[i].second));
                }
            }
            
            else if(t1 == t){
                vi mier = {mes, dia, 0, lista[i].first[0]};
                ans.push_back(make_pair(mier, lista[i].second));
            }
        }
        sort(ans.begin(), ans.end(), compare);
        imprimir(ans, dia, mes);
        cin >> c;
    }
    return 0;
}