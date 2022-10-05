#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;
int m;

bool compare(long long itr1, long long int itr2){
	if(itr2 % m > itr1 % m) return true;
	
	else if(itr2 % m == itr1 % m){
		long long int n1, n2;
		n2 = (itr2) % 2;
		n1 = (itr1) % 2;
		if(n2 < n1) return true;
		
		else if(n2 == n1 && n2 == 1){
			if(itr2 < itr1) return true;
		}
		
		else if(n2 == n1 && n2 == 0){
			if(itr2 > itr1) return true;
			
			else return false;
		}
	}
	return false;
}

int main(){
	int n;
	long long int num, mod;
	cin >> n >> m;
	while(n && m){
		vector<long long int> listado;
		for(int i = 0; i < n; i++){
			cin >> num;
			listado.push_back(num);
		}
		sort(listado.begin(), listado.end(), compare);
		vector<long long int>::iterator itr;
		cout << n << " " << m << endl;
		for(itr = listado.begin(); itr != listado.end(); itr++){
			cout << *itr << endl;
		}
		cin >> n >> m;	
	}
	
	cout << n << " " << m << endl;
	return 0;
}
