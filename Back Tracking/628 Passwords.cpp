#include <bits/stdc++.h>

#define vs vector<string>
#define endl '\n'

using namespace std;

void backtracking(string &linea, int indice, vs &palabras, string temp){
    if(linea[indice] == '0'){
        for(int i = 0; i <= 9; ++i){
            if(indice == linea.size() - 1) cout << temp + (char)(i + 48) << endl;

            else backtracking(linea, indice + 1, palabras, temp + (char)(i + 48));
        }
    }

    else{
        for(int i = 0; i < palabras.size(); ++i){
            if(indice == linea.size() - 1) cout << temp + palabras[i] << endl;

            else backtracking(linea, indice + 1, palabras, temp + palabras[i]);
        }
    }
}

int main(){
    int n;
    while(cin >> n){
        cout << "--" << endl;
        vs palabras(n);
        for(int i = 0; i < n; ++i) cin >> palabras[i];

        int m;
        cin >> m;
        while(m--){
            string linea;
            cin >> linea;
            backtracking(linea, 0, palabras, "");
        }
    }
}
