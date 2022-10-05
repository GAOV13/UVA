#include <iostream>
#include <vector>

#define endl '\n'
#define vi vector<int>

using namespace std;

int main(){
    int n; 
    cin >> n;
    int t = 0;
    while(n){
        vi bloques(n);
        int max = 0, mov = 0;
        for(int i = 0; i < n; ++i){
            cin >> bloques[i];
            max += bloques[i];
        }

        max = max/n;
        for(int i = 0; i < n; ++i){
            if(bloques[i] > max) mov += bloques[i] - max;
        }
        
        cout << "Set #" << ++t << endl;
        cout << "The minimum number of moves is " << mov << ".\n" << endl;
        cin >> n;
    }
}
