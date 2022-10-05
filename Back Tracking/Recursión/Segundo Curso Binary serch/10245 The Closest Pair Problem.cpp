#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cmath>

#define pdd pair<double, double>

using namespace std;

int main(){
	int n;
	cin >> n;
	while(n){
		vector<pdd> lista;
		for(int i = 0; i < n; i++){
			double x, y;
			cin >> x >> y;
			pdd pareja = make_pair(x, y);
			lista.push_back(pareja);
		}
		
		double min = 10000;
		for(int i = 0; i < lista.size() - 1; i++){
			for(int j = i + 1; j < lista.size(); j++){
				pdd temp;
				temp.first = lista[i].first - lista[j].first;
				temp.second = lista[i].second - lista[j].second;
				temp.first = temp.first * temp.first;
				temp.second = temp.second * temp.second;
				double sera = temp.first + temp.second;
				sera = sqrt(sera);
				min = sera < min ? sera : min;
			}	
		}
		if(min == 10000) cout << "INFINITY" << endl;
		
		else printf("%.4f\n", min);
		cin >> n;
	}
	return 0;
}
