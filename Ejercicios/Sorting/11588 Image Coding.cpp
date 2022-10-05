#include <iostream>
#include <map>
#include <cmath>

#define mci map<char, int>
#define endl '\n'

using namespace std;

int main(){
    int caso, casos = 0;
    cin >> caso;
    while(caso--){
        int fil, col, M, N;
        cin >> fil >> col >> M >> N;
        mci mapa;
        int maxi = 0;
        for(int i = 0; i < fil; ++i){
            string temp;
            cin >> temp;
            for(int j = 0; j < col; ++j)
                maxi = max(maxi, ++mapa[temp[j]]);
        }

        int suma = 0;
        for(auto i = mapa.begin(); i != mapa.end(); ++i){
            if(i->second == maxi)
                suma += (M*i->second);
            else
                suma += (N*i->second);
        }
        cout << "Case " << ++casos << ": " << suma << endl;
    }
    return 0;
}