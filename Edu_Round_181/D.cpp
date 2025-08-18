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
const ll MOD = 998244353;
ll pp[NMAX+1];

ll pow (ll x , ll p) {
    ll ret = 1;
    for (ll b = 1; b <= p; b <<= 1 , x = x*x % MOD) {
        if (p & b) ret = ret * x % MOD;
    }
    return ret;
}

ll imod (ll q) { return pow(q, MOD - 2); }

struct Seg {
    bool friend operator < (const Seg &a, const Seg &b) {
        return a.l < b.l || (a.l == b.l && a.r < b.r);
    }
    ll l, r, p, q;

    ll not_exists () const {
        return (q - p) * imod(q) % MOD;
    }

    ll exists () const {
        return p * imod(q) % MOD;
    }

} seg[NMAX+1];

ll dp[NMAX+1];

void solve () {
    int n, m; cin >> n >> m;
    for (int i = 0; i <= m; i++) {
        pp[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        int l, r, p, q;
        cin >> l >> r >> p >> q;
        seg[i] = {l, r, p, q};
        pp[seg[i].l] *= seg[i].not_exists();
        pp[seg[i].l] %= MOD;
    }
    for (int i = 2; i <= m; i++) {
        pp[i] = pp[i] * pp[i-1] % MOD;
        
    }

    sort(seg + 1, seg + n + 1);

    dp[0] = 1;
    int j = 1;
    for (int i = 1; i <= m; i++) {
        // cerr << dp[i-1] << ' ' << j << '\n';
        while (j <= n && seg[j].l == i) {
            dp[seg[j].r] += dp[i-1] * pp[seg[j].r] % MOD * imod(pp[i-1]) % MOD * seg[j].exists() % MOD * imod(seg[j].not_exists()) % MOD;
            dp[seg[j].r] %= MOD;
            j++;
        }
    }
    cout << dp[m] << '\n';
}

int main () {

    #ifdef LOCAL 
    freopen("input.txt" , "r" , stdin);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; // cin >> t;
    while (t--) {
        solve();
    }
}