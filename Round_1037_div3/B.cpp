#pragma GCC optimize ("O3" , "Ofast", "unroll-loops")
#include<bits/stdc++.h>

using namespace std;
const int NMAX = 1e5;

int a[NMAX+1];
void solve () {
    int n , k; cin >> n >> k;
    bool cooldown = 0;
    int ans = 0;
    int streak = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (!cooldown && a[i] == 0) streak++;
        else if (cooldown) cooldown = 0;
        else streak = 0;
        if (streak == k) {
            streak = 0;
            cooldown = 1;
            ans++;
        }
    }
    cout << ans << '\n';
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