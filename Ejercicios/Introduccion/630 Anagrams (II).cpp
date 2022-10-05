#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

#define endl '\n'
#define msvs map<string, vector<string> >
#define vs vector<string>

using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        int m;
        cin >> m;
        string temp;
        msvs mapa;
        for(int i = 0; i < m; ++i){
            cin >> temp;
            string key = temp;
            sort(key.begin(), key.end());
            mapa[key].push_back(temp);
        }

        while(cin >> temp, temp != "END"){
            cout << "Anagrams for: " << temp << endl;
            string key = temp;
            sort(key.begin(), key.end());
            vs dev = mapa[key];
            if(!dev.size()) cout << "No anagrams for: " << temp << endl;

            else{
                int num = 0;
                
                for(int i = 0; i < dev.size(); ++i){
                    printf("  %d) ", ++num); 

                    cout << dev[i] << endl;
                }
            }
        }

        if(n) cout << endl;
    }
}
