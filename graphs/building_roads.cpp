#include <bits/stdc++.h>
using namespace std;

void dfs_visit(int node, vector<int> &vis, vector<vector<int>> &adj){
    vis[node]=1;
    for (auto x: adj[node]){
        if (!vis[x]) dfs_visit(x,vis,adj);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); 
        adj[v].push_back(u);
    }

    vector<int> vis(n+1, 0);
    int ans = 0;
    
    vector<int> nodes;
    
    
    for (int i=1; i<=n ; i++){
        if (!vis[i]){
            dfs_visit(i,vis,adj);
            nodes.push_back(i);
        }
    }


    cout << nodes.size()-1 << "\n";
    for (int i=1; i<nodes.size(); i++){
        cout<<nodes[i-1]<<" "<<nodes[i]<<endl;
    }
}
