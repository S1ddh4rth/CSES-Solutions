#include <bits/stdc++.h>
using namespace std;
int MOD=1e9+7;

int main() {
    int n;
    cin>>n;
    vector<long long> dp(n+1,0);
    dp[0]=1;
    dp[1]=1;
    for (int i=2; i<=n; i++){
        for (int c=1;c<=6;c++){
            if (i>=c) {
                dp[i]+=dp[i-c]%MOD;
                dp[i]=dp[i]%MOD;
            }
        }
    }
    cout<<dp[n]%MOD<<endl;
}
