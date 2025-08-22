#pragma GCC optimize ("O3" , "Ofast", "unroll-loops")
#include<iostream>
#include<vector>
#include<cassert>
#include<functional>
#include<map>
#include<set>
#include<algorithm>
#include<deque>

using namespace std;
using ll = long long;

void solve () {
    deque <char> dq;
    int n, m;
    cin >> n;
    string a , b , c; cin >> a;
    for (auto ch : a) dq.push_back(ch);
    cin >> m >> b >> c;
    for (int i = 0; i < m; i++) {
        if (c[i] == 'D') {
            dq.push_back(b[i]);
        }
        else {
            dq.push_front(b[i]);
        }
    }
    for (auto ch : dq) cout << ch;
    cout << '\n';
    return ;
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