#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1,s2;
    cin>>s1;
    cin>>s2;
    int n,m;
    n=s1.size();
    m=s2.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1, INT_MAX));
    dp[0][0]=0;
    for (int i=0; i<=n; i++){
        for (int j=0; j<=m; j++){
            if (i){
                dp[i][j]=min(dp[i][j],1+dp[i-1][j]);
            }
            if (j){
                dp[i][j]=min(dp[i][j],1+dp[i][j-1]);
            }
            if (i && j){
                dp[i][j]=min(dp[i][j],dp[i-1][j-1] +(s1[i-1]!=s2[j-1]));
            }
        }
    }
    cout<<dp[n][m]<<endl;
    
    

}
