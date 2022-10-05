#include <iostream>
#include <map>
#include <iterator>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(pair<string, int> i1, pair<string, int> i2){
	if(i1.second == i2.second) return i1.first < i2.first;
	
	else return i1.second > i2.second;
}

int main(){
	string dato, temp; 
	map<string, string> listado;
	vector<string> grupos;
	getline(cin, dato);
	while(dato != "0"){
		if(dato != "1"){
			if((int)dato[0] >= 65 && (int)dato[0] <= 90){
				temp = dato;
				grupos.push_back(temp);
			}
			
			else if((int)dato[0] >= 97 && (int)dato[0] <= 122){
				if(listado[dato] == "") listado[dato] = temp; 
				
				if(listado[dato] != temp) listado[dato] += "0";
			}
		} 
				
		else{
			map<string, int> list;
			map<string, string>::iterator itr;
			map<string, int>::iterator itr1;
			vector<pair<string, int> > ordenar;
			for(int i = 0; i < grupos.size(); i++)	list[grupos[i]] = 0;

			for(itr = listado.begin(); itr != listado.end(); itr++){
				if(itr->second[(itr->second).size() - 1] != '0') list[itr->second]++;
			} 
			
			for(itr1 = list.begin(); itr1 != list.end(); itr1++){
				pair<string, int> pareja = make_pair(itr1->first, itr1->second);
				ordenar.push_back(pareja);
			}
			
			sort(ordenar.begin(), ordenar.end(), compare);
			for(int i = 0; i < ordenar.size(); i++){
				cout << ordenar[i].first << " " << ordenar[i].second << endl;
			}
			listado.clear();
			grupos.clear();
		}
		
		getline(cin, dato);
	}
	
	return 0;
}

