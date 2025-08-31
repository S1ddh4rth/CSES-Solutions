#include <bits/stdc++.h>
using namespace std;

void dfs(int i, int j, int n, int m, vector<vector<bool>> &vis, vector<vector<char>> &grid){
    int dx[]={1,-1,0,0};
    int dy[]={0,0,1,-1};
    vis[i][j]=true;
    for (int dir=0; dir<4; dir++){
        int x=i+dx[dir];
        int y=j+dy[dir];
        if (x>=0 && y>=0 && x<n && y<m && !vis[x][y] && grid[x][y]=='.'){
            dfs(x,y,n,m,vis,grid);
        }
    }
    
}

int main() {
	// your code goes here
	int n,m;
	cin>>n>>m;
	vector<vector<bool>> vis(n,vector<bool> (m,false));
	vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
	int rooms=0;
	for (int i=0; i<n; i++){
	    for (int j=0; j<m; j++){
	        if (grid[i][j]=='.' && !vis[i][j]){
	            dfs(i,j,n,m,vis,grid);
	            rooms++;
	        }
	    }
	} 
	cout<<rooms<<endl;
	

}
