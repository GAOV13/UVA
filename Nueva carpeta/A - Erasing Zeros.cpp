#include <iostream>
#include <string>

using namespace std;

int main(){
	int n;
	cin >> n;
	while(n--){
		string x;	
		cin >> x;
		bool ver = false;
		int uno = 0;
		int zero = 0;
		int res = 0;
		for(int i = 0; i < x.size(); i++){
			if(x[i] == '1') uno = 1;
			
			if(uno){
				ver = true;
				res += zero;
				uno = 0;
				zero = 0;
			}
			
			else if(ver) zero++;
		
		}
		cout << res << "\n";
	}
}

