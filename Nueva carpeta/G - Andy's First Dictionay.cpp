#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <stdio.h>
#include <map>

#define vi vector<int>
#define ss set<string>
#define vs vector<string>

using namespace std;

int main(){
	map<string, bool> listado;
	string temp;
	char x;
	while(scanf("%c", &x) != EOF){
		if((int)x >= 97 && (int)x <= 122) temp += x;
		
		else if((int)x >= 65  && (int)x <= 90){
			x = x + 32;
			temp += x;
		}
		
		else{
			if(temp.size() != 0){
				listado[temp] = true;
				temp.clear();
			}
		}
	}
	map<string, bool>::iterator itr;
	for(itr = listado.begin(); itr != listado.end(); itr++){
		cout << itr->first << "\n";
	}
}

