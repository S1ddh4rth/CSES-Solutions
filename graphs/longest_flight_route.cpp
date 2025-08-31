#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
     vector<vector<int>> rev(n+1);
     vector<int> in(n+1,0);
     vector<int> topo;
    
    for (int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        rev[b].push_back(a);
        in[b]++;
    }
    
    queue<int> q;
    for (int i=1; i<=n; i++){
        if (in[i]==0) q.push(i);
    }
    
    while (!q.empty()){
        int curr=q.front();
        q.pop();
        topo.push_back(curr);
        for (auto x : adj[curr]){
            in[x]--;
            if (in[x]==0) q.push(x);
        }
    }
    
    vector<int> dist(n+1,INT_MIN);
    vector<int> par(n+1,-1);
    dist[1]=1;
    
    for (int node : topo){
        for (int prev : rev[node]){
            if (dist[node]<dist[prev]+1){
                dist[node]=dist[prev]+1;
                par[node]=prev;
            }
        }
    }
    
    if (dist[n]<0) cout<<"IMPOSSIBLE"<<endl;
    else{
        int curr=n;
        vector<int> temp;
        while (curr!=-1){
            temp.push_back(curr);
            curr=par[curr];
        }
        reverse(temp.begin(),temp.end());
        cout<<temp.size()<<endl;
        for (auto x : temp){
            cout<<x<<" ";
        }
    }
    
    
    
    

}
