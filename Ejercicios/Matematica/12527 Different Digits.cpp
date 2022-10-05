#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

string numeroAString(int num){
    ostringstream stream;
    stream << num;
    return stream.str();
}

int contar(int &ini, int &fin){
    int num = 0;
    for(int i = ini; i <= fin; ++i){
        string n = numeroAString(i);
        if(n.size() == 1) ++num;

        else if(n.size() == 2){
            if(n[0] != n[1]) ++num;
        }

        else if(n.size() == 3){
            if(n[0] != n[1] && n[0] != n[2] && n[1] != n[2]) ++num;
        }

        else if(n.size() == 4){
            if(n[0] != n[1] && n[0] != n[2] && n[0] != n[3] && n[1] != n[2] && n[1] != n[3] && n[2] != n[3]) ++num;
        }
    }

    return num;
}

int main(){
    int ini, fin;
    while(cin >> ini){
        cin >> fin;
        cout << contar(ini, fin) << endl;
    }
    return 0;
}
