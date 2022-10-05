#include <iostream>
#include <cmath>

using namespace std;

long long H(int n){
	long long res = 0;
	for(int i = 1; i <= n/i; i++ ){
		if(i == n/i) res += n/i;
		
		else{
			res += n/i;
			res += i;
		}
	}
	return res;
}

int main(){
	int n;
	cin >> n;
	while(n--){
		long long int m, res;
		cin >> m;
		cout << H(m) << endl;
	}
	
	return 0;
}
