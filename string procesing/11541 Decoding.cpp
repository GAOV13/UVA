#include <iostream>
#include <sstream>

#define endl '\n'

using namespace std;

int stringANumero(string str){
    stringstream stream(str);
    int n;
    stream >> n;
    return n;
}

int main(){
    int n;
    int nume = 0;
    cin >> n;
    while(n--){
        string temp, dev = "", num = "0";
        char x = ' ';
        cin >> temp;
        for(int i = 0; i <= temp.size(); i++){
            if(i != temp.size() && temp[i] >= 48 && temp[i] <= 57)
                num += temp[i];
            
            else{
                char y = temp[i];
                int m = stringANumero(num);
                num = "";
                for(int j = 0; j < m; j++)
                    dev += x;
                
                if(i != temp.size()) x = y;
            }
        }
        cout << "Case " << ++nume << ": " << dev << endl;
    }
    return 0;
}
