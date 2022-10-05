#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdio>

using namespace std;

int main(){
	int n;
	vector<int> lista;
	while(cin >> n){
		while(n--){
			int k;
			cin >> k;
			lista.push_back(k);
		}
		sort(lista.begin(), lista.end());
		vector<int>::iterator itrp, itre;
		int res;
		cin >> res;
		cin.ignore();
		itrp = lower_bound(lista.begin(), lista.end(), res/2);
		bool ver = true;
		if((*itrp) == res/2) itre = itrp + 1;
		
		else{
			itre = itrp--;	
		} 
		
		while(ver){
			if((*itrp) + (*itre) == res) ver = false;
				
			else{
				if((*itrp) + (*itre) > res) itrp--;
				
				else if((*itrp) + (*itre) < res) itre++;
			}
		}
		int i, j;
		i = (*itrp);
		j = (*itre);
		printf("Peter should buy books whose prices are %d and %d.\n\n", i, j);
		lista.clear();
	}
}
