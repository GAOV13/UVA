#include <bits/stdc++.h>

#define endl '\n'
#define pqi priority_queue<int>
#define vi vector<int>

using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        pqi cola;
        for(int i = 0; i < n; ++i){
            int k;
            cin >> k;
            cola.push(k);
        }

        bool ver = true;
        vi lista(n);
        for(int i = n - 1; i >= 0; --i){
            lista[i] = cola.top();
            cola.pop();
        }

        for(int i = 0; i < n - 1 && ver; ++i){
            if(lista[i + 1] - lista[i] > 200) ver = false;
        }
        int num;
        num = 1422 - lista[n - 1];
        num *= 2;
        if(num > 200) ver = false;

        if(ver) cout << "POSSIBLE" << endl;

        else cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
