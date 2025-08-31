#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main() {
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));
    if (grid[0][0] == '*') {
        cout << 0 << endl;
        return 0;
    }
    dp[0][0] = 1;

    for (int j = 1; j < n; j++) {
        if (grid[0][j] == '.') dp[0][j] = dp[0][j-1];
        else dp[0][j] = 0;
    }
    for (int i = 1; i < n; i++) {
        if (grid[i][0] == '.') dp[i][0] = dp[i-1][0];
        else dp[i][0] = 0;
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (grid[i][j] == '.') {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
            }
        }
    }

    cout << dp[n-1][n-1] << endl;
}
