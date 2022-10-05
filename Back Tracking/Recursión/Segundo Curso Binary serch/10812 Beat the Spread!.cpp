#include <iostream>

#define endl '\n'
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        long long int bet, score;
        cin >> bet >> score;
        if(bet < score) cout << "impossible" << endl;

        else{
            long long int score1, score2; 
            int itr = 0;
            score1 = score2 = score;
            while(itr != 100){
                long long int dist = bet - score1;
                dist /= 2;
                score1 += dist;
                score2 = bet - score1;
                ++itr;
                if(score1 - score2 == score) break;
            }

            if(score1 - score2 != score) cout << "impossible" << endl;

            else cout << score1 << " " << score2 << endl;
        }
    }
    return 0;
}
