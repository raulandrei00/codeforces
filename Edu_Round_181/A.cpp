#pragma GCC optimize ("O3" , "Ofast", "unroll-loops")
#include<iostream>
#include<vector>
#include<cassert>
#include<functional>
#include<map>
#include<set>
#include<algorithm>

bool cmp (char a , char b) {
    if (a == 'T') return true;
    if (b == 'T') return false;
    return a < b;
}

using namespace std;
using ll = long long;

void solve () {
    string s; cin >> s;
    int cnt = 0;
    for (char c : s) {
        if (c == 'T') cnt++;
    }
    for (int i = 0; i < cnt; i++) cout << 'T';
    for (char &c : s) {
        if (c != 'T') {
            cout << c;
        }
    }

    cout << '\n';
    
    return;
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