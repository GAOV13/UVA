#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <sstream>
#include <string>

#define vi vector<int>
#define ss set<string>
#define vs vector<string>

using namespace std;

ss devolver;

void se_puede(vi lista, int indice, int &n, int acum, string temp){
	if(n == acum){
		devolver.insert(temp);
		return;
	};
	
	if(indice == lista.size() || acum > n) return;
	
	se_puede(lista, indice + 1, n, acum, temp);
	
	ostringstream r;
	r << lista[indice];
	string str1 = r.str();
	str1 += "+";
	temp += str1;
	se_puede(lista, indice + 1, n, acum + lista[indice], temp);
}


int main(){
	int n, t;
	cin >> t >> n;
	while(n){
		vi lista;
		devolver.clear();
		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			lista.push_back(x);
		}
		
		se_puede(lista, 0, t, 0, "");
		cout << "Sums of " << t << ":" << endl;
		if(devolver.empty()) cout << "NONE\n";
		
		else{
			vs impri(devolver.begin(), devolver.end());
			for(int i = impri.size() - 1; i >= 0; i--){
				string imp = impri[i];
				imp.pop_back();
				cout << imp << "\n";
			}
		}
		cin >> t >> n;
	}
	return 0;
}

