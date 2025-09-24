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
    int n; cin >> n;
    vector<int> ans;
    
    if (n == 1) {
        cout << "1 1\n";
        return;
    }
    
    for (int x = (((n-1) | 1 )^ 1); x > 0; x -= 2) {
        ans.push_back(x);
    }
    ans.push_back(n);
    for (int x = 2; x <= (((n-1) | 1 )^ 1); x += 2) {
        ans.push_back(x);
    }
    ans.push_back(1);
    for (int x = ((n-2) | 1); x > 1; x -= 2) {
        ans.push_back(x);
    }
    ans.push_back(n);
    ans.push_back(1);
    for (int x = 3; x <= ((n-2) | 1); x += 2) {
        ans.push_back(x);
    }

    for (auto x : ans) cout << x << ' ';
    cout << '\n';

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