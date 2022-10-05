#include <iostream>
#include <stdio.h>

using namespace std;

void cambio(char &x){
    if(x == '1') x = 'I';

    else if(x == '2') x = 'Z';

    else if(x == '3') x = 'E';

    else if(x == '4') x = 'A';

    else if(x == '5') x = 'S';

    else if(x == '6') x = 'G';

    else if(x == '7') x = 'T';

    else if(x == '8') x = 'B';

    else if(x == '9') x = 'P';

    else if(x == '0') x = 'O';
}

int main(){
    int n;
    cin >> n;
    char x;
    scanf("%c", &x);
    while(n--){
        int cont = 0;
        bool ver = true;
        while(1){
            scanf("%c", &x);
            if(x == '\n'){
                ++cont;
                if(cont == 2) break;
            }
            
            else{
                if((int)x >= 48 && (int)x <= 57) cambio(x);
                cont = 0;
            }

            cout << x;
        }
        if(n) cout << x;
    }
    return 0;
}
