#include <iostream>
#include <cmath>

#define endl "\n"
#define vi vector<int>

using namespace std;

/*Este algoritmo mejora por 0.02 segundos la respuesta de ants,
  en comparación con la respuesta que usa vectores, ordenamienots,
  y busqueda binaria.*/
int main(){
	int n;
	cin >> n;
	while(n--){
		int larg, cant;
		int min, max, temp;
		int prim, ult;
		float mitad;
		cin >> larg >> cant;
		mitad = ceil((float)larg/2.0);
		temp = min = 1000001;
		prim = 1000001;
		ult = -1;
		for(int i = 0; i < cant; i++){
			int k;
			cin >> k;
			ult = ult <= k ? k : ult;
			prim = prim >= k ? k : prim;
			if(min >= abs(mitad - k)){
				if(min == abs(mitad - k)){
					if(k > mitad && temp < mitad)
						temp = larg - k > temp ? k : temp;
						
					else if(k < mitad && temp > mitad)
						temp = k > larg - temp ? k : temp; 
				}
				
				else{
					min = abs(mitad - k);
					temp = k;
				}
			} 
		}	
		
		max = ult > larg - prim ? ult : larg - prim;
		min = temp >= mitad ? larg - temp : temp;
		cout << min << " " << max << endl;
	}
	return 0;
}

