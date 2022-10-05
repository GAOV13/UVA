#include <iostream>

#define endl '\n'

using namespace std;

int main(){
  int n, dig;
  int m;
  while(cin >> n){
    dig = 1; m = 1%n;
    while(m){
      ++dig;
      m = (m*10 + 1)%n;
    }
    cout << dig << endl;
  }
}