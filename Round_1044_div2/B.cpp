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
int a[NMAX+1];

void solve () {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1 , a + n + 1);
    ll ans = 0;
    for (int i = 2 + (n % 2); i <= n; i += 2)
    {
        ans += a[i];
    }
    if (n % 2) ans += a[1];
    cout << ans << "\n";
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