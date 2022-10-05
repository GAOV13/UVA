#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Dato{
	public:
		int base;
		int size_bits;
		int dimension;
		vector<pair<int, int> > info;	
		
		Dato(int b, int sb, int d, vector<pair<int, int> > i){
			base = b;
			size_bits = sb;
			dimension = d;
			info = i;
		}	
};

int main(){
	int n, m;
	string name;
	map<string, vector<Dato> > inform;
	cin >> n >> m;
	while(n--){
		cin >> name;
		int b, sb, d;
		cin >> b >> sb >> d;
		vector<pair<int, int> > temp;
		for(int i = 0; i < d; i++){
			int low, up;
			cin >> low >> up;
			pair<int, int> pareja = make_pair(low, up);
			temp.push_back(pareja);
		}
		Dato dato(b, sb, d, temp);
		inform[name].push_back(dato);
	}
	
	while(m--){
		cin >> name;
		int d = inform[name][0].dimension;
		vector<int> list;
		for(int i = 0; i < d; i++){
			int temp;
			cin >> temp;
			list.push_back(temp);
		}
		vector<int> c_info;
		c_info.push_back(inform[name][0].size_bits);
		for(int i = d - 1; i >= 0; i--){
			int temp;
			if(i == 0){
				int tam = c_info.size();
				temp = inform[name][0].base;
				for(int j = 0; j < tam; j++){
					temp -= c_info[tam - 1 - j]*inform[name][0].info[j].first;
				}
				c_info.push_back(temp);
			}
			else{
				temp = c_info[c_info.size() - 1]*(inform[name][0].info[i].second - inform[name][0].info[i].first + 1);
				c_info.push_back(temp);
				
			}
		}
		reverse(c_info.begin(), c_info.end());
		int respuesta = 0;
		for(int i = 0; i < c_info.size(); i++){
			if(i == 0) respuesta += c_info[i];
			
			else{
				respuesta += c_info[i] * list[i - 1];
			}
		}
		cout << name << "[" << list[0];
		for(int i = 1; i < list.size(); i++){
			cout << ", " << list[i];
		}
		cout << "] = " << respuesta << endl;
	}
	
	return 0;
}

