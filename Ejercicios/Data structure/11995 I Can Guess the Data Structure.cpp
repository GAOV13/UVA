#include <bits/stdc++.h>

#define qi queue<int>
#define si stack<int>
#define pq priority_queue<int>
#define endl '\n'

using namespace std;

int main(){
    int n;
    while(cin >> n){
        qi cola; si pila; pq priori;
        int val = 7;
        for(int i = 0; i < n; ++i){
            int op, num;
            cin >> op >> num;
            if(op == 1){
                if((val & 1) == 1)
                    cola.push(num);
                if((val & 2) == 2)
                    pila.push(num);
                if((val & 4) == 4)
                    priori.push(num);
            }
            else{
                int temp;
                if((val & 1) == 1){
                    if(!cola.empty()){
                        temp = cola.front(); cola.pop();
                        if(num != temp)
                            val = val & 6;
                    }
                    else
                        val = val & 6;
                }
                if((val & 2) == 2){
                    if(!pila.empty()){
                        temp = pila.top(); pila.pop();
                        if(num != temp)
                            val = val & 5;
                    }
                    else
                        val = val & 5;
                }
                if((val & 4) == 4){
                    if(!priori.empty()){
                        temp = priori.top(); priori.pop();
                        if(num != temp)
                            val = val & 3;
                    }
                    else
                        val = val & 3;
                }
            }
        }
        if(val == 0)
            cout << "impossible" << endl;
        else if(val == 1)
            cout << "queue" << endl;
        else if(val == 2)
            cout << "stack" << endl;
        else if(val == 4)
            cout << "priority queue" << endl;
        else
            cout << "not sure" << endl;
    }
    return 0;
}