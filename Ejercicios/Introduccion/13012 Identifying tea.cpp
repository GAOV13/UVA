#include <iostream>

#define endl '\n'

using namespace std;

int main(){
    int tea, guess, cant;
    while(cin >> tea){
        cant = 0;
        for(int i = 0; i < 5; ++i){
            cin >> guess;
            if(guess == tea) ++cant;
        }
        cout << cant << endl;
    }
    return 0;
}
