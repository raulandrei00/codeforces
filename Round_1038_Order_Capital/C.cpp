#pragma GCC optimize ("O3" , "Ofast", "unroll-loops")
#include<iostream>
#include<vector>
#include<cassert>
#include<functional>
#include<map>
#include<set>
#include<algorithm>

using namespace std;
using ll = long long;
const int NMAX = 2e5;

int gr[NMAX+1]; // 0 == -- , 1 == -+, 2 == +-, 3==++
pair<int , int> pts[NMAX+1];
pair<int , int>  vx[NMAX+1] , vy[NMAX+1];
vector<int> groups[4];

void solve () {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        cin >> vx[i].first >> vy[i].first;
        vx[i].second = i;
        vy[i].second = i;
        pts[i] = {vx[i].first , vy[i].first};
    }
    sort (vx+1, vx+1 + n);
    sort (vy+1, vy+1 + n);
    
    for (int i = 1; i <= n; i++) {
        int grup = 0;
        if (make_pair(pts[i].first , i) >= vx[n/2+1]) grup += 2;
        if (make_pair(pts[i].second , i) >= vy[n/2+1]) grup ++;
        groups[grup].push_back(i); 
    }

    // cerr << groups[0].size() << ' ' << groups[3].size() << '\n';

    assert(groups[0].size() == groups[3].size());
    assert(groups[1].size() == groups[2].size());

    for (int i = 0; i < groups[0].size(); i++) {
        cout << groups[0][i] << ' ' << groups[3][i] << '\n';
    }
    for (int i = 0; i < groups[1].size(); i++) {
        cout << groups[1][i] << ' ' << groups[2][i] << '\n';
    }

    for (int i = 0; i < 4; i++) groups[i].clear();
}

int main () {

    #ifdef LOCAL 
    freopen("input.txt" , "r" , stdin);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}