#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges;
    vector<vector<pair<int,int>>> adj(n+1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u,v,w});
        adj[u].push_back({v,w});
    }
    
    vector<ll> dist(n+1,0); // start with 0, since we don’t know start
    vector<int> par(n+1,-1);

    int s = -1; // vertex in negative cycle

    for (int i = 0; i < n; i++) {
        s = -1;
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                par[v] = u;
                s = v;
            }
        }
    }

    if (s == -1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        // backtrack n times to enter the cycle
        for (int i = 0; i < n; i++) {
            s = par[s];
        }
        // now s is guaranteed inside cycle
        vector<int> cycle;
        int cur = s;
        do {
            cycle.push_back(cur);
            cur = par[cur];
        } while (cur != s && cur != -1);
        cycle.push_back(s);

        reverse(cycle.begin(), cycle.end());
        for (int v : cycle) cout << v << " ";
        cout << "\n";
    }
}
