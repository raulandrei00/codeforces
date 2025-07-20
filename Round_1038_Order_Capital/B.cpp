#pragma GCC optimize ("O3" , "Ofast", "unroll-loops")
#include<iostream>
#include<vector>
#include<cassert>
#include<functional>
#include<map>
#include<set>

using namespace std;
using ll = long long;
const int NMAX = 2e5;
int a[NMAX+1] , b[NMAX+1] , c[NMAX+1] , d[NMAX+1];

void solve () {
    int n; cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        if (b[i] > d[i]) {

            ans += a[i] + b[i]-d[i];

        }
        else if (a[i] > c[i]) ans += a[i]-c[i];
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
}