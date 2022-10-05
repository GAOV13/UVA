#include <iostream>

#define endl '\n'

using namespace std;

int main(){
    int a[5];
    int b[5];
    while(scanf("%d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4]) != EOF){
        scanf("%d %d %d %d %d", &b[0], &b[1], &b[2], &b[3], &b[4]);
        bool ver = true;
        for(int i = 0; i < 5 && ver; ++i){
            if(a[i] xor b[i] == false) ver =  false;
        }

        if(ver) cout << "Y" << endl;

        else cout << "N" << endl;
    }
}
