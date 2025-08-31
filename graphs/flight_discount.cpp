#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges;  // store {u, v, w}
    vector<vector<pair<int,ll>>> adj(n+1), rev(n+1);

    for (int i = 0; i < m; i++) {
        int u, v; ll w;
        cin >> u >> v >> w;
        edges.push_back({u,v,(int)w});
        adj[u].push_back({v,w});
        rev[v].push_back({u,w});
    }

    auto dijkstra = [&](int start, vector<vector<pair<int,ll>>> &graph) {
        vector<ll> dist(n+1, INF);
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
        dist[start] = 0;
        pq.push({0, start});
        while (!pq.empty()) {
            auto [d,u] = pq.top(); pq.pop();
            if (d != dist[u]) continue;
            for (auto [v,w] : graph[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    };

    vector<ll> dist1 = dijkstra(1, adj);   // from 1
    vector<ll> dist2 = dijkstra(n, rev);   // to n (on reversed graph)

    ll ans = INF;
    for (auto &e : edges) {
        int u = e[0], v = e[1], w = e[2];
        if (dist1[u] < INF && dist2[v] < INF) {
            ans = min(ans, dist1[u] + w/2 + dist2[v]);
        }
    }

    cout << ans << "\n";
}
