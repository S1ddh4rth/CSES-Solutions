#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // answer string
    string ans;
    // frontier of positions we can reach at this step
    set<pair<int,int>> frontier;
    frontier.insert({0,0});
    ans.push_back(grid[0][0]);

    // we need exactly 2n-2 moves
    for (int step = 1; step < 2*n-1; step++) {
        char best = 'Z' + 1;
        set<pair<int,int>> next;
        for (auto [x,y] : frontier) {
            if (x+1 < n) best = min(best, grid[x+1][y]);
            if (y+1 < n) best = min(best, grid[x][y+1]);
        }
        // collect all positions giving best char
        for (auto [x,y] : frontier) {
            if (x+1 < n && grid[x+1][y] == best) next.insert({x+1,y});
            if (y+1 < n && grid[x][y+1] == best) next.insert({x,y+1});
        }
        ans.push_back(best);
        frontier = move(next);
    }

    cout << ans << "\n";
}
