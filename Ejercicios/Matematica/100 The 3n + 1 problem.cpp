#include <iostream>
#include <stdio.h>

#define endl '\n'
#define lli long long int

using namespace std;

int main(){
    lli ini, fin;
    lli num;
    while(cin >> ini){
        cin >> fin;
        int ver = 0;
        if(fin < ini){
            num = fin;
            fin = ini;
            ini = num;
            ++ver;
        }
        num = 0;
        for(lli i = ini; i <= fin; ++i){
            lli k = i;
            lli intento = 1;
            label:
                if(k == 1) goto label1;

                else if(k % 2 == 0) k = k/2;

                else k = 3*k + 1;

                ++intento;
                goto label;

            label1:
                num = num < intento ? intento : num;
        }

        if(!ver) printf("%lli %lli %lli\n", ini, fin, num);

        else printf("%lli %lli %lli\n", fin, ini, num);
    }
    return 0;
}
