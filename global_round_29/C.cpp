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

bool solve_rabbit(int i , vector<int> &dir , bool &ans, string &s, int n) {
    // force right
    bool assigned = 0;
    if (i > 1 && s[i-1] == s[i-2] && s[i-1] == '1' ||
        i < n-2 && s[i+1] == '1' && s[i+2] == '0' && dir[i+2] == -1 ||
        i == 1 && s[i-1] == '1') {
        if (dir[i] == -1) ans = 0;
        else dir[i] = 1 , assigned = 1;
    }
    // force left
    if (i < n-2 && s[i+1] == s[i+2] && s[i+1] == '1' || 
        i > 1 && s[i-1] == '1' && s[i-2] == '0' && dir[i-2] == 1 ||
        i == n-2 && s[i+1] == '1') {
        if (dir[i] == 1) ans = 0;
        else dir[i] = -1 , assigned = 1;
    }
    return assigned;
}

void dfs(int rabbit, vector<int> &dir , bool &ans, string &s, int n) {
    if (solve_rabbit(rabbit , dir , ans , s , n)) {
        int l = rabbit-2 , r = rabbit+2;
        if (l >= 0 && s[l] == '0') dfs(l , dir , ans , s , n);
        if (r >= 0 && s[r] == '0') dfs(r , dir , ans , s , n);
    }
}

const int NMAX = 2e5;
bool dp[2][NMAX+1];

void solve () {
    
    int n; cin >> n;
    string s; cin >> s;
    bool ans = 1;
    
    for (int i = 0; i < n; i++) {
        dp[0][i] = dp[1][i] = 0;
        if (s[i] == '1') continue;
        // can look left
        if (i == 0 || s[i-1] == '0' || i > 1 && dp[1][i-2] == 1) {
            dp[0][i] = 1;
        }
        // can look right
        if ((i == n-1 || s[i+1] == '0' || i < n-2 && s[i+2] == '0') && 
            !(i > 1 && s[i-2] == '0' && s[i-1] == '1' && dp[0][i-2] == 0)) {
            dp[1][i] = 1;
        }
        if (dp[0][i] + dp[1][i] == 0) ans = 0;
        // cerr << i << ' ' << dp[0][i] << ' ' << dp[1][i] << '\n';
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