#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n+1);
    for (int i=0; i<m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    
    long long ans = 0;   
    vector<int> vis(n+1,0);
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    pq.push({0,1});
    
    while (!pq.empty()){
        auto [w,node] = pq.top();
        pq.pop();
        if (vis[node]) continue;
        vis[node] = 1;
        ans += w;
        
        for (auto [v,edge_w] : adj[node]){
            if (!vis[v]){
                pq.push({edge_w, v});
            }
        }
    }
    
    for (int i=1; i<=n; i++){
        if (!vis[i]){
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }
    
    cout << ans << "\n";
}
