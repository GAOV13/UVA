#include <iostream>

#define endl '\n'

using namespace std;

int f(int &a, int &b, int &c, int &d, int &l){
    int cant = 0;
    for(int i = 0; i <= l; ++i){
        int sum = (a*i*i) + (b*i) + (c);
        if(sum % d == 0) ++cant;
    }

    return cant;
}
int main(){
    int a, b, c, d, l;
    cin >> a >> b >> c >> d >> l;
    while(a || b || c || d || l){
        cout << f(a, b, c, d, l) << endl;
        cin >> a >> b >> c >> d >> l;
    }
    return 0;
}
