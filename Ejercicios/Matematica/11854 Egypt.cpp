#include <iostream>

#define endl '\n'

using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    while(a && b && c){
        bool ver = false;
        if(a >= b && a >= c){
            if((b*b) + (c*c) == (a*a)) ver = true;        
        }

        else if(b >= a && b >= c){
            if((a*a) + (c*c) == (b*b)) ver = true;
        }
        
        else{
            if((b*b) + (a*a) == (c*c)) ver = true;
        }
        
        if(ver) cout << "right" << endl;

        else cout << "wrong" << endl;

        cin >> a >> b >> c;
    }
    return 0;
}
