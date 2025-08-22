#pragma GCC optimize ("O3" , "Ofast", "unroll-loops")
#include<iostream>
#include<vector>
#include<cassert>
#include<functional>
#include<map>
#include<set>
#include<algorithm>
#include<queue>

using namespace std;
using ll = long long;

const int NMAX = 2e5;
const int QMAX = 2e5;

vector<int> adj[NMAX+1];
vector<pair<int , int> > edges;
vector<pair<int , int> > crit;
pair<int , int> dist_crit[NMAX+1];

map<pair<int , int> , int> edge_id;

const int INF = 1e9 + 9;

void bfs_2(int n) {
    for (int i = 1; i <= n; i++) {
        dist_crit[i] = {INF , -1};
    }
    queue<int> q;
    for (auto [nod , id] : crit) {
        dist_crit[nod] = min(dist_crit[nod], {0 , id});
        q.push(nod);
    }
    while (q.size()) {
        int nod = q.front(); q.pop();
        for (auto to : adj[nod]) {
            if (make_pair(dist_crit[to].first, dist_crit[to].second) > make_pair(dist_crit[nod].first + 1, dist_crit[nod].second)) {
                dist_crit[to] = {dist_crit[nod].first + 1, dist_crit[nod].second};
                q.push(to);
            }
        }
    }
}

int min_dep[NMAX+1];
int depth[NMAX+1];
int n;
bool viz[NMAX+1];

int timer = 0;

bool dfs (int nod = 1 , int par=0) {
    depth[nod] = timer++;
    min_dep[nod] = depth[nod];
    viz[nod] = 1;
    bool ret = 0;
    if (nod == n) ret = 1;
    for (auto to : adj[nod]) {
        if (to == par) continue;
        if (viz[to]) {
            min_dep[nod] = min(min_dep[nod], depth[to]);
        }
        else {
            bool good = dfs(to, nod);
            ret |= good;
            min_dep[nod] = min(min_dep[nod], min_dep[to]);
            
        }

    }

    if (min_dep[nod] == depth[nod] && par != 0 && ret) {
        crit.push_back({nod , edge_id[{nod , par}]});
        crit.push_back({par , edge_id[{par , nod}]});
    }

    return ret;
}

void solve () {
    timer = 0;
    int m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        viz[i] = 0;
    }
    edges.clear();
    crit.clear();
    edge_id.clear();
    for (int i = 1; i <= m; i++) {
        int u , v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edge_id[{u , v}] = i;
        edge_id[{v , u}] = i;
        edges.push_back({u , v});
    }


    // for (auto nod : crit) cerr << nod << " ";
    // cerr << endl;

    dfs();

    if (crit.empty()) {
        cout << -1 << '\n';
        int q; cin >> q;
        while (q--) {
            int x; cin >> x;
            
        }
        return;
    }

    bfs_2(n);

    int q; cin >> q;

    for (int i = 1; i <= q; i++) {
        int x; cin >> x;
        cout << dist_crit[x].second << " ";
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