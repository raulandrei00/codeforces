#pragma GCC optimize ("O3" , "Ofast", "unroll-loops")
#include<iostream>
#include<vector>
#include<cassert>
#include<functional>
#include<map>
#include<set>

using namespace std;
using ll = long long;

ll calc (ll r) {
    return r - 1 - r / 5 - r / 2 - r/3 - r/7 + r/6+r/21+r/14+r/10+r/15+r/35-r/30-r/70-r/105-r/42+r/210;
}

void solve () {
    ll l, r; cin >> l >> r;
    ll ans = calc(r) - calc(l - 1);
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
}