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
const int NMAX = 100;
const ll INF = 1e17;

pair<ll , ll> anch[NMAX+1];

ll ask (char d , ll k) {
    cout << "? " << d << ' ' << k << endl;
    ll s; cin >> s;
    return s; 
}

void solve () {
    int n; cin >> n;
    ll max_sum = -INF, max_dif = -INF;
    ll max_up = -INF , max_right = -INF;
    int index_up = -1;
    int index_right = -1;
    for (int i = 1; i <= n; i++) {
        cin >> anch[i].first >> anch[i].second;
        max_sum = max(max_sum , anch[i].first + anch[i].second);
        max_dif = max(max_dif , -anch[i].first + anch[i].second);
        if (anch[i].first > max_up) {
            max_up = anch[i].first;
            index_up = i;
        }
        if (anch[i].second > max_right) {
            max_right = anch[i].second;
            index_right = i;
        }
    }

    ll s1 = ask('U' , 1e9);
    s1 = ask('U' , 1e9);
    s1 = ask('R' , 1e9);
    s1 = ask('R' , 1e9);
    

    ll s2 = ask('L' , 1e9);
    s2 = ask('L' , 1e9);
    s2 = ask('L' , 1e9);
    s2 = ask('L' , 1e9);

    ll sum = max_sum + s1 - 4e9;
    ll dif = max_dif + s2 - 4e9;
    
    // => 
    ll x = (sum + dif) / 2;
    ll y = (sum - dif) / 2;

    swap(x , y);

    cout << "! " << x << ' ' << y << endl;

}

int main () {

    // #ifdef LOCAL 
    // freopen("input.txt" , "r" , stdin);
    // #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}