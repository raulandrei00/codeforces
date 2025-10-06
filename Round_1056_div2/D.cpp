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

bool ask (int x , int y) {
    cout << x << ' ' << y << endl;
    bool r; cin >> r;
    return r;
}

void solve () {
    int n; cin >> n;
    for (int b = 1; b <= n; b <<= 1) {
        for (int grup = 1; grup <= n; grup += 2*b) {
            if (grup + b > n) break;
            for (int g1 = grup; g1 < grup+b; g1++) {
                for (int g2 = grup+b; g2 <= min(n , grup+2*b-1); g2++) {
                    if (ask(g1 , g2)) return;
                }
            }
        }
    }
    assert(0);
}

int main () {

    // #ifdef LOCAL 
    // freopen("input.txt" , "r" , stdin);
    // #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}