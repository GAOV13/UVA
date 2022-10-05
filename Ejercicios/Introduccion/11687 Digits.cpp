#include <iostream>
#include <sstream>
#include <cmath>

#define endl '\n'

using namespace std;

string numeroAString(int num){
    ostringstream stream;
    stream << num;
    return stream.str();
}

int main(){
    string temp;
    cin >> temp;
    while(temp != "END"){
        string anterior = "-";
        int cant = 0;
        while(anterior != temp){
            anterior = temp;
            temp = numeroAString(temp.size());
            ++cant;
        }
        cout << cant << endl;
        cin >> temp;
    }
    return 0;
}
