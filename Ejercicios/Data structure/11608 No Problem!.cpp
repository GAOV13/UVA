#include <iostream>
#include <vector>

#define endl '\n'
#define vi vector<int>

using namespace std;

int main(){
    int n, casos = 0;
    cin >> n;
    while(n > -1){
        vi lista(13, 0);
        lista[0] = n;
        for(int i = 1; i < 13; ++i){
            cin >> n;
            lista[i] = n;
        }

        cout << "Case " << ++casos << ":" << endl;
        int sum = lista[0];
        for(int i = 0; i < 12; ++i){
            cin >> n;
            if(n <= sum){
                cout << "No problem! :D" << endl;
                sum -= n;
            } 

            else cout << "No problem. :(" << endl;

            sum += lista[i + 1];
        }
        cin >> n;
    }
    return 0;
}
