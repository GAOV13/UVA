#include <iostream>
#include <vector>

#define vi vector<int>
#define endl '\n'

using namespace std;

int max(int a, int b){
    return a > b ? a : b;
}

int max(int a, int b, int c){
    return max(max(a, b), c);
}

int crossArray(vi &lista, int low, int mid, int hi){
    int leftSum = 0, rightSum = 0, suma = 0;
    for(int i = mid; i >= low; --i){
        suma += lista[i];
        leftSum = max(suma, leftSum);
    }
    suma = 0;
    for(int i = mid+1; i <= hi; ++i){
        suma += lista[i];
        rightSum = max(suma, rightSum);
    }
    return max(leftSum+rightSum, leftSum, rightSum);
}

int rangeSum(vi &lista, int low, int hi){
    int ans;
    if(low == hi) ans = lista[low];
    else{
        int mid = (low + hi)/2;
        ans = max(rangeSum(lista, low, mid), rangeSum(lista, mid+1, hi), crossArray(lista, low, mid, hi));
    }
    return ans;
}

int main(){
    int n;
    while(cin >> n, n){
        vi lista(n);
        for(int i = 0; i < n; ++i) cin >> lista[i];
        int ans = rangeSum(lista, 0, lista.size() - 1);
        if(ans) cout << "The maximum winning streak is " << ans << "." << endl;
        else cout << "Losing streak." << endl;
    }
    return 0;
}