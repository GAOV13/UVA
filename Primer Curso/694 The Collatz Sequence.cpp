#include <iostream>
#include <cstdio>

typedef long long int lli;

using namespace std;

int main(){
	lli n, limit;
	cin >> n >> limit;
	int casos = 1;
	while(n > 0 && limit > 0){
		int a = n;
		int resp = 1;
		bool ver = true;
		while(ver){
			
			if(n == 1) ver = false;
			
			else if(n%2 == 0){
				n = n/2;
				resp++;
			}
			
			else if(n%2 != 0){
				if((n*3) + 1 > limit) ver = false;
				
				else{
					n = (n*3) + 1;
					if(n < 0) ver = false;
					
					else resp++;
				}
			}
		}
		printf("Case %d: A = %lli, limit = %lli, number of terms = %d\n", casos++, a, limit, resp);
		cin >> n >> limit;
	}
	return 0;	
}

