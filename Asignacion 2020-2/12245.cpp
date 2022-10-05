#include <bits/stdc++.h>

#define endl '\n'
#define pi pair<int, int>
#define vpi vector<pair<int, int> >

using namespace std;

bool compare(pi par1, pi par2){
    if(par1.second != par2.second) 
        return par1.second < par2.second;
    
    return par1.first >= par2.first;
}

int main(){
    int n, m;
    while(cin >> n >> m, n || m){
        vpi lista(m);
        for(int i = 0; i < m; ++i)
            cin >> lista[i].first >> lista[i].second;
        
        sort(lista.begin(), lista.end());
        for(int i = 0; i < m; ++i)
            cout << lista[i].first << ' ' << lista[i].second << endl;
        
        sort(lista.begin(), lista.end(), compare);
        cout << endl;
        for(int i = 0; i < m; ++i)
            cout << lista[i].first << ' ' << lista[i].second << endl;
            
        cout << endl;
    }

    return 0;
}
