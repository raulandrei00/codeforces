#pragma GCC optimize ("O3" , "Ofast", "unroll-loops")
#include<bits/stdc++.h>

using namespace std;
const int NMAX = 1e5;
struct Cazino {
    bool friend operator < (const Cazino &c1 , const Cazino &c2) {
        return c1.l < c2.l;
    }
    int l, real, r;
} casinos[NMAX+1];

void solve () {
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int l, r, re; cin >> l >> r >> re;
        casinos[i] = {l, re, r};
    }
    sort (casinos + 1 , casinos + 1 + n);
    for (int i = 1; i <= n; i++) {
        if (casinos[i].l <= k && casinos[i].real > k) {
            k = casinos[i].real;
        }
    }
    cout << k << '\n';
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