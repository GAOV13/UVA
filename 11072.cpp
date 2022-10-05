#include <bits/stdc++.h>

#define endl '\n'
#define pi pair<int, int>
#define vi vector<pair<int, int> >
#define lli long long int

using namespace std;

void swap(pi &p, pi &q);

lli distsq(pi p1, pi p2);

int orientation(pi p, pi q, pi r);

bool compare(pi p1, pi p2);

void convexhull(int n, vi &points, vi &S);

bool phi(pi p, vi &S, vi &points);

void imprimir(vi &algo){
    printf("[(%d, %d)", algo[0].first, algo[0].second);
    for(int i = 1; i < algo.size(); ++i)
        printf(", (%d, %d)", algo[i].first, algo[i].second);
    cout << "]" << endl;
}

pi p0;

int main(){
    int n, m;
    int x, y;
    while(cin >> n){
        vi points(n), S;
        for(int i = 0; i < n; ++i){
            cin >> x >> y;
            points[i] = make_pair(x, y);
        }
        convexhull(n, points, S);
        cin >> m;
        while(m--){
            cin >> x >> y;
            pi p = make_pair(x, y);
            if(phi(p, S, points)) cout << "inside" << endl;
            else cout << "outside" << endl;
        }
    }
    return 0;
}

lli distsq(pi p1, pi p2){
    lli x = (p2.first - p2.second), y = (p2.second - p1.second);
    return (x*x) + (y*y);
}

int orientation(pi p, pi q, pi r){
    int ans;
    lli val = ((q.second-p.second)*(r.first-q.first)) - ((r.second-q.second)*(q.first-p.first));
    if(!val) ans = 0;
    else ans = val > 0 ? 1:2;
    return ans;
}

bool compare(pi p1, pi p2){
    int alpha = orientation(p0, p1, p2);
    bool ans;
    if(alpha == 0) ans = distsq(p0, p2) >= distsq(p0, p1);
    else ans = alpha == 2 ? true:false;
    return ans;
}

void swap(pi &p, pi &q){
    p0 = q;
    q = p;
    p = p0;
}

void convexhull(int n, vi &points, vi &S){
    int min = 0, ymin = points[0].second;
    int x, y, m = 1;
    for(int i = 1; i < n; ++i){
        x = points[i].first; y = points[i].second;
        if((y < ymin) || (y==ymin && x < points[min].first)){
            ymin = y; min = i;
        }
    }
    swap(points[0], points[min]);
    sort(points.begin()+1, points.end(), compare);
    for(int i = 1; i < n; ++i){
        while(i < n-1 && (orientation(p0, points[i], points[i+1]) == 0)) ++i;
        points[m++] = points[i];
    }
    S.push_back(points[0]);
    S.push_back(points[1]);
    S.push_back(points[2]);
    for(int i = 3; i < m; ++i){
        int tam = S.size();
        while(tam > 1 && orientation(S[tam-2], S[tam-1], points[i]) != 2){
            S.pop_back(); --tam;
        }
        S.push_back(points[i]);
    }
    if(S[S.size()-1] == S[S.size()-2] || m < 3) S.pop_back();
}

bool phi(pi p, vi &S, vi &points){
    bool ans = true;
    for(int i = 1; i <= S.size() && ans; ++i){
        pi p1 = S[i-1], p2;
        if(i == S.size()) p2 = S[0];
        else p2 = S[i];
        int a = orientation(p1, p2, p);
        if(a == 1) ans = false;
        else if(a == 0){
            int xm = min(p1.first, p2.first), xM = max(p1.first, p2.first);
            int ym = min(p1.second, p2.second), yM = max(p1.second, p2.second);
            if(!(p.first >= xm && p.first <= xM && p.second >= ym && p.second <= yM))
                ans = false;
        }
    }
    return ans;
}