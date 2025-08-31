#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<ll>> dist(n+1, vector<ll>(n+1, INF));
    for (int i=1; i<=n; i++) dist[i][i] = 0;

    for (int i=0; i<m; i++) {
        int u, v; ll w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }

    // Floyd–Warshall
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        if (dist[a][b] == INF) cout << -1 << "\n";
        else cout << dist[a][b] << "\n";
    }
}
