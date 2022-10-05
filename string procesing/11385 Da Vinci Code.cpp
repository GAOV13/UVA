#include <bits/stdc++.h>
#include <stdio.h>

#define endl '\n'
#define vlli vector<long long int>
#define vpllic vector<pair<long long int, char> >
#define pic pair<long long int, char>

using namespace std;

string respuesta(vpllic lista, int tam){
    long long int fibo = 2, ant = 1, temp;
    int limit = lista[tam - 1].first;
    int i = 0;
    string str = "";
    while(ant <= limit){
        if(ant == lista[i].first){
            str += lista[i].second;
            ++i;
        }

        else str += ' ';

        temp = fibo;
        fibo += ant;
        ant = temp;
    }

    return str;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        vlli temp;
        int tam;
        cin >> tam;
        for(int i = 0; i < tam; ++i){
            long long int num;
            cin >> num;
            temp.push_back(num);
        }

        char x = '\n';
        while((int)x < 65) scanf("%c", &x);
        

        int index = 0;
        vpllic lista(tam);
        while((int)x != 10){
            if(((int)x >= 65 && (int)x <= 90) && index < tam){
                pic par = make_pair(temp[index], x);
                lista[index] = par;
                ++index;
            }
            scanf("%c", &x);
        }
        
        sort(lista.begin(), lista.end());
        cout << respuesta(lista, tam) << endl;
    }
    return 0;
}
