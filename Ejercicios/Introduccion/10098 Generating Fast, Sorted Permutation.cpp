#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'
#define vs vector<string>

using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        string temp;
        cin >> temp;
        vs resp;
        sort(temp.begin(), temp.end());
        resp.push_back(temp);
        while(next_permutation(temp.begin(), temp.end())) resp.push_back(temp);

        sort(resp.begin(), resp.end());
        for(int i = 0; i < resp.size(); ++i) cout << resp[i] << endl;

        cout << endl;
    }
}
