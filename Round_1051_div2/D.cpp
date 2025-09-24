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
const int NMAX = 2000;
const ll MOD = 1e9 + 7;
int a[NMAX+1];

ll p2[NMAX+1];

void precalc () {
    p2[0] = 1;
    for (int i = 1; i <= NMAX; i++) {
        p2[i] = 1ll * p2[i-1] * 2 % MOD;
    }
}

struct Aib {
    int n; 
    vector<int> aib;
    Aib(int _n) : n(_n) {
        aib.resize(n+1 , 0);
    }

    void update (int pos , int val) {
        for (int i = pos; i <= n; i += (i & -i)) {
            aib[i] += val;
        }
    }

    int ps (int r) {
        int ret = 0;
        for (int i = r; i > 0; i -= (i & -i)) {
            ret += aib[i];
        }
        return ret;
    }
    void clear () {
        aib.clear();
        aib.resize(n+1 , 0);
    }
};

int gr[NMAX+1];
int less_than[NMAX+1];

void solve () {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    Aib aib_fr(n);
    for (int i = 1; i <= n; i++) {
        gr[i] = i-1 - aib_fr.ps(a[i]);
        aib_fr.update(a[i] , 1);
    }

    aib_fr.clear();
    for (int i = n; i > 0; i--) {
        less_than[i] = aib_fr.ps(a[i]-1);
        aib_fr.update(a[i] , 1);
    }

    ll ans = p2[n];

    for (int i = 1; i < n; i++) {
        aib_fr.clear(); int consider = 0;
        for (int j = i+1; j <= n; j++) {
            if (a[i] > a[j]) {
                // bienn
                int x1 = i - 1 - gr[i];
                int x2 = consider;
                int x3 = less_than[j];
                int x4 = (n-j) - x3;
                if (x3 == 0) consider++;

                ans -= (p2[x1] * p2[x2] % MOD * (p2[x3] - 1) % MOD * p2[x4] % MOD);
                if (ans < 0) ans += MOD;

                aib_fr.update(a[j] , 1);
            }
            else {
                // consider++;
            }
            cerr << i << ' ' << j << ' ' << ans << '\n';
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

    precalc();
    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}