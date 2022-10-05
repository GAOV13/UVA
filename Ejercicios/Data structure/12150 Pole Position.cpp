#include <iostream>
#include <vector>

#define endl '\n'
#define vi vector<int>

using namespace std;

int main(){
    int n; 
    while(cin >> n, n != 0){
        vi lista(n, 0);
        int dat = 0;
        for(int i = 0; i < n; ++i){
            int num, cuanto;
            cin >> num >> cuanto;
            if(cuanto > 0 && cuanto + i < n && lista[i + cuanto] == 0){
                lista[i + cuanto] = num;
                ++dat;
            }

            else if(cuanto <= 0 && i + cuanto >= 0 && lista[i + cuanto] == 0){
                lista[i + cuanto] = num;
                ++dat;
            }
        }

        if(dat == n){
            cout << lista[0];
            for(int i = 1; i < n; ++i) cout << " " << lista[i];
        }

        else cout << "-1";

        cout << endl;
    }
}
