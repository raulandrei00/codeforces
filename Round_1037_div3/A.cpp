#pragma GCC optimize ("O3" , "Ofast", "unroll-loops")
#include<bits/stdc++.h>

using namespace std;

void solve () {
    string x; cin >> x;
    sort(x.begin() , x.end());
    cout << x[0] << '\n';
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