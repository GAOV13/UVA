#include <iostream>

#define vi vector<int>
#define ss set<string>
#define vs vector<string>

using namespace std;

int main(){
	int n; 
	cin >> n;
	for(int i = 0; i < n; i++){
		int cant, res = 0;
		cin >> cant;
		while(cant){
			if(cant < 10){
				res += cant;
				cant = 0;
			}
			
			else if(cant < 1000000000 && cant >= 100000000){
				res += 100000000;
				cant -= 90000000;
			}
			
			else if(cant < 100000000 && cant >= 10000000){
				res += 10000000;
				cant -= 9000000;
			}	
			
			else if(cant < 10000000 && cant >= 1000000){
				res += 1000000;
				cant -= 900000;
			}
			
			else if(cant < 1000000 && cant >= 100000){
				res += 100000;
				cant -= 90000;
			}
			
			else if(cant < 100000 && cant >= 10000){
				res += 10000;
				cant -= 9000;
			}
			
			else if(cant < 10000 && cant >= 1000){
				res += 1000;
				cant -= 900;
			}
			
			else if(cant < 1000 && cant >= 100){
				res += 100;
				cant -= 90;
			}
			
			else if(cant < 100 && cant >= 10){
				res += 10;
				cant -= 9;
			}
			
			else{
				res += 1000000000;
				cant -= 900000000;
			}
		}
		cout << res << "\n";
	}
}

