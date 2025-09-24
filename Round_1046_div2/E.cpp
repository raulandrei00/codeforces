#pragma GCC optimize ("O3" , "Ofast", "unroll-loops")
#include<iostream>
#include<vector>
#include<cassert>
#include<functional>
#include<map>
#include<set>
#include<algorithm>
#include<stack>

using namespace std;
using ll = long long;
const int NMAX = 2e5;
int a[NMAX+1];

struct Dsu {
    int n;
    vector<int> par , sef , dist , sz;

    Dsu (int _n) : n(_n) {
        par.resize(n+1);
        dist.resize(n+1 , 0);
        sef.resize(n+1);
        sz.resize(n+1 , 0);
        for (int i = 1; i <= n; i++) {
            par[i] = i;
            sef[i] = i;
        }
    }

    pair<int , int> find (int nod) {
        if (par[nod] == nod) return {nod , 0};
        else {
            auto [p , d] = find(par[nod]);
            dist[nod] ^= d;
            par[nod] = p;
            return make_pair(p , dist[nod]);
        }
    }

    pair<bool , bool> unite (int x , int y , int val) {
        
        auto [xp , dx] = find(x);
        auto [yp , dy] = find(y);

        if (xp == yp) {
            if (dx ^ dy != val) {
                return {0,0};
            }
            else return {0,1};
        }
        if (sz[x] < sz[y]) swap(x , y);
        par[yp] = xp;
        sz[xp] += sz[yp];
        dist[yp] = val ^ dy;
        sef[yp] = xp;
    }

};
const int INF = 1e9 + 3;
const int MOD = 998244353;

ll imod (ll x) {
    ll ret = 1;
    ll p = MOD - 2;
    for (int b = 1; b <= p; b <<= 1) {
        if (b & p) ret = ret * x % MOD;
        x = x*x % MOD;
    }
    return ret;
}

ll v;
ll ans = 1;
int pos[NMAX+1];
bool viz[NMAX+1];
vector<int> adj[NMAX+1];
vector<int> node_stack;
int n;

vector<int> val_stack;

map<int , int> current_vals;

// largest odd cyc, largest even cyc (by node stack)
pair<int , int> dfs (int nod) {
    node_stack.push_back(nod);
    bool popp = 0;
    if (a[nod] != -1) {
        val_stack.push_back(a[nod]);
        popp = 1;
    }
    int ret_val = 0;
    viz[nod] = 1;
    int nod_even = 0, nod_odd = 0;
    

    // cerr << nod << ' ' << ans << '\n';

    // for (int i = 1; i <= n; i++) {
    //     cerr << a[i] << ' ';
    // } cerr << '\n';

    // if (a[nod] >= 0) current_vals[a[nod]]++;

    for (auto to : adj[nod]) {
        if (!viz[to]) {
            pos[to] = pos[nod]+1;
            auto checker = dfs(to);
            if (pos[nod_even] > pos[checker.second]) {
                nod_even = checker.second;
            }
            if (pos[nod_odd] > pos[checker.first]) {
                nod_odd = checker.first;
            }
            if (pos[checker.first] <= pos[nod] || pos[checker.second] <= pos[nod] && a[nod] == -1) {
                a[nod] = a[to];
                // if (a[nod] == -2) {
                //     ans *= v;
                //     ans %= MOD;
                // }
            }
            
            if (pos[checker.first] <= pos[nod] && a[nod] != 0) {
                ans = 0;
            }
            else if (pos[checker.second] <= pos[nod] && a[nod] != a[to]) {
                if (a[to] == v+1) {
                    ans = ans * imod(v) % MOD;
                }
                else
                    ans = 0;
            }
        }
        else if (pos[nod] - pos[to] > 1){
            // cerr << "????\n";
            if ((pos[nod] - pos[to]) % 2 == 0) {
                if (a[nod] <= 0) a[nod] = 0;
                else ans = 0;
                if (pos[to] < pos[nod_odd]) {
                    nod_odd = to;
                }
            }
            else {
                // if (a[nod] == -1) a[nod] = -2;
                if (a[nod] == -1 && val_stack.size()) a[nod] = val_stack.back();
                if (pos[to] < pos[nod_even]) {
                    nod_even = to;
                }
            }
        }
    }
    node_stack.pop_back();
    pos[nod] = INF;

    if (a[nod] == -1) {
        a[nod] = v+1;
        
        ans *= v;
        ans %= MOD;
    }
    
    if (popp) val_stack.pop_back();
    // current_vals[a[nod]]--;
    // if (current_vals[a[nod]] == 0) current_vals.erase(a[nod]);

    // for (int i = 1; i <= n; i++) {
    //     cerr << a[i] << ' ';
    // } cerr << '\n';
    // cerr << nod << ' ' << ans<<'\n';
    // cerr << "->" << nod_odd << ' ' << nod_even << '\n';

    return make_pair(nod_odd , nod_even);
}

void solve () {
    ans = 1;
    int m; cin >> n >> m >> v;
    pos[0] = INF;
    for (int i = 1; i <= n; i++) {
        viz[i] = 0;
        pos[i] = INF;
        cin >> a[i];
    }

    for (int i = 1; i <= m; i++) {
        int x , y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    pos[1] = 1;
    dfs(1);

    for (int i = 1; i <= n; i++) {
        adj[i].clear();
    }

    cout << ans << '\n';

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

    return 0;
}