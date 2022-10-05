#include <bits/stdc++.h>

#define ls list<string>
#define endl '\n'

using namespace std;

void eliminar(string str){
    ls lista(1);
    ls::iterator itr;
    string temp = "";
    bool frente = false;
    for(int i = 0; i < str.size(); ++i){
        if(str[i] == '['){
            frente = true;
            if(temp != "")
                lista.push_front(temp);
            temp = "";
        }
        else if(str[i] == ']'){
            frente = false;
            if(temp != "")
                lista.push_front(temp);
            temp = "";
        }
        else if(!frente){
            itr = lista.end();
            *(--itr) += str[i];
        }
        else if(frente)
            temp += str[i];
    }

    cout << temp;
    for(itr = lista.begin(); itr != lista.end(); ++itr) cout << *itr;
}

int main(){
    string res;
    while(cin >> res){
        eliminar(res);
        cout << endl;
    }
    return 0;
}
