#include <bits/stdc++.h>

#define vpii vector<pair<int,int> >
#define pii pair<int, int>
#define endl '\n'

using namespace std;

pii ini, fin;
bool ver;

void phi(int n, int v, vpii &A){
    if(!n){
        if(v == fin.first) ver = true;
    }
    else if(!ver){
        for(int i = 0; i < A.size() && !ver; ++i){
            if(A[i].first != -1 && (A[i].first == v || A[i].second == v)){
                pii temp = A[i];
                A[i] = make_pair(-1, -1);
                int u = temp.first == v ? temp.second : temp.first;
                phi(n-1, u, A);
                A[i] = temp;
            }
        }
    }
}

int main(){
    int n, m;
    while(cin >> n, n){
        cin >> m;
        cin >> ini.first >> ini.second;
        cin >> fin.first >> fin.second;
        vpii A(m);
        for(int i = 0; i < m; ++i)
            cin >> A[i].first >> A[i].second;
        
        ver = false;
        if(n <= m)
            phi(n, ini.second, A);
        if(ver)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}