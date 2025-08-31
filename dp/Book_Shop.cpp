#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,x;
    cin>>n>>x;
    vector<int> wt(n,-1);
    vector<int> val(n,-1);
    for (int i=0; i<n; i++){
        cin>>wt[i];
    }
    for (int i=0; i<n; i++){
        cin>>val[i];
    }
    
    vector<vector<int>> dp(n, vector<int>(x + 1, 0));
    for (int i = wt[0]; i <= x; i++) {
        dp[0][i] = val[0];
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= x; j++) {
            int not_take = dp[i - 1][j];
            int take = 0;
            if (wt[i] <= j) {
                take = val[i] + dp[i - 1][j - wt[i]];
            }
            dp[i][j] = max(not_take, take);
        }
    }
    cout<<dp[n - 1][x]<<endl;

}
