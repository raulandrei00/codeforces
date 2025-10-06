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

void solve () {
    int n; cin >> n;
    int rounds = 0;
    int winners = n;
    int losers = 0;
    while (winners > 1 || losers > 1) {
        // cerr << winners << ' ' << losers << '\n';
        int retrogradat = winners / 2;
        winners = (winners / 2) + (winners % 2);
        losers = (losers / 2) + (losers % 2);
        rounds++;
        
        losers += retrogradat;
        assert(winners + losers <= n);
    }
    rounds++;
    assert(winners == 1 && losers == 1);
    cout << rounds << '\n';
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