#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges;        // each edge = {u, v, w}
    vector<vector<int>> adj(n+1);     // for BFS propagation

    for (int i = 0; i < m; i++) {
        int u, v; ll w;
        cin >> u >> v >> w;
        edges.push_back({u, v, (int)(-w)});  // store -w (safe cast: CSES weights ≤ 1e9)
        adj[u].push_back(v);
    }

    vector<ll> dist(n+1, INF);
    dist[1] = 0;

    // Bellman–Ford n-1 iterations
    for (int i = 0; i < n-1; i++) {
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            if (dist[u] < INF && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // detect negative cycles
    vector<int> affected(n+1, 0);
    for (auto &e : edges) {
        int u = e[0], v = e[1], w = e[2];
        if (dist[u] < INF && dist[v] > dist[u] + w) {
            affected[v] = 1;
        }
    }

    // BFS propagate "affected" nodes
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (affected[i]) q.push(i);
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (!affected[v]) {
                affected[v] = 1;
                q.push(v);
            }
        }
    }

    if (affected[n]) {
        cout << -1 << "\n";
    } else {
        cout << -dist[n] << "\n";
    }
}
