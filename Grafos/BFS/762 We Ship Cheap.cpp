#include <iostream>
#include <map>
#include <vector>
#include <queue>

#define vs vector<string>
#define msvs map<string, vector<string> >
#define msi map<string, int>
#define mss map<string, string>
#define qs queue<string>
#define endl "\n"

using namespace std;

int main(){
	int n;
	bool ver = false;
	while(cin >> n){
		if(ver) cout << endl;

		ver = true;
		msvs lista;
		msi visitado;
		string city_in, city_end;
		for(int i = 0; i < n; ++i){
			cin >> city_in >> city_end;
			lista[city_in].push_back(city_end);
			lista[city_end].push_back(city_in);
			visitado[city_end] = 0; visitado[city_in] = 0;
		}
		cin >> city_in >> city_end;
		visitado[city_end] = 0; visitado[city_in] = 0;
		cin.ignore();
		
		mss padre;
		qs cola;
		cola.push(city_in);
		while(!cola.empty()){
			string nodo = cola.front(); cola.pop();
			if(nodo == city_end) break;
			
			for(int i = 0; i < lista[nodo].size(); ++i){
				string aux = lista[nodo][i];
				if(visitado[aux] == 0){
					cola.push(aux);
					++visitado[aux];
					padre[aux] = nodo;
				}
			}
		}
		
		if(visitado[city_end] == 0) cout << "No route" << endl;
		
		else{
			string nodo = city_end;
			vs ruta;
			while(nodo != city_in){
				ruta.push_back(nodo);
				nodo = padre[nodo];
			}
			ruta.push_back(city_in);
			
			for(int i = ruta.size() - 1; i > 0; --i){
				cout << ruta[i] << " " << ruta[i - 1] << endl;
			}
		} 
	}
	return 0;
}

