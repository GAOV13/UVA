#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int anos, num, k;
	int min, max, dev, temp;
	int cuanto, cuanto1, sera;
	while(cin >> anos){
		vector<int> lista;
		cin >> num;
		max = temp = 1;
		cin >> k;
		lista.push_back(k);
		for(int i = 1; i < num; i++){
			cin >> k;
			lista.push_back(k);
		}
		
		cin.ignore();
		vector<int>::iterator itrb, itre, temp1 = lista.begin();
		temp = (*temp1);
		bool ver = true;
		cuanto = cuanto1 = 0;
		dev = 0;
		while(ver){
			itre = upper_bound(temp1, lista.end(), temp + anos - 1);
			cuanto = itre - temp1;
			sera = (*(itre - 1)) - (*temp1);
			
			if(itre == lista.end()) cuanto1++;
			
			if(dev < cuanto && sera < anos){
				dev = cuanto;
				min = (*temp1);
				max = (*(itre - 1));
			}
			
			temp1++;
			while((*temp1) == temp) temp1++;
			
			temp = (*temp1);
			if(cuanto1 == 1) ver = false; 
		}	
		printf("%d %d %d\n", dev, min, max);	
	}
	return 0;
}

