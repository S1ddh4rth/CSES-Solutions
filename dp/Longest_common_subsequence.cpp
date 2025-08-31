#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    vector<int> v1(n), v2(m);
    for (int i=0; i<n; i++) cin>>v1[i];
    for (int i=0; i<m; i++) cin>>v2[i];

    vector<vector<int>> dp(n+1, vector<int>(m+1,0));

    // Fill DP table
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (v1[i-1]==v2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout<<dp[n][m]<<endl; // length of LCS

    // Backtracking
    vector<int> ans;
    int i=n, j=m;
    while (i>0 && j>0){
        if (v1[i-1]==v2[j-1]){
            ans.push_back(v1[i-1]);
            i--; j--;
        }
        else if (dp[i-1][j] >= dp[i][j-1]){
            i--;
        }
        else {
            j--;
        }
    }
    reverse(ans.begin(), ans.end());

    for (int x: ans) cout<<x<<" ";
    cout<<endl;
}
