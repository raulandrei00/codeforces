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
const int NMAX = 2e5;

struct Edge {
    int to;
    int x , y;
    Edge (int _to , int _x , int _y) : to(_to) , x(_x) , y(_y) {}
};

vector<Edge> adj[NMAX+1];
int subtree[NMAX+1];
int p[NMAX+1];

void dfs (int nod , int par, int first_val) {
    
    subtree[nod] = 1;
    int crt_val = first_val;
    for (auto edge : adj[nod]) {
        int to = edge.to , x = edge.x , y = edge.y;
        if (to == par) continue;
        // smaller val 
        if (to < nod && x < y || to > nod && x > y) {
            dfs(to , nod , crt_val);
            crt_val += subtree[to];
        }
    }
    p[nod] = crt_val++;

    for (auto edge : adj[nod]) {
        int to = edge.to , x = edge.x , y = edge.y;
        if (to == par) continue;
        if (to > nod && x <= y || to < nod && x >= y) {
            dfs(to , nod , crt_val);
            crt_val += subtree[to];
        }
        subtree[nod] += subtree[to];
    }

}

void solve () {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        subtree[i] = 0;
        adj[i].clear();
    }
    
    for (int i = 1; i < n; i++) {
        int u , v , x , y;
        cin >> u >> v >> x >> y;
        adj[u].push_back(* new Edge (v , x , y));
        adj[v].push_back(* new Edge (u , x , y));
    }


    dfs(1 , 0 , 1);

    for (int i = 1; i <= n; i++) 
    {
        cout << p[i] << ' ';
    } cout << '\n';

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