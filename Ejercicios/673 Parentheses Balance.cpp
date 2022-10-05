#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

int main(){	
	string dato, temp;
	int n, i;
	getline(cin,  dato);
	stringstream temp1(dato);
	temp1 >> n;
	bool ver;
	while(n--){
		stack<string> parentesis;
		ver = true;
		getline(cin,  dato);
		for(i = 0; i < dato.size() && ver; i++){
			temp = "";
			if(dato[i] == '[' || dato[i] == '('){
				temp += dato[i];
				parentesis.push(temp);
			}
			
			else if(dato[i] == ']'|| dato[i] == ')'){
				if(parentesis.empty()) ver = false;
				
				else{
					if(parentesis.top() == "[" && dato[i] == ']') parentesis.pop();
				
					else if(parentesis.top() == "(" && dato[i] == ')') parentesis.pop();	
					
					else ver = false;			
				}
			}
		}
		
		if(parentesis.empty() && ver) cout << "Yes" << endl;
		
		else cout << "No" << endl;
	}
	return 0;
}

