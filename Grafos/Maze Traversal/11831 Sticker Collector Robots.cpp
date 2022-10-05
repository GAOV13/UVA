#include <bits/stdc++.h>

#define vs vector<string>
#define endl '\n'

using namespace std;

int main(){
    int row, colum, instruc;
    while(cin >> row >> colum >> instruc, row && colum && instruc){
        vs laberinto(row, "");
        int pos_x, pos_y;
        char direc;
        cin.ignore();
        for(int i = 0; i < row; ++i){
            string str = "";
            char x;
            for(int j = 0; j < colum; ++j){
                scanf("%c", &x);
                str += x;
                if(x != '*' && x != '#' && x != '.'){
                    pos_x = i;
                    pos_y = j;
                    direc = x;
                }
            }
            cin.ignore();
            laberinto[i] = str;
        }
        
        string info;
        cin >> info;
        int conteo = 0;
        for(int k = 0; k < info.size(); ++k){
            if(info[k] == 'D'){
                if(direc == 'N') direc = 'L';

                else if(direc == 'L') direc = 'S';

                else if(direc == 'S') direc = 'O';

                else direc = 'N';
            }

            else if(info[k] == 'E'){
                if(direc == 'N') direc = 'O';

                else if(direc == 'L') direc = 'N';

                else if(direc == 'S') direc = 'L';

                else direc = 'S';
            }

            else{
                if(direc == 'N'){
                    if(pos_x - 1 >= 0){
                        if(laberinto[pos_x - 1][pos_y] != '#'){
                            --pos_x;
                            if(laberinto[pos_x][pos_y] == '*'){
                                laberinto[pos_x][pos_y] = '.';
                                ++conteo;
                            }   
                        }
                    }
                }

                else if(direc == 'L'){
                    if(pos_y + 1 < colum){
                        if(laberinto[pos_x][pos_y + 1] != '#'){
                            ++pos_y;
                            if(laberinto[pos_x][pos_y] == '*'){
                                laberinto[pos_x][pos_y] = '.';
                                ++conteo;
                            }   
                        }
                    }
                }

                else if(direc == 'S'){
                    if(pos_x + 1 < row){
                        if(laberinto[pos_x + 1][pos_y] != '#'){
                            ++pos_x;
                            if(laberinto[pos_x][pos_y] == '*'){
                                laberinto[pos_x][pos_y] = '.';
                                ++conteo;
                            }   
                        }
                    }
                }

                else{
                    if(pos_y - 1 >= 0){
                        if(laberinto[pos_x][pos_y - 1] != '#'){
                            --pos_y;
                            if(laberinto[pos_x][pos_y] == '*'){
                                laberinto[pos_x][pos_y] = '.';
                                ++conteo;
                            }   
                        }
                    }
                }
            }
        }

        cout << conteo << endl;
    }
    return 0;
}