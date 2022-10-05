#include <bits/stdc++.h>

#define endl '\n'
#define vi vector<int>

using namespace std;

int main(){
    int num, dem;
    while(cin >> num){
        cin >> dem;
        vi lista;
        bool ver = true;
        while(ver){
            int k = num / dem;
            lista.push_back(k);
            if(num % dem == 0) ver = false;

            else{
                num = num % dem;
                k = num;
                num = dem;
                dem = k;
            }
        }

        cout << '[' << lista[0];
        if(lista.size() > 1){
            cout << ';' << lista[1];
            for(int i = 2; i < lista.size(); ++i) cout << ',' << lista[i];
        }

        cout << "]" << endl;
    }
    return 0;
}
