#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

void back(int *N, int acum, int itera, bool &ans){
  if(!ans){
    if(itera == 5 && acum == 23) ans = true;
    else if(itera != 5){
      for(int i = 0; i < 5 && !ans; ++i){
        if(N[i]){
          int hacer = N[i];
          N[i] = 0;
          back(N, acum+hacer, itera+1, ans);
          back(N, acum-hacer, itera+1, ans);
          back(N, acum*hacer, itera+1, ans);
          N[i] = hacer;
        }
      }
    }
  }
}
void general(int *N, bool &ans){
  if(!ans){
    for(int i = 0; i < 5 && !ans; ++i){
      int hacer = N[i];
      N[i] = 0;
      back(N, hacer, 1, ans);
      N[i] = hacer;
    }
  }
}

int main(){
  int N[5];
  while(cin >> N[0] >> N[1] >> N[2] >> N[3] >> N[4], N[0]+N[1]+N[2]+N[3]+N[4]){
    bool ans = false;
    general(N, ans);
    if(ans) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
  }
  return 0;
}