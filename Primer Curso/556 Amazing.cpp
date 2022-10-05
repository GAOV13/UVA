#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main(){  
	int n, m;
	int i, j;
	cin >> n >> m;
	while(n && m){
		vector<string> maze;
		vector<vector<int> > listado;
		for(i = 0; i < n; i++){
			vector<int> temp(m, 0);
			string x; 
			cin >> x;
			maze.push_back(x);
			listado.push_back(temp);
		}
		
		bool ver = true;
		bool ver1 = false;
		i = listado.size() - 1;
		j = 0;
		int dir = 1;
		while(ver){
			if(ver1 && j == 0 && i == listado.size() - 1) ver = false;
			
			else{
				ver1 = true;
				if(dir == 1){
					if(i + 1 < listado.size() && maze[i + 1][j] == '0'){
						dir = 4;
						listado[i + 1][j]++;
						i++;
					}
		
					else if(j + 1 < listado[i].size() && maze[i][j + 1] == '0'){
						listado[i][j + 1]++;
						j++;
					}
							
					else if(i - 1 >= 0 && maze[i - 1][j] == '0'){
						dir = 2;
						listado[i - 1][j]++;
						i--;
					}
					
					else if(j - 1 >= 0 && maze[i][j - 1] == '0'){
						dir = 3;
						listado[i][j - 1]++;
						j--;
					}
				}
					
				else if(dir == 2){
					if(j + 1 < listado[i].size() && maze[i][j + 1] == '0'){
						dir = 1;
						listado[i][j + 1]++;
						j++;
					}
					
					else if(i - 1 >= 0 && maze[i - 1][j] == '0'){
						listado[i - 1][j]++;
						i--;
					}
					
					else if(j - 1 >= 0 && maze[i][j - 1] == '0'){
						dir = 3;
						listado[i][j - 1]++;
						j--;
					}
					
					else if(i + 1 < listado.size() && maze[i + 1][j] == '0'){
						dir = 4;
						listado[i + 1][j]++;
						i++;
					}
				}
				
				else if(dir == 3){	
					if(i - 1 >= 0 && maze[i - 1][j] == '0'){
						dir = 2;
						listado[i - 1][j]++;
						i--;
					}
					
					else if(j - 1 >= 0 && maze[i][j - 1] == '0'){
						listado[i][j - 1]++;
						j--;
					}
					
					else if(i + 1 < listado.size() && maze[i + 1][j] == '0'){
						dir = 4;
						listado[i + 1][j]++;
						i++;
					}
		
					else if(j + 1 < listado[i].size() && maze[i][j + 1] == '0'){
						dir = 1;
						listado[i][j + 1]++;
						j++;
					}
				}
				
				else if(dir == 4){
					if(j - 1 >= 0 && maze[i][j - 1] == '0'){
						dir = 3;
						listado[i][j - 1]++;
						j--;
					}
					
					else if(i + 1 < listado.size() && maze[i + 1][j] == '0'){
						listado[i + 1][j]++;
						i++;
					}
		
					else if(j + 1 < listado[i].size() && maze[i][j + 1] == '0'){
						dir = 1;
						listado[i][j + 1]++;
						j++;
					}
							
					else if(i - 1 >= 0 && maze[i - 1][j] == '0'){
						dir = 2;
						listado[i - 1][j]++;
						i--;
					}
					

				}
			}
		}
		vector<int> devolver(5, 0);
		for(i = 0; i < n; i++){
			for(j = 0; j < m; j++){
				if(listado[i][j] < 5 && maze[i][j] == '0') devolver[listado[i][j]]++;
			}
		}
		
		for(i = 0; i < 5; i++){
			int num = devolver[i];
			printf("%3d", num);
		}
		cout << endl;
		cin >> n >> m;
	}
	return 0;
}

