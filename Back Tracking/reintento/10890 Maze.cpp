#include <bits/stdc++.h>

#define vpi vector<pair<int, int> >
#define pi pair<int, int>
#define vi vector<int>
#define endl '\n'

using namespace std;

int ans;

bool nohay(pi u, pi v, vpi &tresure, vi &visitado){
  int ini1=min(u.first,v.first), ini2=min(u.second,v.second);
  int fin1=max(u.first,v.first), fin2=max(u.second,v.second);
  for(int i = 0; i < visitado.size(); ++i){
    if(tresure[i] == u || tresure[i] == v)
      continue; 
    else if(!visitado[i]){
      if(tresure[i].first>=ini1 && tresure[i].first<=fin1 && tresure[i].second>=ini2 && tresure[i].second<=fin2){
        return false;
      }
    }
  }
  return true;
}

void back(int pos, int n, int S, int N, int acum, vpi &tresure, vi &visitado){
  if(acum+(N-1)-tresure[pos].first+(N-1)-tresure[pos].second < ans){
    if(S == n) ans = min(ans, acum+(N-1)-tresure[pos].first+(N-1)-tresure[pos].second);
    else{
      for(int i = 0; i < visitado.size(); ++i){
        if(!visitado[i]){
          if(pos == -1 && nohay(make_pair(0,0), tresure[i], tresure, visitado)){
            visitado[i] = 1;
            back(i, n+1, S, N, acum+tresure[i].first+tresure[i].second, tresure, visitado);
            visitado[i] = 0;
          }
          else if(pos != -1 && nohay(tresure[pos], tresure[i], tresure, visitado)){
            visitado[i] = 1;
            back(i, n+1, S, N, acum+abs(tresure[pos].first-(tresure[i].first))+abs(tresure[pos].second-tresure[i].second), tresure, visitado);
            visitado[i] = 0;
          }
        }
      }
    }
  }
}

int main(){
  int N, T, S, cases = 0;
  while(cin >> N >> T >> S, N+T+S){
    vpi tresure(T);
    vi visitado(T, 0);
    ans = 1000000000;
    bool flag = false;
    for(int i = 0; i < T; ++i){
      cin >> tresure[i].first >> tresure[i].second;
      if(tresure[i].first == 0 && tresure[i].second == 0)
        flag = true;
    }

    if(flag)
      back(-1, 1, S, N, 0, tresure, visitado);
    else
      back(-1, 0, S, N, 0, tresure, visitado);
    cout << "Case " << ++cases << ": " << ans << endl;
  }
  return 0;
}