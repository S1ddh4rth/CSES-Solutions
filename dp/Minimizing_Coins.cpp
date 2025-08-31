#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,x;
    cin>>n>>x;
    vector<int> coins(n);
    for (int i=0; i<n; i++){
        cin>>coins[i];
    }
    vector<long long> dp(x+1,INT_MAX);
    dp[0]=0;
    for (int i=1; i<=x; i++){
        for (auto c: coins){
            if (c<=i) dp[i]=min(dp[i], dp[i-c]+1);
        }
    }
    
    long long ans = (dp[x]!=INT_MAX) ? dp[x] : -1;
    cout<<ans<<endl;

}
