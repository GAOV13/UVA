#include <bits/stdc++.h>

#define pii pair<unsigned long long int, unsigned long long int>
#define endl '\n'

using namespace std;

pii busqueda(char anterior, string info, pii padre, pii temp, pii actual){
    for(int i = 1; i < info.size(); ++i){
        pii var;
        if(anterior == 'L' && info[i] == 'L'){
            padre = actual;
            var = make_pair((temp.first + actual.first), (temp.second + actual.second));
            actual = var;
        }

        else if(anterior == 'L' && info[i] == 'R'){
            var = make_pair((padre.first + actual.first), (padre.second + actual.second));
            temp = padre;
            anterior = 'R';
            padre = actual;
            actual = var;
        }

        else if(anterior == 'R' && info[i] == 'L'){
            var = make_pair((padre.first + actual.first), (padre.second + actual.second));
            temp = padre;
            anterior = 'L';
            padre = actual;
            actual = var;
        }

        else if(anterior == 'R' && info[i] == 'R'){
            padre = actual;
            var = make_pair((temp.first + actual.first), (temp.second + actual.second));
            actual = var;
        }
    }
    return actual;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        string temp;
        cin >> temp;
        pii padre = make_pair(1, 1), temp1, actual;
        if(temp[0] == 'L') temp1 = make_pair(0, 1);
        
        else temp1 = make_pair(1, 0);
        actual = make_pair((temp1.first + padre.first), (temp1.second + padre.second));
        actual = busqueda(temp[0], temp, padre, temp1, actual);
        cout << actual.first << '/' << actual.second << endl;
    }
    return 0;
}
