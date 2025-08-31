#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<long long>> dp(n, vector<long long>(n, 0));

    for (int i = 0; i < n; i++) dp[i][i] = a[i];

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            dp[i][j] = max(a[i] - dp[i+1][j], a[j] - dp[i][j-1]);
        }
    }

    long long total = accumulate(a.begin(), a.end(), 0LL);
    cout << (total + dp[0][n-1]) / 2 << "\n";
}
