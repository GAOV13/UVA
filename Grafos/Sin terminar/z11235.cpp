#include <bits/stdc++.h>

#define vi vector<int>
#define vti vector<tuple<int, int, int, int> >
#define pii pair<int, int>
#define endl '\n'
#define TAM_MAX 100000

using namespace std;

vi info(TAM_MAX);
vti tree(4*TAM_MAX, make_tuple(2147483647, -1, -2147483647, -1));

void build(int v, int l, int r){
    if(l == r) tree[v] = make_tuple(info[l], l, info[l], l);
    
    else{
        int m = l + ((r - l) >> 1);
        int v1 = (2 * v) + 1, v2 = 2 * (v + 1);
        int val_min, val_max, left_i, right_i;
        build(v1, l, m);
        build(v2, m + 1, r);
        int a1, b1, c1, d1;
        int a2, b2, c2, d2; 
        tie(a1, b1, c1, d1) = tree[v1];
        tie(a2, b2, c2, d2) = tree[v2];
        val_max = max(a1, a2);
        val_min = min(c1, c2);
        left_i = a1 == a2 ? b1 : b2;
        right_i = c1 == c2 ? d2 : d1;
        tree[v] = make_tuple(val_max, left_i, val_min, right_i); 
    }
}

pii getMin(int v, int L, int R, int l, int r){
    pii ans;
    if(l > r) ans = make_pair(2147483647, -1);
    else if(l == L && r == R){  
        int a, b, c, d;
        tie(a, b, c, d) = tree[v];
        ans = make_pair(c, d);
    }

    else{
        int m = L + ((R - L) >> 1);
        int v1 = (2 * v) + 1, v2 = 2 * (v + 1);
        pii tempi = getMin(v1, L, m, l, min(r, m)), tempd = getMin(v2, m + 1, R, max(m + 1, l), r);
        int minimo, right_i;
        minimo = min(tempi.first, tempd.first);
        if(tempi.first == 2147483647 && tempd.first != 2147483647) right_i = tempd.second;

        else if(tempi.first != 2147483647 && tempd.first == 2147483647) right_i = tempi.second;

        else if(tempi.first == 2147483647 && tempd.first == 2147483647) right_i = -1;

        else right_i = tempi.first == tempd.first ? tempd.second : tempi.second;
        
        ans = make_pair(minimo, right_i);
    }
    return ans;
}

pii getMax(int v, int L, int R, int l, int r){
    pii ans;
    if(l > r) ans = make_pair(-2147483647, -1);
    else if(l == L && r == R){  
        int a, b, c, d;
        tie(a, b, c, d) = tree[v];
        ans = make_pair(a, b);
    }

    else{
        int m = L + ((R - L) >> 1);
        int v1 = (2 * v) + 1, v2 = 2 * (v + 1);
        pii tempi = getMax(v1, L, m, l, min(r, m)), tempd = getMax(v2, m + 1, R, max(m + 1, l), r);
        int minimo, right_i;
        minimo = max(tempi.first, tempd.first);
        if(tempi.first == -2147483647 && tempd.first != -2147483647) right_i = tempd.second;

        else if(tempi.first != -2147483647 && tempd.first == -2147483647) right_i = tempi.second;

        else if(tempi.first == -2147483647 && tempd.first == -2147483647) right_i = -1;

        else right_i = tempi.first == tempd.first ? tempi.second : tempd.second;
        
        ans = make_pair(minimo, right_i);
    }
    return ans;
}

int main(){
    int n, m;
    while(cin >> n, n){
        cin >> m;
        fill(tree.begin(), tree.begin() + n, make_tuple(2147483647, -1, -2147483647, -1));
        for(int i = 0; i < n; ++i) cin >> info[i];

        build(0, 0, n - 1);
        while(m--){
            int ini, fin;
            int maximo = 1;
            cin >> ini >> fin;
            while(ini < fin){
                pii der = getMax(0, 0, n - 1, ini - 1, fin - 1), izq = getMin(0, 0, n - 1, ini - 1, fin - 1);
                int pos1 = izq.second, pos2 = der.second;
                maximo = max(maximo, fin - pos2);
                maximo = max(maximo, pos1 - ini + 2);
                ini = izq.second + 2;
                fin = der.second ;
            }
            cout << maximo << endl; 
        }
    }

    return 0;
}
