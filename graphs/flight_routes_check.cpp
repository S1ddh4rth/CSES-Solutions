#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<int> &vis){
    vis[node] = 1;
    for (auto x : adj[node]){
        if (!vis[x]) dfs(x, adj, vis);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1), rev(n+1);

    for (int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        rev[b].push_back(a);   // reverse edge
    }

    vector<int> vis1(n+1,0), vis2(n+1,0);
    
    // Check reachability from 1
    dfs(1, adj, vis1);
    for (int i=1; i<=n; i++){
        if (!vis1[i]){
            cout << "NO\n";
            cout << 1 << " " << i << "\n";
            return 0;
        }
    }

    // Check reachability to 1 (via reversed graph)
    dfs(1, rev, vis2);
    for (int i=1; i<=n; i++){
        if (!vis2[i]){
            cout << "NO\n";
            cout << i << " " << 1 << "\n";
            return 0;
        }
    }

    cout << "YES\n";
}
