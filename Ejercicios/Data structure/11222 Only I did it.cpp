#include <bits/stdc++.h>

#define endl '\n'
#define misi map<int, set<int> >
#define vvi vector<vector<int> >

using namespace std;

int main(){
    int n, casos = 0;
    cin >> n;
    while(n--){
        misi mapa;
        for(int i = 0; i < 3; ++i){
            int temp;
            cin >> temp;
            for(int j = 0; j < temp; ++j){
                int num;
                cin >> num;
                mapa[num].insert(i);
            }
        }

        int maxi = 0;
        vvi info(3);
        for(auto itr = mapa.begin(); itr != mapa.end(); ++itr){
            if(itr->second.size() == 1){
                info[*(itr->second.begin())].push_back(itr->first);
                if(info[*(itr->second.begin())].size() > maxi) maxi = info[*(itr->second.begin())].size();
            }
        }
        cout << "Case #" << ++casos  << ":" << endl;
        for(int i = 0; i < 3; ++i){
            if(info[i].size() == maxi){
                cout << i + 1 << " " << maxi;
                for(int j = 0; j < maxi; ++j) cout << " " << info[i][j];

                cout << endl;
            }
        }
    }
    return 0;
}