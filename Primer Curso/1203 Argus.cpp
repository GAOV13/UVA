#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
	priority_queue<vector<int> > listado;
	string x;
	cin >> x;
	while(x == "Register"){
		vector<int> temp(3);
		int name, m;
		cin >> name >> m;
		temp[0] = m * -1;
		temp[2] = m * -1;
		temp[1] = name * -1;
		listado.push(temp); 
		cin >> x;
	}
	
	int n;
	cin >> n;
	while(n--){
		vector<int> temp = listado.top();
		listado.pop();
		temp[0] += temp[2];
		cout << temp[1] * -1 << endl;
		listado.push(temp);
	}
	return 0;
}

