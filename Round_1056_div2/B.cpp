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
    int n, k; cin >> n >> k;
    if (k == n*n - 1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    int added = 0;
    vector<vector<char>> ans(n , vector<char>(n , '&'));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n && added < k; j++) {
            added++;
            ans[i][j] = 'U';
            if (added == k) break;
        }
        if (added == k) break;

    }
    if (k != n*n) { 
    ans[n-1][n-1] = 'L';
    ans[n-1][n-2] = 'R';
    for (int j = n-3; j >= 0 && ans[n-1][j] != 'U'; j--) {
        ans[n-1][j] = 'R';
    }
    for (int i = n-2; i >= 0; i--) {
        for (int j = n-1; j >= 0 && ans[i][j] != 'U'; j--) {
            ans[i][j] = 'D';
        }
    }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] ;
        }
        cout << '\n';
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