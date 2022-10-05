#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>

#define endl "\n"
#define vi vector<int>

using namespace std;

/*Este algoritmo usa busqueda binaria con el objetivo de hallar la hormiga que
  mas cerca a la mitad esta*/
int main(){
	int n;
	cin >> n;
	while(n--){
		int larg, cant;
		vi lista;
		cin >> larg >> cant;
		for(int i = 0; i < cant; i++){
			int k;
			cin >> k;
			lista.push_back(k);
		}	
		
		sort(lista.begin(), lista.end());
		
		int min, max;
		float mitad = ceil((float)larg/2.0);
		max = lista[cant - 1] > larg - lista[0] ? lista[cant - 1] : larg - lista[0];
		
		vi::iterator itr;
		itr = lower_bound(lista.begin(), lista.end(), mitad);
		
		if(itr == lista.end()) itr--;
		
		min = *(itr) >= mitad ? larg - *(itr) : *(itr);
		
		if(itr != lista.begin() && abs(mitad - *(itr)) >= abs(mitad - *(itr - 1)))
			min = *(itr - 1);
			
		cout << min << " " << max << endl;
	}
	return 0;
}

