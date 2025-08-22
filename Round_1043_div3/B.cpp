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

void solve () {
    ll n; cin >> n;
    vector <ll> ans;
    for (ll b = 10; b <= 1e18; b *= 10) {
        if (n % (b+1) == 0) ans.push_back(n / (b+1));
    }
    cout << ans.size() << '\n';
    reverse(ans.begin(), ans.end());
    for (auto x : ans) cout << x << ' ';
    if (ans.size()) 
        cout << '\n';
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