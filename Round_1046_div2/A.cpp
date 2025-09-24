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

void solve () {
    int a , b , c , d;
    cin >> a >> b >> c >> d;
    
    c -= a;
    d -= b;
    
    if (a < b) swap(a , b);
    if (c < d) swap(c , d);

    if (a > 2 * b + 2 || c > 2 * d + 2) cout << "No\n";
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

    return 0;
}