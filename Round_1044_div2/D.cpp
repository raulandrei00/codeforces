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
int h[NMAX+2];

struct Node {
    int h;
    int val;
};

struct Aint {
    vector<Node> aint , lazy;
    int n , offset;
    Aint (int _n) : n(_n) {
        offset = 1;
        while (offset < n) offset *= 2;
        aint.resize(2 * offset);
        lazy.resize(2 * offset);
        for (int i = 1; i <= n; i++) {
            aint[i+offset-1] = {h[i], max(h[i] , i)};
        }
    }
};

ll dp[NMAX+1];
ll sp[NMAX+1];

void solve () {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    // stack<pair<int , int> > s;

    // ll ans = 0;

    // for (int i = 1; i <= n; i++) {
    //     while (s.size() && s.top().first < max(i , h[i+1])) {
    //         s.pop();
    //     }
    //     // il batem pe asta si propagam;
    //     int delta = s.size() ? s.top().second : 0;
    //     ans += h[i];
    //     h[i+1] -= i - delta;
    //     s.push({h[i] , i});
    //     if (h[i+1] <= 0) {
    //         i++;
    //         while (i + 1 <= n && h[i+1] <= 1) i++;
    //     }
    // }

    // cout << ans << '\n';

    sp[0] = 0;
    for (int i = 1; i <= n; i++) {
        sp[i] = sp[i-1] + h[i];
    }

    ll minSuf1 = sp[n] - n;
    ll minSuf2 = sp[n] - n;
    int s1p = n+1 , s2p = n+1;
    for (int i = n-1; i >= 1; i--) {
        if (s1p == i+1) {
            dp[i] = minSuf2 + h[i] + i + 2 - sp[i+1] + max(0 , h[i+1] - i);
            dp[i] = min(dp[i] , minSuf1 + h[i]);
        }
        else {
            dp[i] = minSuf2 + h[i] + i + 2 - sp[i+1] + max(0 , h[i+1] - i);
        }
            // cerr << minSuf << ' ' << dp[i] << '\n';
        // minSuf = min(minSuf , dp[i] + sp[i-1] - i);
        if (minSuf1 > dp[i] + sp[i-1] - i) {
            s2p = s1p;
            minSuf2 = minSuf1;
            s1p = i;
            minSuf1 = dp[i] + sp[i-1] - i;
        }
        else if (minSuf2 > dp[i] + sp[i-1] - i) {
            s2p = i;
            minSuf2 = dp[i] + sp[i-1] - i;
        }
    }

    cout << dp[1] << '\n';

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