#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n, tam, casos = 1;
	cin >> n;
	while(n--){
		string x;
		int pointer = 0;
		cin >> x;
		tam = x.size();
		vector<int> info(100, 0);
		for(int i = 0; i < tam; i++){
			if(x[i] == '<'){
				if(pointer == 0) pointer = 99;
				
				else pointer--;
			}
			
			else if(x[i] == '>'){
				if(pointer == 99) pointer = 0;
				
				else pointer++;
			}
			
			else if(x[i] == '+'){
				if(info[pointer] + 1 == 256) info[pointer] = 0;
				
				else info[pointer]++;
			}
			
			else if(x[i] == '-'){
				if(info[pointer] - 1 < 0) info[pointer] = 255;
				
				else info[pointer]--;
			}
		}
		
		printf("Case %d: %02X", casos++, info[0]);
		for(int i = 1; i < 100; i++){
			printf(" %02X", info[i]);
		}
		printf("\n");
	}
	return 0;
}

