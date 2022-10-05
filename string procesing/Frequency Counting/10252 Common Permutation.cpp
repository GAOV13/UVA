#include <iostream>
#include <algorithm>

#define endl '\n'

using namespace std;

/*
Caso a considerar:
thetet
street
Si no cambio algo en la variable me va a dar eettt. Y la
respuesta es eett.
*/

int main(){
    string temp1, temp2;
    while(getline(cin, temp1)){
        getline(cin, temp2);
        string dev = "";
        for(int i = 0; i < temp1.size(); ++i){
            for(int j = 0; j < temp2.size(); ++j){
                if(temp1[i] == temp2[j]){
                    temp2[j] = '-';
                    dev += temp1[i];
                    break;
                } 
            }
        }

        sort(dev.begin(), dev.end());
        cout << dev << endl;
    }
    return 0;
}
