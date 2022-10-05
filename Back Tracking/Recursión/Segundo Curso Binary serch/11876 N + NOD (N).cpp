#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

#define vi vector<int>
#define endl '\n'

using namespace std;

int nod(int n){
	int suma = 0;
	for (int i = 1; i <= n / i; i++) {
		if(n % i == 0){
			if(n/i == i) suma++;
			
			else suma += 2;
		}
	}
	return suma;
}

int main(){
	int n, min, max, k, casos = 0;
	vi lista;
	vi::iterator itrf, itre;
	lista.push_back(1);
	cin >> n;
	while(n--){
		cin >> min >> max;
		while(lista[lista.size() - 1] <= 1000000 && lista[lista.size() - 1] <= max){
			k = nod(lista[lista.size() - 1]);
			k += lista[lista.size() - 1];
			lista.push_back(k);
		}

		itrf = lower_bound(lista.begin(), lista.end(), min);
		itre = upper_bound(itrf, lista.end(), max);
		k = itre - itrf;
		cout << "Case " << ++casos << ": " << k << endl;
	}
	return 0;
}
