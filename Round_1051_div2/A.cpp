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

int p[101];

void solve () {
    //detect if p is a mountain permutation
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    bool ans = 1;
    int x = 1;
    int l = 1, r = n;
    while (x <= n) {
        if (p[l] == x) {
            l++;
        }
        else if (p[r] == x) {
            r--;
        }
        else ans = 0;
        x++;
    }
    if (ans) {
        cout << "YES\n";
        
    }
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