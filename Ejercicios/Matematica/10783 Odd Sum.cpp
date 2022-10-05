#include <iostream>
#include <math.h>

#define endl '\n'

using namespace std;

int main(){
    int a, b, n, caso = 0;
    cin >> n;
    while(n--){
        cin >> a >> b;
        int a1 = a, an = b;
        float m = b - a + 1;
        if(a % 2 == 0 && b % 2 == 0) m = floor(m/2);

        else m = ceil(m/2);
        if(a % 2 == 0 && a + 1 <= b) ++a1;

        if(b % 2 == 0 && b - 1 >= a) --an;

        int sum = ((a1 + an)*m)/2;
        cout << "Case " << ++caso << ": " << sum << endl;
 
    }
    return 0;
}
