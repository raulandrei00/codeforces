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
    int n; cin >> n;
    vector<int> a(n+1);
    vector<int> f(101 , 0);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f[a[i]]++;
        if (f[a[i]] == 2) ans = 1;
    }
    if (ans) cout << "YES\n";
    else cout << "NO\n";
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