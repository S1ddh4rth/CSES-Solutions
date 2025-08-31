#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<pair<int,int>>> par(n, vector<pair<int,int>> (m, {-1,-1}));
    pair<int,int> start, end;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') start = {i, j};
            if (grid[i][j] == 'B') end = {i, j};
        }
    }

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    char dirChar[] = {'D', 'U', 'R', 'L'};
    
    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<int,int>> q;
    q.push(start);
    vis[start.first][start.second] = 1;

    bool found = false;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if (x == end.first && y == end.second) {
            found = true;
            break;
        }
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && grid[nx][ny] != '#') {
                vis[nx][ny] = 1;
                par[nx][ny] = {x, y};
                q.push({nx, ny});
            }
        }
    }

    if (!found) {
        cout << "NO" << endl;
    } else {
        cout << "YES"<< endl;
        // reconstruct path
        vector<char> path;
        pair<int,int> curr = end;
        while (curr != start) {
            auto [px, py] = par[curr.first][curr.second];
            if (px == -1 && py == -1) break; 
            if (px+1 == curr.first && py == curr.second) path.push_back('D');
            else if (px-1 == curr.first && py == curr.second) path.push_back('U');
            else if (px == curr.first && py+1 == curr.second) path.push_back('R');
            else if (px == curr.first && py-1 == curr.second) path.push_back('L');
            curr = {px, py};
        }
        reverse(path.begin(), path.end());
        cout << path.size() << endl;
        for (char c : path) cout << c;
        cout << endl;
    }
}
