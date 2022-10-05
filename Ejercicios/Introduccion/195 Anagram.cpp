#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'
#define vs vector<string>

using namespace std;

void toLower(char &x){
    if((int)x >= 65 && (int)x <= 90) x += 32;
}

bool compare(string str1, string str2){
    char x1, x2;
    for(int i = 0; i < str1.size(); ++i){
        if((int)str1[i] == (int)str2[i]) continue;

        x1 = str1[i]; x2 = str2[i];
        toLower(x1); toLower(x2);
        if((int)x1 != (int)x2) return (int)x1 > (int)x2;

        else  return (int)str1[i] > (int)str2[i];
    }

    return false;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        string temp;
        cin >> temp;
        vs lista;
        sort(temp.begin(), temp.end());
        lista.push_back(temp);
        while(next_permutation(temp.begin(), temp.end())){
            lista.push_back(temp);
        }
        sort(lista.begin(), lista.end(), compare);
        for(int i = lista.size() - 1; i >= 0; --i) cout << lista[i] << endl;
    }
}
