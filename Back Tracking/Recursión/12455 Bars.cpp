#include <iostream>
#include <vector>

using namespace std;

bool se_puede(vector<int> lista, int indice, int n, int acum){
	if(n == acum) return true;
	
	if(indice == lista.size() || acum > n) return false;
	 
	return se_puede(lista, indice + 1, n, acum) || se_puede(lista, indice + 1, n, acum + lista[indice]);
}


int main(){
	int n;
	cin >> n;
	while(n--){
		vector<int> lista;
		int num, m;
		cin >> num >> m;
		for(int i = 0; i < m; i++){
			int x; 
			cin >> x;
			lista.push_back(x);
		}
		bool ver = se_puede(lista, 0, num, 0);
		
		if(ver) cout << "YES" << endl;
		
		else cout << "NO" << endl;
	}
	return 0;
}

