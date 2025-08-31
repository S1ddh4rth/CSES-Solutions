#include <bits/stdc++.h>
using namespace std;

set<int> split(long long num) {
    set<int> s;
    if (num == 0) {
        s.insert(0); // handle special case
        return s;
    }
    while (num > 0) {
        int d = num % 10;
        s.insert(d);
        num /= 10;
    }
    return s;
}

int main() {
    int n;
    cin>>n;
    vector<long long> dp(n+1,INT_MAX);
    dp[0]=0;
    for (int i=1; i<=n; i++){
        set<int> nums=split(i);
        for (auto x : nums){
            if (x<=i)dp[i]=min(dp[i], dp[i-x]+1);
        }
    }
    cout<<dp[n]<<endl;
    

}
