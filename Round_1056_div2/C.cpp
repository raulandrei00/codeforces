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
const int MOD = 676767677;
const int NMAX = 1e5;
int a[NMAX+1];

void solve () {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    long long ans = 1;
    vector<char> dir(n+1 , '*');

    auto assign = [&] (int pos , char val) {
        // cerr << pos << ' ' << val << '\n';
        if (dir[pos] != '*' && dir[pos] != val) {
            ans = 0;
            // cerr << "oops " <<pos << ' '<< dir[pos] << ' ' << val << '\n';
        }
        else {
            dir[pos] = val;
        }
    };

    int propag_pos = -1;
    
    for (int i = 1; i < n; i++) {
        int delta = a[i+1] - a[i];
        if (delta == 1) {
            assign(i , 'D');
            assign(i+1 , 'D');
            if (propag_pos == -1)
                propag_pos = i;
        }
        else if (delta == -1) {
            if (propag_pos == -1)
                propag_pos = i;
            assign(i , 'S');
            assign(i+1 , 'S');
        }
        else if (delta == 0) {
            if (dir[i] == 'S') assign(i+1 , 'D');
            else if (dir[i] == 'D') assign(i+1 , 'S');
        }
        else ans = 0;
    }
    // cerr << "!" << ans << '\n';
    if (propag_pos == -1) {
        if (n % 2 == 1 && a[1] == (n+1) / 2)
            ans *= 2;
        else if (n % 2 == 1 && a[1] != (n+1) / 2) ans = 0;
        else if (n % 2 == 0 && (a[1] == n/2 || a[1] == n/2 + 1)) ans *= 1;
        else ans = 0;
    }
    else {
        for (int i = propag_pos-1; i > 0; i--) {
            if (dir[i+1] == 'S') assign(i , 'D');
            else assign(i , 'S');
        }
        vector<int> l(n+1 , 0) , r(n+2 , 0);
        for (int i = 1; i <= n; i++) {
            l[i] = l[i-1] + (dir[i] == 'D');
        }
        for (int i = n; i > 0; i--) {
            r[i] = r[i+1] + (dir[i] == 'S');
        }
        for (int i = 1; i <= n; i++) {
            // cerr << l[i] + r[i] << ' ';
            if (l[i] + r[i] != a[i]) ans = 0;
        } 
        // cerr << '\n';
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

    return 0;
}