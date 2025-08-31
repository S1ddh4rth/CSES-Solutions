#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    queue<pair<int,int>> q;
    vector<vector<int>> monster(n, vector<int>(m, 1e9));
    pair<int,int> start;

    // Push all monsters
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'M') {
                q.push({i, j});
                monster[i][j] = 0;
            }
            if (grid[i][j] == 'A') {
                start = {i, j};
            }
        }
    }

    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};
    char dirChar[] = {'D','U','R','L'};

    // BFS for monsters
    while (!q.empty()) {
        auto [x,y] = q.front(); q.pop();
        for (int d=0; d<4; d++) {
            int nx = x+dx[d], ny = y+dy[d];
            if (nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny] != '#' && monster[nx][ny] > monster[x][y] + 1) {
                monster[nx][ny] = monster[x][y] + 1;
                q.push({nx,ny});
            }
        }
    }

    // BFS for player
    vector<vector<int>> dist(n, vector<int>(m, -1));
    vector<vector<pair<int,int>>> par(n, vector<pair<int,int>>(m, {-1,-1}));
    queue<pair<int,int>> qa;
    qa.push(start);
    dist[start.first][start.second] = 0;

    pair<int,int> escape = {-1,-1};
    while (!qa.empty()) {
        auto [x,y] = qa.front(); qa.pop();
        // check boundary escape
        if (x==0 || y==0 || x==n-1 || y==m-1) {
            escape = {x,y};
            break;
        }
        for (int d=0; d<4; d++) {
            int nx = x+dx[d], ny = y+dy[d];
            if (nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny] != '#' && dist[nx][ny]==-1) {
                int arrive = dist[x][y] + 1;
                if (arrive < monster[nx][ny]) { // only safe if earlier
                    dist[nx][ny] = arrive;
                    par[nx][ny] = {x,y};
                    qa.push({nx,ny});
                }
            }
        }
    }

    if (escape.first == -1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        // reconstruct path
        vector<char> path;
        pair<int,int> cur = escape;
        while (cur != start) {
            auto [px,py] = par[cur.first][cur.second];
            if (px+1 == cur.first) path.push_back('D');
            else if (px-1 == cur.first) path.push_back('U');
            else if (py+1 == cur.second) path.push_back('R');
            else if (py-1 == cur.second) path.push_back('L');
            cur = {px,py};
        }
        reverse(path.begin(), path.end());
        cout << path.size() << "\n";
        for (char c : path) cout << c;
        cout << "\n";
    }
}
