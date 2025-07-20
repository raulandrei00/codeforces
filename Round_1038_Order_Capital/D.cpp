#pragma GCC optimize ("O3" , "Ofast", "unroll-loops")
#include<iostream>
#include<vector>
#include<cassert>
#include<functional>
#include<map>
#include<queue>
#include<set>

using namespace std;
using ll = long long;
const int NMAX = 5000 , INF = 1e9 + 9;
vector<int> adj[NMAX+1];
int n, m; 
int mod[NMAX+1];

unordered_map<int , pair<int , int>> best[2*NMAX+1];

pair<int , int> bfs () {
    queue<pair<int , int> > q; // [nod , time]
    q.push({1,0});
    for (int i = 1; i <= n; i++) {
        for (int t = 0; t <= 2*m; t++) {
            best[i][t] = {INF , INF};
        }
    }
    best[1][0] = {0,0};
    while (q.size()) {
        auto [nod , time] = q.front();
        // if (nod == n) {
        //     return best[n][time%mod[n]];
        // }
        q.pop();
        
        // 1) move
        int to = adj[nod][time%adj[nod].size()];
        if (best[to][(time+1)%mod[to]] > make_pair(best[nod][time%mod[nod]].first+1 , best[nod][time%mod[nod]].second)) {
            best[to][(time+1)%mod[to]] = make_pair(best[nod][time%mod[nod]].first+1 , best[nod][time%mod[nod]].second);
            q.push({to , time+1});
        }

        // 2) stay
        if (best[nod][(time+1)%mod[nod]] > make_pair(best[nod][time%mod[nod]].first+1 , best[nod][time%mod[nod]].second+1)) {
            best[nod][(time+1)%mod[nod]] = make_pair(best[nod][time%mod[nod]].first+1 , best[nod][time%mod[nod]].second+1);
            q.push({nod , time+1});
        }
    }
    pair<int , int> ans = {INF , INF};
    for (int time = 0; time < mod[n]; time++) {
        ans = min(ans , best[n][time]);
    }
    return ans;
}

void solve () {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x , y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int maxx = 0;
    for (int i = 1; i <= n; i++) maxx = max(maxx , (int)adj[i].size());
    for (int i = 1; i <= n; i++) {
        mod[i] = ((maxx + adj[i].size()-1) / adj[i].size()) * adj[i].size();
    }

    auto rez = bfs();

    for (int i = 1; i <= n; i++) {
        adj[i].clear();
    }

    cout << rez.first << ' ' << rez.second<< '\n';

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