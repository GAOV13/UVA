#include <iostream>
#include <vector>

#define endl '\n'
#define vb vector<bool>

using namespace std;

int main(){
	int n, m;
	while (cin >> n >> m, n || m){
		bool ver = false;	
		int ini, fin, rep;
		vb horario(1000000, false);
		for (int i = 0; i < n; ++i) {
			cin >> ini >> fin;
			if (!ver){
				for (int j = ini; j < fin && !ver; j++) {
					if (horario[j]) ver = true;
					
					horario[j] = true;
				}
			}
		}

		for (int i = 0; i < m; i++) {
			cin >> ini >> fin >> rep;
			if (!ver) {
				bool ver1 = true;
				while(ver1) {
					for (int j = ini; j < fin && !ver; j++) {
						if (horario[j]){
							ver = true;
							ver1 = false;
						}
						
						horario[j] = true;
					}

					ini += rep;
					fin += rep;
					if (ini > 1000000 && fin > 1000000) ver1 = false;
						
					else if (fin > 1000000) fin = 1000000;
				}
			}
		}

		if(ver) cout << "CONFLICT" << endl;

		else cout << "NO CONFLICT" << endl;
	}
	return 0;
}
