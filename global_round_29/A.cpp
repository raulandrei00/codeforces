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
    int x , y; cin >> x >> y;
    if (x < y) {
        cout << 2 << '\n';
    }
    else if (x - 1 > y && y > 1) {
        cout << 3 << '\n';
    }
    else cout << "-1\n";
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