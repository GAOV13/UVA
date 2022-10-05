#include <bits/stdc++.h>

#define endl '\n'
#define vi vector<int>

using namespace std;

void back(vi &freq, int j, int &N, string acum){
  if(acum.size() == N)
    cout << acum << endl;
  else{
    for(int i = j; i < 26; ++i){
      for(int k = min(freq[i], N-(int)acum.size()); k > 0; --k){
        string temp = acum;
        for(int l = k; l > 0; --l)
          temp += (char)(i+97);
        back(freq, i+1, N, temp);
      }
    }
  }
}

int main(){
  string s;
  int r;
  while(cin >> s >> r){
    vi freq(26);
    for(int i = 0; i < s.size(); ++i)
      ++freq[(int)s[i]-97];
    back(freq, 0, r, "");
  }
  return 0;
}