#include <iostream>
#include <stack>
#include <vector>
#include <cstdio>

using namespace std;

int main(){
	string str;
	cin >> str;
	int i, j, casos = 1, num;
	while(str != "end"){
		vector<stack<char> > info;
		stack<char> temp;
		temp.push(str[0]);
		info.push_back(temp);
		for(i = 1; i < str.size(); i++){
			
			bool ver = false;
			for(j = 0; j < info.size(); j++){
				if((int)str[i] <= (int)info[j].top()){
					ver = true;
					break;
				}
			}
			
			if(ver){
				info[j].push(str[i]);
			}
			
			else{
				stack<char> temp1;
				temp1.push(str[i]);
				info.push_back(temp1);
			}
		}
		num = info.size();
		printf("Case %d: %d\n", casos++, num);
		cin >> str;
	}

	return 0;
}
