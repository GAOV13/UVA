#include <iostream>
#include <queue>
#include <iterator>

typedef long long int lli;

using namespace std;

deque<lli>::iterator esta(deque<lli> &temp, lli num){
	deque<lli>::iterator itr;
	for(itr = temp.begin(); itr != temp.end(); itr++){
		if((*itr) == num) break;
	}
	
	return itr;
}

int main(){  
	lli n;
	int m, casos = 1;	
	cin >> n >> m;
	while(n && m){
		deque<lli> lista;
		for(int i = 1; i <= n && i <= 1000; i++) lista.push_back(i);
		
		cout << "Case " << casos++ << ":" << endl;
		while(m--){
			string x;
			cin >> x;
			if(x == "N"){
				cout << lista.front() << endl;
				lista.push_back(lista.front());
				lista.pop_front();
			}
			
			else if(x == "E"){
				lli k;
				cin >> k;
				deque<lli>::iterator itr = esta(lista, k);
				lista.erase(itr);
				lista.push_front(k);
			}
		}
		cin >> n >> m;
	}
	return 0;
}

