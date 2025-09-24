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

const int NMAX = 0;
int a[NMAX+1];
void solve () {
    int n , q; cin >> n >> q;
    ll sau = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sau |= a[i];
    }
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