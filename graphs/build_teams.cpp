#include <bits/stdc++.h>
using namespace std;

int flag = 0;

void dfs_visit(int node, int col, vector<int> &team, vector<vector<int>> &adj) {
    team[node] = col;
    for (auto x : adj[node]) {
        if (team[x] == col) {  // same color conflict
            flag = 1;
            return;
        }
        if (team[x] == -1) {
            dfs_visit(x, 3 - col, team, adj); // switch 1 <-> 2
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> team(n+1, -1);
    for (int i = 1; i <= n; i++) {
        if (team[i] == -1) {
            dfs_visit(i, 1, team, adj);
        }
    }

    if (flag) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (int i = 1; i <= n; i++) {
            cout << team[i] << " ";
        }
        cout << "\n";
    }
}
