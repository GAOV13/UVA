#include <bits/stdc++.h>

#define endl '\n'
#define vi vector<int>
#define vvi vector<vector<int> >

using namespace std;

vvi dev;

void backTracking(vi &lista, int i, vi acum){
    if(acum.size() == 6){
        dev.push_back(acum);
        return;
    }

    if(i >= lista.size()) return;

    vi temp = acum;
    temp.push_back(lista[i]);
    backTracking(lista, i + 1, temp);
    backTracking(lista, i + 1, acum);

}

int main(){
    int k;
    bool ver = false;
    while(cin >> k, k != 0){
        if(ver) cout << endl;

        ver = true;
        vi lista(k);
        for(int i = 0; i < k; ++i) cin >> lista[i];

        dev.clear();
        vi temp;
        backTracking(lista, 0, temp);

        for(int i = 0; i < dev.size(); ++i){
            cout << dev[i][0];
            for(int j = 1; j < 6; ++j) cout << " " << dev[i][j];

            cout << endl;
        }
    }
    return 0;
}
