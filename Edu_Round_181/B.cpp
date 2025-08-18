#pragma GCC optimize ("O3" , "Ofast", "unroll-loops")
#include<iostream>
#include<vector>
#include<cassert>
#include<functional>
#include<map>
#include<set>
#include<bits\stdc++.h>

using namespace std;
using ll = long long;

void solve () {
    ll x, y, k; cin >> x >> y >> k;
    if (max(x,y) / __gcd(x, y) > k) cout << 2 << '\n';
    else cout << 1 << '\n';
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