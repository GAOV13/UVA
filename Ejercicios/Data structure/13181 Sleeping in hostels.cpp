#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
    string str;;
    while(cin >> str){
        int val = 0, index = -1;
        int n = str.size();
        for(int i = 0; i < n; ++i){
            if(str[i] == 'X'){
                if(index == -1){
                    val = max(val, i - 1);
                    index = i;
                }
                else{
                    val = max(val, (i - index - 2)/2);
                    index = i;
                }
            }
        }
        if(index != str.size() - 1) val = max(val, n - index - 2);
        cout << val << endl;
    }
    return 0;
}