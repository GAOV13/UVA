#include <bits/stdc++.h>

/*La aproximación fuerza bruta esta en el git Parcial 3, usar
  arboles de fenwick porque con segment tree no se logro*/
using namespace std;

int maxn = 5000;
vector<long long int> tree(maxn * 4);

void build(vector<int> a, int v, int l, int r){
    if(l == r) tree[v] = a[l];

    else{
        int m = l + ((r - l) >> 1);
        build(a, 2 * v + 1, l, m);
        build(a, 2 * (v + 1), m + 1, r);
        tree[v] = tree[2 * v + 1] + tree[2 * (v + 1)];
    }
}

int sum(int v, int L, int R, int l, int r){
    int ans = 0;
    if(l > r) ans = 0;
    else if(l == L and r == R) ans = tree[v];
    else{
        int m = L + ((R - L) >> 1);
        ans = sum(2 * v + 1, L, m, l, min(r, m)) + sum(2 * (v + 1), m + 1, R, max(l, m + 1), r);
        }    
    return ans;
}

void update(int v, int L, int R, int pos, int h){
    if(L == R) tree[v] = h;
    else{
        int m = L + ((R - L) >> 1);
        if(pos <= m) update(2 * v + 1, L, m, pos, h);
        else update(2 * (v + 1), m + 1, R, pos, h);
        tree[v] = tree[2 * v + 1] + tree[2 * (v + 1)];
    }
}

int main(){
    int n, m, si;
    cin >> n;
    while(n--){
        cin >> m;
        vector<int> a(m, 1);
        build(a, 0, 0, m - 1);
        for(int i = 0; i < m; ++i){
            if(i > 0) cout << " ";

            cin >> si;
            int v = sum(0, 0, m - 1, 0, si);
            a[v - 1] += i + 1;
            cout << v;
            update(0, 0, m - 1, v - 1, a[v - 1]);
        }
        cout << endl;  
    }
}