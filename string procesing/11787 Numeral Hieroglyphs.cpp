#include <iostream>
#include <algorithm>

#define endl '\n'

using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        string temp;
        cin >> temp;
        char x = temp[0];
        char y = temp[temp.size() - 1];
        if(x == 'B' && (y == 'U' || y == 'S' || y == 'P' || y == 'F' || y == 'T' || y == 'M')) reverse(temp.begin(), temp.end());

        else if(x == 'U' && (y == 'S' || y == 'P' || y == 'F' || y == 'T' || y == 'M')) reverse(temp.begin(), temp.end());

        else if(x == 'S' && (y == 'P' || y == 'F' || y == 'T' || y == 'M')) reverse(temp.begin(), temp.end());

        else if(x == 'P' && (y == 'F' || y == 'T' || y == 'M')) reverse(temp.begin(), temp.end());
        
        else if(x == 'F' && (y == 'T' || y == 'M')) reverse(temp.begin(), temp.end());

        else if(x == 'T' && y == 'M') reverse(temp.begin(), temp.end());

        x = temp[0];
        int num = 1;
        int i = 1;
        int lim = temp.size();
        string dev = "";

        while(i <= lim){
            if(x == 'M'){
                if(temp[i] == x){
                    ++num;
                    if(num >= 10) break;

                    i++;
                }

                else if(temp[i] == 'T' || temp[i] == 'F' || temp[i] == 'P' || temp[i] == 'S' || temp[i] == 'U' || temp[i] == 'B' || i == lim){
                    x = 'T';
                    num += 48;
                    dev += (char)num;
                    num = 0;
                }

                else break;
            }

            else if(x == 'T'){
                if(temp[i] == x){
                    ++num;
                    if(num >= 10) break;

                    i++;
                }

                else if(temp[i] == 'F' || temp[i] == 'P' || temp[i] == 'S' || temp[i] == 'U' || temp[i] == 'B' || i == lim){
                    x = 'F';
                    num += 48;
                    dev += (char)num;
                    num = 0;
                }

                else break;
            }

            else if(x == 'F'){
                if(temp[i] == x){
                    ++num;
                    if(num >= 10) break;

                    i++;
                }

                else if(temp[i] == 'P' || temp[i] == 'S' || temp[i] == 'U' || temp[i] == 'B' || i == lim){
                    x = 'P';
                    num += 48;
                    dev += (char)num;
                    num = 0;
                }

                else break;
            }

            else if(x == 'P'){
                if(temp[i] == x){
                    ++num;
                    if(num >= 10) break;

                    i++;
                }

                else if(temp[i] == 'S' || temp[i] == 'U' || temp[i] == 'B' || i == lim){
                    x = 'S';
                    num += 48;
                    dev += (char)num;
                    num = 0;
                }

                else break;
            }

            else if(x == 'S'){
                if(temp[i] == x){
                    ++num;
                    if(num >= 10) break;

                    i++;
                }

                else if(temp[i] == 'U' || temp[i] == 'B' || i == lim){
                    x = 'U';
                    num += 48;
                    dev += (char)num;
                    num = 0;
                }

                else break;
            }

            else if(x == 'U'){
                if(temp[i] == x){
                    ++num;
                    if(num >= 10) break;

                    i++;
                }

                else if(temp[i] == 'B' || i == lim){
                    x = 'B';
                    num += 48;
                    dev += (char)num;
                    num = 0;
                }

                else break;
            }

            else if(x == 'B'){
                if(temp[i] == x){
                    ++num;
                    if(num >= 10) break;

                    i++;
                }

                else if(i == lim){
                    num += 48;
                    dev += (char)num;
                    ++i;
                }
                
                else break;
            }
        }

        if(i == lim + 1) cout << dev << endl;
        
        else cout << "error" << endl;
    }
    return 0;
}
