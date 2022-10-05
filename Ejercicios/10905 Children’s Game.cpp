/*
Nombre Archivo: ChildrensGame 10905
Version: 1.0
Fecha de Creacion: 25 de octubre del 2019
Fecha Ultima modificacion: 25 de Octubre del 2019
Autor: Guido Salazar
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

bool compare(string n1, string n2){
	int largo1 = n1.size(), largo2 = n2.size(), i, j = 0, ver = 0;
	
	if(n1 == n2){
		return false;
	}
	
	else if(largo1 > largo2){
		for(i = 0; ver < 5; i++, j++){
			if(j == largo2) j = 0;
			
			if(i == largo1){
				i = 0;
				ver++;	
			} 
			
			if(n1[i] > n2[j]){
				return true;
			}
			
			else if(n1[i] < n2[j]){
				return false;
			}
		}
	}
	
	else{
		for(i = 0; ver < 5; i++, j++){
			if(j == largo1) j = 0;
			
			if(i == largo2){
				i = 0;
				ver++;	
			} 
			
			if(n1[j] > n2[i]){
				return true;
			}
			
			else if(n1[j] < n2[i]){
				return false;
			}
		}
	}
	return false;
}

int main(){
	string temp, max;
	vector<string> palabra;
	int n, i;
	cin >> n;
	while(n){
		for(i = 0; i < n; i++){
			cin >> temp;
			palabra.push_back(temp);
		}

		sort(palabra.begin(), palabra.end(), compare);

		for(i = 0; i < palabra.size(); i++) cout << palabra[i]; 

		cout << endl;
		palabra.clear();
		
		cin >> n;
	}
	return 0;
}

