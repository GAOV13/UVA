#include <iostream>
#include <vector>

#define vi vector<int>

using namespace std;

int main(){
	int n;
	cin >> n;
	while(n--){
		vi lista;
		int tam; 
		int camb = 0;
		cin >> tam;
		for(int i = 0; i < tam; i++){
			int x;
			cin >> x;
			if(x == 0){
				camb++;
				x++;
			}
			lista.push_back(x);
		}
		
		int suma = 0;
		for(int i = 0; i < tam; i++){
			suma += lista[i];
		}
		
		if(suma == 0) camb++;
		
		cout << camb << "\n";
	}	
}

