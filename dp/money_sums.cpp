#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];

    int sum = accumulate(coins.begin(), coins.end(), 0);
    vector<bool> dp(sum+1, false);
    dp[0] = true;

    for (int c : coins) {
        for (int s = sum; s >= c; s--) {
            if (dp[s - c]) dp[s] = true;
        }
    }

    vector<int> results;
    for (int s = 1; s <= sum; s++) {
        if (dp[s]) results.push_back(s);
    }

    cout << results.size() << "\n";
    for (int x : results) cout << x << " ";
    cout << "\n";
}
