#include <bits/stdc++.h>

#define endl '\n'
#define vpi vector<pair<int, int> >

using namespace std;

int phi(int M, vpi &intervalos){
    int ans = 0, temp1 = 0, temp2 = -1;
    for(int i = 0; i < intervalos.size(); ++i){
        int ini = intervalos[i].first, fin = intervalos[i].second;
        if(ini <= temp1 && fin > temp2)
            temp2 = fin;
        else if(temp2 >= temp1 && ini > temp1){
            temp1 = temp2; temp2 = -1; ans += 1;
            if(temp1 >= M) 
                break;
            if(ini <= temp1 && fin > temp2) 
                temp2 = fin;
        }
        else if(temp2 < temp1 && ini > temp1){
            ans = -1;
            break;
        }
    }
    if(temp1 < M && temp2 >= M)
        ans += 1;
    else if(temp1 < M && temp2 < M)
        ans = -1;
    return ans;
}

int main(){
    int n, l;
    while(cin >> l >> n, n || l){
        vpi intervalos(n);
        for(int i = 0; i < n; ++i){
            int pos, r;
            cin >> pos >> r;
            intervalos[i] = make_pair(pos-r, pos+r);
        }
        sort(intervalos.begin(), intervalos.end());
        int ans = phi(l, intervalos);
        if(ans == -1) cout << -1 << endl;
        else cout << n - ans << endl;
    }
    return 0;
}