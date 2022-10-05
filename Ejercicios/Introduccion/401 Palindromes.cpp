#include <bits/stdc++.h>

#define endl '\n'
#define vi vector<int>

using namespace std;

vi listado(127, 0);

void llenar(){
    listado['A'] = 'A';
    listado['E'] = '3';
    listado['H'] = 'H';
    listado['I'] = 'I';
    listado['J'] = 'L';
    listado['L'] = 'J';
    listado['M'] = 'M';
    listado['O'] = 'O';
    listado['S'] = '2';
    listado['T'] = 'T';
    listado['U'] = 'U';
    listado['V'] = 'V';
    listado['W'] = 'W';
    listado['X'] = 'X';
    listado['Y'] = 'Y';
    listado['Z'] = '5';
    listado['1'] = '1';
    listado['2'] = 'S';
    listado['3'] = 'E';
    listado['5'] = 'Z';
    listado['8'] = '8';
}

int main(){
    llenar();
    string temp;
    while(cin >> temp){
        bool pali = false, mirro = false;
        string ver = temp;
        reverse(ver.begin(), ver.end());
        if(ver == temp) pali = true;

        ver = "";
        for(int i = 0; i < temp.size(); ++i)
            ver += listado[temp[i]];
        
        if(ver.size() == temp.size()){
            reverse(ver.begin(), ver.end());
            if(ver == temp) mirro = true;
        }
        
        if(pali && mirro) cout << temp << " -- is a mirrored palindrome." << endl;

        else if(pali) cout << temp << " -- is a regular palindrome." << endl;

        else if(mirro) cout << temp << " -- is a mirrored string." << endl;

        else cout << temp << " -- is not a palindrome." << endl;

        cout << endl;
    }

    return 0;
}
