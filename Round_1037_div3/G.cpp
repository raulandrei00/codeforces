#pragma GCC optimize ("O3" , "Ofast", "unroll-loops")
#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const int NMAX = 2e5;
int a[NMAX+1];

struct Rmq {
    vector<vector< pair<int , int> > > rmq;
    int n , lg;
    Rmq (int _n) : n(_n) {
        lg = 1;
        while ((1 << lg) < n) lg++;
        rmq.resize(lg+1 , vector<pair<int , int>> (n+1));
        for (int i = 1; i <= n; i++) {
            rmq[0][i] = {a[i] , i};
        }
        for (int b = 1; b <= lg; b++) {
            for (int i = 1; i <= n - (1 << (b-1)); i++) {
                rmq[b][i] = min(rmq[b-1][i] , rmq[b-1][i + (1 << (b-1))]);
            }
        }
    }
    int query_index (int l , int r) {
        int lg2 = log2(r - l + 1);
        if (rmq[lg2][l].first < rmq[lg2][r - (1 << lg2) + 1].first) {
            return rmq[lg2][l].second;
        }
        else return rmq[lg2][r - (1 << lg2) + 1].second;
    }
};

void solve () {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    Rmq rmq(n);

    

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