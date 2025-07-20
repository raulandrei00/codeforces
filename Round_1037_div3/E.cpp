#pragma GCC optimize ("O3" , "Ofast", "unroll-loops")
#include<bits/stdc++.h>

using namespace std;
const int NMAX = 1e5;
int p[NMAX+5] , s[NMAX+5];

void solve () {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    s[0] = p[0] = 0;
    s[n+1] = p[n+1] = 0;

    bool ans = 1;
    for (int i = 0; i <= n; i++) {
        // cerr << __gcd(p[i] , s[i+1]) << ' ';
        if (__gcd(p[i] , s[i+1]) != s[1]) ans = 0;
    }
    for (int i = 1; i < n; i++) {
        if (p[i] % p[i+1] != 0 || s[i+1] % s[i] != 0) ans = 0;
    }

    if (ans) cout << "yes\n";
    else cout << "no\n";

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