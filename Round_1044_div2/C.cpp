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
const int NMAX = 500;

int ask (set<int>& nodes , int start) {
    cout << "? " << start << " " << nodes.size() << " ";
    for (auto it = nodes.begin(); it != nodes.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    int x; cin >> x;
    
    return x;
}

void solve () {
    int n; cin >> n;
    int start = -1;
    set <int> nodes;
    for (int i = 1; i <= n; i++) {
        nodes.insert(i);
    }
    int maxx = 0;
    vector<int> dist(n+1 , 0);
    for (int i = 1; i <= n; i++) {
        dist[i] = ask(nodes , i);
        maxx = max(maxx , dist[i]);
        if (maxx == dist[i]) start = i;
    }

    for (int i = 1; i <= n; i++) {
        if (i != start) {
            nodes.erase(i);
        }
        int temp = ask(nodes , start);
        if (temp < maxx) nodes.insert(i);
    }

    vector<int> ans;
    for (auto x : nodes) {
        ans.push_back(x);
    }
    sort(ans.begin() , ans.end() , [&](int a , int b) {
        return dist[a] > dist[b];
    });

    cout << "! " << maxx << ' ';
    for (int x : ans) cout << x << ' ';
    cout << endl;
    

}

int main () {

    #ifdef LOCAL 
    // freopen("input.txt" , "r" , stdin);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}