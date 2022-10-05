#include <bits/stdc++.h>

#define endl '\n'
#define lpii list<pair<int, int> >

using namespace std;

int main(){
    int n;
    while(cin >> n){
        int cant = 0;
        lpii lista(1, make_pair(0, -1));
        for(int i = 0; i < n; ++i){
            bool ver = true;
            int temp;
            cin >> temp;
            lpii::iterator itr = lista.end();
            itr--;
            while(ver){
                if(itr == lista.begin()){
                    cant += temp;
                    itr++;
                    lista.insert(itr, make_pair(temp, temp));
                    ver = false;
                }
                else if(temp < (*itr).first && (*itr).second >= temp){
                    (*itr).second -= temp;
                    itr++;
                    lista.insert(itr, make_pair(temp, temp));
                    ver = false;
                }
                else itr--;
            }
        }
        cout << cant << endl;     
    }
    return 0;
}