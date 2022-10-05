#include <iostream>

using namespace std;

int main(){	
	string original, secuencia;
	int i, j;
	while(cin >> secuencia >> original){
		j = 0;
		for(i = 0; i < original.size() && j < secuencia.size(); i++){
			if(secuencia[j] == original[i]) j++;
		}
		
		if(j == secuencia.size()) cout << "Yes" << endl;
		
		else cout << "No" << endl;
	}
	return 0;
}
