#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main() {
    int n;
    cin >> n;

    long long total = 1LL * n * (n+1) / 2;
    if (total % 2) {
        cout << 0 << "\n";
        return 0;
    }

    int target = total / 2;

    vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
    dp[0][0] = 1; // one way to make sum 0 with 0 numbers

    for (int num = 1; num <= n; num++) {
        for (int sum = 0; sum <= target; sum++) {
            dp[num][sum] = dp[num-1][sum]; // not take
            if (sum - num >= 0) {
                dp[num][sum] = (dp[num][sum] + dp[num-1][sum-num]) % MOD; // take
            }
        }
    }

    // divide by 2 to remove double-counting
    cout << (1LL * dp[n][target] * ((MOD+1)/2)) % MOD << "\n";
}
