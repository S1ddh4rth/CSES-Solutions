#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int,int>>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }

    vector<priority_queue<ll>> dist(n+1);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    pq.push({0,1});

    while (!pq.empty()) {
        auto [d,u] = pq.top();
        pq.pop();

        if ((int)dist[u].size() == k && dist[u].top() <= d) continue;
        dist[u].push(d);
        if ((int)dist[u].size() > k) dist[u].pop(); 

        for (auto [v,w] : adj[u]) {
            pq.push({d+w, v});
        }
    }

    vector<ll> ans;
    while (!dist[n].empty()) {
        ans.push_back(dist[n].top());
        dist[n].pop();
    }
    reverse(ans.begin(), ans.end()); 

    for (ll x : ans) cout << x << " ";
    cout << "\n";
}
