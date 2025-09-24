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

int a[NMAX+1] , b[NMAX+1];

void solve () {
    int n , k; cin >> n >> k;

    for (int i = 1; i <= n; i++) 
    {
        cin >> a[i];
    }
    for (int i = 1; i <= k; i++) {
        cin >> b[i];
    }

    sort(a + 1 , a + 1 + n);
    sort(b + 1 , b + 1 + k);

    ll ans = 0;
    for (int i = n , j = 1 , cnt = 1; i > 0; i-- , cnt++) {
        if (j <= k && cnt == b[j]) {
            j++;
            cnt = 0;
        }
        else {
            ans += a[i];
        }
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

    return 0;
}