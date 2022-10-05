#include <bits/stdc++.h>

#define vi vector<int>
#define vvi vector<vector<int> >
#define endl '\n'

using namespace std;

int low_bou(vvi &A, int low, int hi, int &x){
    if(low + 1 == hi)
        return low + 1;
    else{
        int mid = low + ((hi - low)>>1);
        if(A[mid][0] ==  x) return mid;
        else if(A[mid][0] < x) return low_bou(A, mid, hi, x);
        else return low_bou(A, low, mid, x);
    }
}
void solve(vi &ans, int N, int K, int Q, vi &roll, vi &query){
    vvi intervals;
    vi temp = roll;
    temp.push_back(0);
    temp.push_back(N + 1);
    intervals.push_back(vi(3));
    sort(temp.begin(), temp.end());
    for(int i = 0; i < temp.size() - 1; ++i){
        if(temp[i] + 1 != temp[i + 1])
            intervals.push_back({intervals[intervals.size() - 1][0] + (temp[i + 1] - (temp[i] + 1)), temp[i] + 1, temp[i]});
    }
    for(int i = 0; i < Q; ++i){
        if(query[i] <= K)
            ans.push_back(roll[query[i] - 1]);
        else{
            int est = query[i] - K;
            int index = low_bou(intervals, 0, intervals.size(), est);
            int val = est - intervals[index - 1][0];
            ans.push_back(intervals[index][1] + (val - 1));
        }
    }
}

int main(){
    int tcnt, tc = 0;
    cin >> tcnt;
    while(tcnt--){
        int n, k, q;
        cin >> n >> k >> q;
        vi roll(k), query(q), ans;
        for(int i = 0; i < k; ++i)
            cin >> roll[i];
        for(int i = 0; i < q; ++i)
            cin >> query[i];
        cout << "Case " << ++tc << ":" << endl;
        solve(ans, n, k, q, roll, query);
        for(int i = 0; i < ans.size(); ++i)
            cout << ans[i] << endl;
    } 
    return 0;
}