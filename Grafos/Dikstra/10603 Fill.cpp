#include <bits/stdc++.h>

#define pqvi priority_queue<vector<int> >
#define pii pair<int, int>
#define endl '\n'

using namespace std;

int tanka[200], tankb[200], tankc[200];
bool tankba[200], tankbb[200], tankbc[200];

vector<int> operacion(int num1, int num2, int tam){
    int dist = tam - num2, ini = 0, fin = 0;
    if(num1 - dist < 0){
        dist = num1;
        fin = num2 + num1;
    }
    else{
        ini = num1 - dist;
        fin = tam;
    }

    vector<int> dev = {ini, fin, dist};
    return dev;
}

pii dikstra(int d, int tama, int tamb, int tamc){
    pqvi cola;
    vector<int> temp = {0, 0, 0, tamc};
    
    cola.push(temp);
    pii par = make_pair(0, 0);
    if(tamc <= d) par.second = tamc;

    while(!cola.empty()){
        temp = cola.top(); cola.pop();
        int peso = temp[0] * -1, a = temp[1], b = temp[2], c = temp[3];
        if((!tankba[a]) || (!tankbb[b]) || (!tankbc[c])){
            if(a == d || b == d || c == d) return make_pair(peso, d);

            tankba[a] = true; tankbb[b] = true; tankbc[c] = true;
            if(a > par.second and a < d){
                par.first = peso;
                par.second = a;
            }
            if(b > par.second and b < d){
                par.first = peso;
                par.second = b;
            }
            if(c > par.second and c < d){ 
                par.first = peso;
                par.second = c;
            }

            if(c > 0){
                if(a < tama){
                    vector<int> temp1 = operacion(c, a, tama);
                    int ini = temp1[0], fin = temp1[1], dist = temp1[2];
                    if((peso + dist < tanka[fin] && !tankba[fin]) || (peso + dist < tankb[b] && !tankbb[b]) || (peso + dist < tankc[ini] && !tankbc[ini])){
                        tanka[fin] = peso + dist;
                        tankb[b] = peso + dist;
                        tankc[ini] = peso + dist;
                        temp[0] = (peso + dist) * -1; temp[1] = fin; temp[2] = b; temp[3] = ini;
                        cola.push(temp);
                    }
                }

                if(b < tamb){
                    vector<int> temp1 = operacion(c, b, tamb);
                    int ini = temp1[0], fin = temp1[1], dist = temp1[2];
                    if((peso + dist < tanka[a] && !tankba[a]) || (peso + dist < tankb[fin] && !tankbb[fin]) || (peso + dist < tankc[ini] && !tankbc[ini])){
                        tanka[a] = peso + dist;
                        tankb[fin] = peso + dist;
                        tankc[ini] = peso + dist;
                        temp[0] = (peso + dist) * -1; temp[1] = a; temp[2] = fin; temp[3] = ini;
                        cola.push(temp);
                    }
                }
            }

            if(b > 0){
                if(a < tama){
                    vector<int> temp1 = operacion(b, a, tama);
                    int ini = temp1[0], fin = temp1[1], dist = temp1[2];
                    if((peso + dist < tanka[fin] && !tankba[fin]) || (peso + dist < tankb[ini] && !tankbb[ini]) || (peso + dist < tankc[c] && !tankbc[c])){
                        tanka[fin] = peso + dist;
                        tankb[ini] = peso + dist;
                        tankc[c] = peso + dist;
                        temp[0] = (peso + dist) * -1; temp[1] = fin; temp[2] = ini; temp[3] = c;
                        cola.push(temp);
                    }
                }

                if(c < tamc){
                    vector<int> temp1 = operacion(b, c, tamc);
                    int ini = temp1[0], fin = temp1[1], dist = temp1[2];
                    if((peso + dist < tanka[a] && !tankba[a]) || (peso + dist < tankb[ini] && !tankbb[ini]) || (peso + dist < tankc[fin] && !tankbc[fin])){
                        tanka[a] = peso + dist;
                        tankb[ini] = peso + dist;
                        tankc[fin] = peso + dist;
                        temp[0] = (peso + dist) * -1; temp[1] = a; temp[2] = ini; temp[3] = fin;
                        cola.push(temp);
                    }
                }
            }

            if(a > 0){
                if(c < tamc){
                    vector<int> temp1 = operacion(a, c, tamc);
                    int ini = temp1[0], fin = temp1[1], dist = temp1[2];
                    if((peso + dist < tanka[ini] && !tankba[ini]) || (peso + dist < tankb[b] && !tankbb[b]) || (peso + dist < tankc[fin] && !tankbc[fin])){
                        tanka[ini] = peso + dist;
                        tankb[b] = peso + dist;
                        tankc[fin] = peso + dist;
                        temp[0] = (peso + dist) * -1; temp[1] = ini; temp[2] = b; temp[3] = fin;
                        cola.push(temp);
                    }
                }

                if(b < tamb){
                    vector<int> temp1 = operacion(a, b, tamb);
                    int ini = temp1[0], fin = temp1[1], dist = temp1[2];
                    if((peso + dist < tanka[ini] && !tankba[ini]) || (peso + dist < tankb[fin] && !tankbb[fin]) || (peso + dist < tankc[c] && !tankbc[c])){
                        tanka[ini] = peso + dist;
                        tankb[fin] = peso + dist;
                        tankc[c] = peso + dist;
                        temp[0] = (peso + dist) * -1; temp[1] = ini; temp[2] = fin; temp[3] = c;
                        cola.push(temp);
                    }
                }
            }
        }
    }
    return par;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for(int i = 0; i < a; ++i){ 
            tanka[i] = 2147483647;
            tankba[i] = false;
        }

        for(int i = 0; i < b; ++i){ 
            tankb[i] = 2147483647;
            tankbb[i] = false;
        }

        for(int i = 0; i < c; ++i){
            tankc[i] = 2147483647;
            tankbc[i] = false;
        }

        pii par = dikstra(d, a, b, c);
        cout << par.first << ' ' << par.second << endl;
    }
    return 0;
}
