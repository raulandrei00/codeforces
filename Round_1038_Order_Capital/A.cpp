#pragma GCC optimize ("O3" , "Ofast", "unroll-loops")
#include<iostream>
#include<vector>
#include<cassert>
#include<functional>
#include<map>
#include<set>

using namespace std;
using ll = long long;

void solve () {

    int n, m; cin >> n >> m;
    if (n < 3 && m < 3 || min(n , m) == 1) cout << "No\n";
    else cout << "Yes\n";

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