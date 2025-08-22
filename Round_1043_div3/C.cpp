#pragma GCC optimize ("O3" , "Ofast", "unroll-loops")
#include<iostream>
#include<vector>
#include<cassert>
#include<functional>
#include<map>
#include<set>
#include<algorithm>

using namespace std;
using ll = long long;
const int NMAX = 1e9;

ll p3[30];

void precalc ()
{
    
    p3[0] = 1;
    for (int i = 1; i < 30 && p3[i-1] <= NMAX; i++)
    {
        p3[i] = p3[i-1] * 3;
        // cerr << p3[i] << ' ';
    }
}

void solve () {
    ll n , k; cin >> n;
    vector<int> deals(20,0);
    
    ll n_temp = n;
    ll total = 0;
    ll cost = 0;
    for (ll p = 1 , i = 0; p <= n; p *= 3 , i++) {
        while (n_temp % (p * 3) != 0) {
            n_temp -= p;
            total++;
            deals[i]++;
            cost += 1ll * i * p / 3 + p * 3;
        }
    }

    cout << cost << '\n';
    return;

    if (total > k) {
        cout << -1 << '\n';
        return;
    }
    for (int i = 19; i > 0; i--) {
        // cerr << i << ' ' << deals[i] << '\n';
        // while (deals[i] > 0 && total + 2 <= k) {

        ll change = min(1ll * deals[i] , 1ll * (k - total) / 2);

            total += 2 * change;
            deals[i] -= change;
            deals[i-1] += 3 * change;
            cost -= change * (1ll * i * p3[i] / 3 + p3[i] * 3);
            // if (i > 1)
            cost += change * p3[i-1] * (i + 8);
            
        // }
        // cerr << cost << '\n';
    }

    cout << cost << '\n';

}

int main () {

    #ifdef LOCAL 
    freopen("input.txt" , "r" , stdin);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    precalc();
    int t; cin >> t;
    while (t--) {
        solve();
    }
}