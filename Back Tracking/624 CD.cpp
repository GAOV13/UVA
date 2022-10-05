#include <bits/stdc++.h>

#define endl '\n';
#define vi vector<int>

using namespace std;

vi dev;

void back(vi lista, int index, int &max, int acum, vi temp){
    if(acum == max){
        if(acum > dev[dev.size() - 1]){
            dev = temp;
            dev.push_back(acum);
        }
        return;
    }

    else if(acum > max) return;
    
    else if(index == lista.size()){
        if(acum > dev[dev.size() - 1]){
            dev = temp;
            dev.push_back(acum);
        }
        return;
    }

    vi temp1 = temp;
    temp.push_back(lista[index]);
    back(lista, index + 1, max, acum + lista[index], temp);
    back(lista, index + 1, max, acum, temp1);
}

int main(){
    int n;
    while(cin >> n){
        int tam;
        cin >> tam;
        vi lista(tam);
        for(int i = 0; i < tam; ++i){
            int k;
            cin >> k;
            lista[i] = k;
        }
        dev.clear();
        dev.push_back(0);
        back(lista, 0, n, 0, vector<int>(0));
        int i;
        for(i = 0; i < dev.size() - 1; ++i) cout << dev[i] << " ";

        cout << "sum:" << dev[i] << endl;
    }
    return 0;
}
