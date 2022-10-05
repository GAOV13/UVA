#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <stdio.h>
#include <algorithm>

#define endl "\n"
#define vi vector<int>
#define mcvi map<char, vector<int> >

using namespace std;

int main(){
	mcvi listado;
	char x;
	int i = 0;
	scanf("%c", &x);
	while(x != '\n'){
		listado[x].push_back(i);
		i++;
		scanf("%c", &x);
	}
	
	int n; 
	int min, max;
	cin >> n;
	while(n--){
		int ver = 0;
		string temp;
		cin >> temp;
		for(i = 0; i < temp.size(); i++){
			vi::iterator itr = lower_bound(listado[temp[i]].begin(), listado[temp[i]].end(), ver);
			if(itr == listado[temp[i]].end()) break;
			
			else{
				ver = *(itr);
				if(i == 0) min = ver;
				
				if(i == temp.size() - 1) max = ver;
				ver++;
			}
		}
		
		if(i == temp.size()) printf("Matched %d %d\n", min, max);
		
		else cout << "Not matched" << endl;
	}
	return 0;
}

