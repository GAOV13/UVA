#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

void busqueda(string preo, string ino){
    if(preo == "") return;

    char raiz = preo[0];
    string temppd = "", tempid = "", temppi = "", tempii = "";
    bool ver = true;
    int j = 1;
    for(int i = 0; i < ino.size(); ++i){
        if(ino[i] == raiz) ver = false;

        else if(ver){
            temppd += preo[j++];
            tempid += ino[i];
        }

        else{
            temppi += preo[j++];
            tempii += ino[i];
        }
    }
    busqueda(temppd, tempid);
    busqueda(temppi, tempii);
    cout << raiz;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        int m;
        string preo, ino;
        cin >> m >> preo >> ino;
        busqueda(preo, ino);
        cout << endl;
    }
    return 0;
}