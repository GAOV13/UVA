#include <bits/stdc++.h>

#define si set<pair<int, int> >

using namespace std;

int main(){
    int T, casos = 0;
    cin >> T;
    while(T--){
        int t1, t2, f, a, num;
        si conj;
        cin >> t1 >> t2 >> f >> a;
        for(int i = 0; i < 3; ++i){
            cin >> num;
            conj.insert(make_pair(num, i));
        }
        si::iterator itr = conj.end(), itr1 = conj.begin();
        itr--; itr1++;
        num = t1+t2+f+a+((itr->first + itr1->first)/2);
        char c;
        if(num < 60) c = 'F';
        else if(num < 70) c = 'D';
        else if(num < 80) c = 'C';
        else if(num < 90) c = 'B';
        else c = 'A';
        cout << "Case " << ++casos << ": ";
        cout << c << endl;   
    }
    return 0;
}