#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    
    vector<long long> dist(n+1, LLONG_MAX);
    vector<int> ways(n+1, 0);
    vector<int> s_min(n+1, INT_MAX);
    vector<int> s_max(n+1, INT_MIN);
    
    dist[1] = 0;
    ways[1] = 1;
    s_min[1] = 0;
    s_max[1] = 0;
    
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    pq.push({0, 1});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue; // skip stale entries
        
        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                ways[v] = ways[u];
                s_min[v] = s_min[u] + 1;
                s_max[v] = s_max[u] + 1;
                pq.push({dist[v], v});
            }
            else if (dist[v] == dist[u] + w) {
                ways[v] = (ways[v] + ways[u]) % MOD;
                s_min[v] = min(s_min[v], s_min[u] + 1);
                s_max[v] = max(s_max[v], s_max[u] + 1);
            }
        }
    }
    
    cout << dist[n] << " " << ways[n] << " " << s_min[n] << " " << s_max[n] << endl;
}
