#include <iostream>
#include <map>
#include <iterator>

#define endl '\n'
#define msi map<string, int>

using namespace std;

int main(){
    int n;
    string temp;
    while(cin >> n){
        cin >> temp;
        string::iterator itr = temp.begin();
        bool ver = true;
        int i = 0;
        msi datos;
        int max = 0;
        string dev;
        while(ver){
            if(itr + n > temp.end()) ver = false;

            else{
                string key(itr, itr + n);
                ++itr;
                if(++datos[key] > max){
                    max = datos[key];
                    dev = key;
                }
            } 
        }

        cout << dev << endl;
    }
    return 0;
}
