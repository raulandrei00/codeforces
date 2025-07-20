#pragma GCC optimize ("O3" , "Ofast", "unroll-loops")
#include<bits/stdc++.h>

using namespace std;
const int NMAX = 1e5;
int h[NMAX+1];

void solve () {
    int n , k; cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    int lvl = h[k];
    sort (h + 1 , h + 1 + n);

    int j = 1; 
    while (h[j] < lvl) j++;
    int water_lvl = 1;
    bool ans = 1;
    for (int i = j+1; i <= n; i++) {
        // cerr << water_lvl << ' ' << h[i] << '\n';
        if (h[i] - h[i-1] > h[i-1] - water_lvl + 1) {
            ans = 0;
        }
        else {
            water_lvl += h[i] - h[i-1];
        } // crt lvl is now h[i]

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