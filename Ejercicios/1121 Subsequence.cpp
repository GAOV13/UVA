#include <iostream>
#include <vector>

#define endl '\n'
#define vi vector<int>

using namespace std;

int main(){
    int n, sum;
    while(scanf("%d %d", &n, &sum) != EOF){
        vi lista(n);
        for(int i = 0; i < n; ++i) cin >> lista[i];

        int menor, mayor, temp, min = 100000;
        menor = mayor = 0;
        temp = lista[0];
        while(mayor < n){
            if(temp >= sum)
                min = min > mayor - menor + 1 ? mayor - menor + 1 : min;
            
            if(temp >= sum && menor < mayor){
                temp -= lista[menor];
                ++menor;
            }

            else if(temp < sum){
                ++mayor;
                if(mayor < n) temp += lista[mayor];
            }
        }

        if(min == 100000) cout << 0 << endl;

        else cout << min << endl;
    }
}
