#include <iostream>
#include <sstream>
#include <algorithm>

#define endl '\n'

using namespace std;

string numeroAstring(int n){
    ostringstream stream;
    stream << n;
    return stream.str();
}

int stringANumero(string str){
    stringstream stream(str);
    int n;
    stream >> n;
    return n;
}

int main(){
    string x;
    while(getline(cin, x)){
        string dev, temp;
        dev = "";

        if((int)x[0] >= 48 && (int)x[0] <= 57){
            bool ver = true;
            int i = x.size() - 1;
            while(ver){
                if(x[i] == '1'){
                    temp = "";
                    temp = temp + x[i] + x[i - 1] + x[i - 2];
                    int n = stringANumero(temp);
                    dev += (char)n;
                    i -= 3;
                }

                else{
                    temp = "";
                    temp = temp + x[i] + x[i - 1];
                    int n = stringANumero(temp);
                    dev += (char)n;
                    i -= 2;
                }

                if(i < 0) ver = false;
            }
        }   
            
        
        else{
            for(int i = 0; i < x.size(); i++){
                temp = numeroAstring((int)x[i]);
                dev += temp;
            }
            reverse(dev.begin(), dev.end());
        }

        cout << dev << endl;   
    }
    return 0;
}
