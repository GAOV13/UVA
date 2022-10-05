#include <iostream>
#include <queue>

typedef long long int lli;

using namespace std;

int main(){
	int n;
	cin >> n;
	while(n){
		priority_queue<lli> listado;
		for(int i = 0; i < n; i++){
			lli m;
			cin >> m;
			listado.push(m * -1);
		}
		
		lli resp = 0;
		bool ver = true;
		while(ver){
			lli a = listado.top(); listado.pop();
			lli b = listado.top(); listado.pop();
			lli gasto = a + b;
			resp += gasto;
			if(listado.empty()) ver = false;
			
			else listado.push(gasto);
		}
		cout << resp * -1 << endl;
		cin >> n;
	}
}

