#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

typedef long long int lli;
using namespace std;

int main(){
	int n;
	vector<lli> lista;
	cin >> n;
	for(int i = 0; i < n; i++){
		lli k;
		cin >> k;
		lista.push_back(k);
	}
	
	cin >> n;
	while(n--){
		lli tam;
		cin >> tam;
		vector<lli>::iterator itr;
		itr = lower_bound(lista.begin(), lista.end(), tam);
		itr--;
		if(itr == lista.begin() - 1) cout << "X ";
		
		else cout << (*itr) << " ";
		
		itr = upper_bound(lista.begin(), lista.end(), tam);
		if(itr == lista.end()) cout << "X";
		
		else cout << (*itr);
		
		cout << endl;
	}
	return 0;
}
