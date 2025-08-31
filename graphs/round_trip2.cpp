#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> state;   // 0 = unvisited, 1 = visiting, 2 = finished
vector<int> parent;
vector<int> cycle;

bool dfs(int u) {
    state[u] = 1; // visiting
    for (int v : adj[u]) {
        if (state[v] == 0) {
            parent[v] = u;
            if (dfs(v)) return true;
        } else if (state[v] == 1) {
            // Found a cycle, backtrack from u to v
            cycle.push_back(v);
            for (int x = u; x != v; x = parent[x]) {
                cycle.push_back(x);
            }
            cycle.push_back(v);
            reverse(cycle.begin(), cycle.end());
            return true;
        }
    }
    state[u] = 2; // finished
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    adj.assign(n+1, {});
    state.assign(n+1, 0);
    parent.assign(n+1, -1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) {
        if (state[i] == 0) {
            if (dfs(i)) {
                cout << cycle.size() << "\n";
                for (int x : cycle) cout << x << " ";
                cout << "\n";
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
}
