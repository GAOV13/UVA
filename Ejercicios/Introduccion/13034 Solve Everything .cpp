#include <iostream>

#define endl '\n'

using namespace std;

int main(){
    int s, n, casos = 0;
    cin >> s;
    while(s--){
        cout << "Set #" << ++casos << ": ";
        bool ver = true;
        for(int i = 0; i < 13; ++i){
            cin >> n;
            if(!n) ver = false; 
        }

        if(ver)  cout << "Yes" << endl;

        else cout << "No" << endl;
    }
    return 0;
}
