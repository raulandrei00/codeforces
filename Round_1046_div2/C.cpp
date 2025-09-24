#pragma GCC optimize ("O3" , "Ofast", "unroll-loops")
#include<iostream>
#include<vector>
#include<cassert>
#include<functional>
#include<map>
#include<set>
#include<algorithm>
#include<stack>
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int NMAX = 2e5;
const int LOGMAX = log2(NMAX) + 2;
int a[NMAX+1];
int dp[NMAX+1];
int lift[LOGMAX+1][NMAX+1];
int last[NMAX+1];

void solve () {
    int n; cin >> n;

    for (int i = 0; i <= n; i++) {
        dp[i] = 0;
        last[i] = -1;
        
    }
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        lift[0][i] = last[a[i]];
        last[a[i]] = i;
    }

    for (int b = 1; (1 << b) <= n; b++) {
        for (int i = 1; i <= n; i++) {
            if (lift[b-1][i] > 0)
                lift[b][i] = lift[b-1][lift[b-1][i]];
            else {
                lift[b][i] = -1;
            }
            // cerr << lift[b][i] << ' ';
        } 
        // cerr << '\n';
    }


    for (int i = 1; i <= n; i++) {
        int latest_start = i;
        for (int b = 19; b >= 0 && latest_start >= 0; b--) {
            if ((1 << b) & (a[i]-1)) {
                latest_start = lift[b][latest_start];
            }
        }
        if (latest_start >= 0) {
            dp[i] = max(dp[i-1] , dp[latest_start-1] + a[i]);
        }
        else dp[i] = dp[i-1];
    }

    cout << dp[n] << '\n';

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