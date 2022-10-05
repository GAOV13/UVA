#include <bits/stdc++.h>

#define endl '\n'
#define vi vector<int>

using namespace std;

vi anagramaticPrimes = {2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, 97, 113, 131, 199, 311, 337, 373, 733, 919, 991};

int main(){
    int num;
    while(cin >> num, num){
        if(num >= 991){
            cout << 0 << endl;
            continue;
        }
        vi::iterator itr = upper_bound(anagramaticPrimes.begin(), anagramaticPrimes.end(), num);
        if(itr == anagramaticPrimes.end())
            cout << 0 << endl;
        else if(*itr > pow(10, floor(log10(num)) + 1))
            cout << 0 << endl;
        else
            cout << *itr << endl;
    }
    return 0;
}