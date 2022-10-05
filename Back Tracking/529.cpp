#include <bits/stdc++.h>

#define endl '\n'
#define vi vector<int>

using namespace std;

vi ans;

void back(int n, vi res, int &size);

int main(){
  int n;
  while(cin >> n, n){
    ans.clear();
    int size = 2147483647;
    back(n, vi(1, 1), size);
    cout << 1;
    for(int i = 1; i < size; ++i) cout << " " << ans[i];
    cout << endl;
  }
  return 0;
}

void back(int n, vi res, int &size){
  if(res.size() < size){
    if(res[res.size() - 1] == n){
      ans.clear();
      for(int i = 0; i < res.size(); ++i) ans.push_back(res[i]);
      size = res.size();
    }
    else if(res[res.size() - 1] < n){
      for(int i = res.size() - 1; i >= 0 && res[i] + res[i] > res[res.size() - 1]; --i){
        for(int j = i; j >= 0 && res[i] + res[j] > res[res.size() - 1]; --j){
          res.push_back(res[i] + res[j]);
          back(n, res, size);
          res.pop_back();
        }
      }
    }
  }
}