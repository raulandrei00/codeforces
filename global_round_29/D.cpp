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
    map<int , int> fr;
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        fr[x]++;
    }
    ll a = 0 , b = 0;
    bool turn = 0;
    
    vector<pair<ll , ll> > picks; // [cnt , val];

    for (auto [key , val] : fr) {
        picks.push_back(make_pair(val , key));
    }

    sort(picks.begin() , picks.end() , greater<pair<ll , ll>>());

    for (auto [cnt , val] : picks) {
        if (val & 1) {
            if (turn == 0) {
                a += cnt;
                a += val/2 * cnt;
                b += val/2 * cnt;
                
            }
            else {
                b += cnt;
                a += val/2 * cnt;
                b += val/2 * cnt;
            }
            turn ^= 1;
        }
        else {
            a += val/2 * cnt;
            b += val/2 * cnt;
        }
    }

    cout << a << ' ' << b << '\n';

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