#include <iostream>

using namespace std;

int main(){	
	string dato,
	int i;
	while(getline(cin, dato)){
		temp = dato;
		sort(temp.begin(), temp.end());
		next_permutation(dato.begin(), dato.end());
		if(dato == temp) cout << "No Successor" << endl;
		
		else cout << dato << endl;
		
		cin >> dato;
	}
	return 0;
}

