#include <bits/stdc++.h>

#define vlli vector<long long int>
#define lli long long int
#define endl '\n'

using namespace std;

lli cambios;

void merge(vlli &lista, lli low, lli mid, lli hi){
    lli i, j, k;
    lli n1 = mid - low + 1, n2 = hi - mid;
    vlli izq(n1 + 2), der(n2 + 2);
    for(i = 1; i <= n1; ++i) izq[i] = lista[low + i - 1];

    for(i = 1; i <= n2; ++i) der[i] = lista[mid + i];

    izq[n1 + 1] = der[n2 + 1] = 10000000000;
    i = j = 1;
    for(k = low; k <= hi; ++k){
        if(izq[i] <= der[j]){
            lista[k] = izq[i];
            ++i;
        }

        else{
            lista[k] = der[j];
            cambios += n1 - i + 1;
            j++;
        }
    }
}

void merge_sort(vlli &lista, lli low, lli hi){
    if(low < hi){
        lli mid = (hi + low)/2;
        merge_sort(lista, low, mid);
        merge_sort(lista, mid + 1, hi);
        merge(lista, low, mid, hi);
    }
}

int main(){
    lli n;
    while(cin >> n){
        cambios = 0;
        vlli lista(n + 1);
        for(lli i = 1; i <= n; ++i) cin >> lista[i];

        lli p = 1;
        merge_sort(lista, p, n);
        cout << cambios << endl;
    }
    return 0;
}
