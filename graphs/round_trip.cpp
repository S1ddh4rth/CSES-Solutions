#include <bits/stdc++.h>
using namespace std;

int start_node = -1, end_node = -1;

void dfs(int node, int parent, vector<int> &vis, vector<int> &par, vector<vector<int>> &adj) {
    vis[node] = 1;
    for (auto x : adj[node]) {
        if (x == parent) continue;
        if (!vis[x]) {
            par[x] = node;
            dfs(x, node, vis, par, adj);
        } else if (vis[x] == 1) {
            // Found a cycle
            start_node = x;
            end_node = node;
        }
    }
    vis[node] = 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(n + 1, 0), par(n + 1, -1);

    for (int i = 1; i <= n; i++) {
        if (!vis[i] && start_node == -1) {
            dfs(i, -1, vis, par, adj);
        }
    }

    if (start_node == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int> cycle;
        cycle.push_back(start_node);
        for (int v = end_node; v != start_node; v = par[v]) {
            cycle.push_back(v);
        }
        cycle.push_back(start_node);
        reverse(cycle.begin(), cycle.end());

        cout << cycle.size() << "\n";
        for (auto v : cycle) cout << v << " ";
        cout << "\n";
    }
}
