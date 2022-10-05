#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main(){
	int n, fil, col;
	int i, j, k;
	int min, max;
	int tam, tam_max;
	bool ver;
	vector<int>::iterator itr;
	cin >> fil >> col;
	while(fil && col){
		vector<vector<int> > lista;
		for(i = 0; i < fil; i++){
			vector<int> temp;
			for(j = 0; j < col; j++){
				cin >> k; 
				temp.push_back(k);
			}
			lista.push_back(temp);
		}
		cin >> n;
		while(n--){
			cin >> min >> max;
			ver = true;
			i = 0;
			tam_max = 0;
			while(ver){
				tam = 0;
				if(i == fil || lista[i][0] > max){
					ver = false;
				} 
				
				else{
					itr = lower_bound(lista[i].begin(), lista[i].end(), min);
					if((*itr) <= max && (*itr) >= min && itr != lista[i].end()){
						j = itr - lista[i].begin();
						bool ver1 = true;
						tam = 1;
						int i1 = i;
						while(ver1){
							ver1 = false;
							if(i1 + 1 < fil && j + 1 < col){
								if(lista[i1 + 1][j + 1] <= max){
									tam++; i1++; j++;
									ver1 = true;
								}	
							}				
						}
						tam_max = tam > tam_max ? tam : tam_max;
					}
					i++;
				}
			}
			cout << tam_max << endl;
		}
		cout << "-" << endl;
		cin >> fil >> col;
	}
	return 0;
}
