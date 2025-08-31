#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<long long>> projects(n, vector<long long>(3));
    
    for (int i = 0; i < n; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        projects[i][0] = a; // start
        projects[i][1] = b; // end
        projects[i][2] = c; // reward
    }

    // sort by end time
    sort(projects.begin(), projects.end(), [](const vector<long long> &p1, const vector<long long> &p2) {
        return p1[1] < p2[1];
    });

    vector<long long> dp(n + 1, 0);  
    vector<long long> ends;
    for (int i = 0; i < n; i++) ends.push_back(projects[i][1]);

    for (int i = 1; i <= n; i++) {
        auto &p = projects[i - 1];
        long long start = p[0], end = p[1], reward = p[2];

        // find latest project that ends before this one starts
        int j = upper_bound(ends.begin(), ends.end(), start - 1) - ends.begin();

        // skip or take
        dp[i] = max(dp[i - 1], dp[j] + reward);
    }

    cout << dp[n] << "\n";
    return 0;
}
