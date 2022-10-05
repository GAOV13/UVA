#include <bits/stdc++.h>

#define endl '\n'
#define vp vector<pair<vector<int>, int> >
#define vi vector<int>
#define pvi pair<vector<int>, int> 

using namespace std;

double prom;

bool compare(int p1, int p2){
    return p1 > p2;
}

double rendondear(double x, int n){
    x = x * (double)pow(10, n);
    x += 0.5;
    int x1 = x;
    x = (double)x1/(double)(pow(10, n));
    return x;
}

bool compare1(pvi p1, pvi p2){
    bool ans;
    if(p1.first.size() == 2 || p2.first.size() == 2) ans = p1.first.size() < p2.first.size();
    else ans = p1.second < p2.second;
    return ans;
}

void imprimir(vp &C, double ans, int caso){
    cout << "Set #" << caso << endl;
    for(int i = 0; i < C.size(); ++i){
        cout << " " << i << ":";
        for(int j = 0; j < C[i].first.size(); ++j)
            cout << " " << C[i].first[j];
        cout << endl;
    }
    printf("IMBALANCE = %.5f\n", ans);
}

double phi(vp &C, vi &pesos){
    double ans = 0;
    for(int i = 0; i < pesos.size(); ++i){
        C[0].first.push_back(pesos[i]);
        C[0].second += pesos[i];
        sort(C.begin(), C.end(), compare1);
    }
    for(int i = 0; i < C.size(); ++i){
        ans += (double)abs(prom-(double)C[i].second);
    }
    return rendondear(ans, 5);
}

int main(){
    int n, m, caso=0;
    while(cin >> n >> m){
        vp C(n, make_pair(vi(0), 0));
        vi pesos(m);
        prom = 0;
        for(int i = 0; i < m; ++i){ 
            cin >> pesos[i];
            prom += pesos[i];
        }
        prom /= (double)n;
        sort(pesos.begin(), pesos.end(), compare);
        double ans = phi(C, pesos);
        imprimir(C, ans, ++caso);
        cout << endl;
    }
    return 0;
}