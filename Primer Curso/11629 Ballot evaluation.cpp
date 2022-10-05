#include <iostream>
#include <map>
#include <cstdio>
#include <cmath>

using namespace std;

double round(double n){
	n *= 10.0;
	n += 0.5;
	int x;
	x = (int)floor(n);
	return (double)x/10.0;
}

int main(){
	map<string, double> listado;
	int n, m, casos = 1;
	cin >> n >> m;
	while(n--){
		string llave;
		double number;
		cin >> llave >> number;
		listado[llave] = number;
	}
	
	while(m--){
		bool ver = true;
		double resp = 0;
		string temp;
		while(ver){
			cin >> temp;
			if(temp == "<" || temp == ">" || temp == "<=" || temp == ">=" || temp == "=") ver = false;
			
			else if(temp != "+") resp += listado[temp];	
		}
		cin >> n;
		resp = round(resp);
		if(temp == "<"){
			if(resp < n) ver = true;
		}
		
		else if(temp == ">"){
			if(resp > n) ver = true;
		}
		
		else if(temp == "<="){
			if(resp <= n) ver = true;
		}
		
		else if(temp == ">="){
			if(resp >= n) ver = true;
		}
		
		else if(temp == "="){
			if(resp == n) ver = true;
		}
		
		if(ver) printf("Guess #%d was correct.\n", casos++);
		
		else printf("Guess #%d was incorrect.\n", casos++);
	}
	return 0;
}

