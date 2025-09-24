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
    int n , k; cin >> n >> k;
    string s; cin >> s;
    bool ans = 1;
    int streak = 0;
    for (auto c : s) {
        if (c == '1') streak++;
        else {
            if (streak >= k) {
                ans = 0;
            }
            streak = 0;
        }
    }

    if (streak >= k) ans = 0;

    int cnt = 0;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            p[i] = ++cnt;
        }
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            p[i] = ++cnt;
        }
    }
    if (ans) {
        cout << "Yes\n";
        for (auto x : p) cout << x << ' ';
    
        cout << '\n';
    }
    else cout << "No\n";
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