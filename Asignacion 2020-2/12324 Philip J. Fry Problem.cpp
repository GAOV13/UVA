#include <bits/stdc++.h>

#define pii pair<int, int>
#define vpii vector<pair<int, int> >
#define endl '\n'
#define pqi priority_queue<int>

using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        vpii lista(n);
        for(int i = 0; i < n; ++i){
            int num, dark;
            cin >> num >> dark;
            pii pair = make_pair(num, dark);
            lista[i] = pair;
        }
        pqi cola;
        int sum = 0;
        for(int i = n - 1; i >= 0; --i){
            int rest = lista[i].second;
            while(!cola.empty() && rest){
                int num = cola.top(); cola.pop();
                num = num/2;
                sum += num;
                --rest;
            }
            cola.push(lista[i].first);
        }

        while(!cola.empty()){
            sum += cola.top(); cola.pop();
        }

        cout << sum << endl;
    }
    return 0;
}
