#pragma GCC optimize ("O3" , "Ofast", "unroll-loops")
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int NMAX = 2e5;
vector<pair<int , int> > adj[NMAX+1];
int a[NMAX+1];
pair<int , int> p[NMAX+1];
int n;

vector<map<int, ll>> init () {
    p[1] = {0,0};
    vector<map<int , ll>> ret(n+1);
    function<void(int)> dfs = [&](int nod) {
        for (auto &[to , cost] : adj[nod]) {
            if (to != p[nod].first) {
                p[to] = {nod , cost};
                ret[nod][a[to]] += cost;
                dfs(to);
            }
        }
    };

    dfs(1);

    return ret;
}

void solve () {
    int q; cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        int x , y, c; cin >> x >> y >> c;
        adj[x].push_back({y , c});
        adj[y].push_back({x , c});
    }

    ll ans = 0;
    vector<map<int , ll> > color_map = init();
    for (int nod = 1; nod <= n; nod++) {
        for (auto &[key , val] : color_map[nod]) {
            if (key != a[nod]) 
                ans += val;
        }
    }

    while (q--) {
        int x , col; cin >> x >> col;
        if (col == a[x]) {cout << ans<<'\n'; continue;}
        ans += color_map[x][a[x]];
        ans -= color_map[x][col];
        if (x != 1) {
            if (a[x] == a[p[x].first]) ans += p[x].second;
            else if (col == a[p[x].first]) ans -= p[x].second;
            color_map[p[x].first][a[x]] -= p[x].second;
            color_map[p[x].first][col] += p[x].second;
        }
        a[x] = col;
        cout << ans << '\n';
    }

    for (int i = 1; i <= n; i++) {
        adj[i].clear();
    }
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