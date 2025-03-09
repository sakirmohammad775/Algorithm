#include <bits/stdc++.h>
using namespace std;
char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;

bool valid(int i, int j)
{
    if (i < 0 || j < 0 || i >= n || j >= m)
    {
        return false;
    }
    if (grid[i][j] != '.')
    {
        return false;
    }
    if (vis[i][j])
    {
        return false;
    }
    return true;
}

int bfs(int si, int sj) {
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    int area = 0;

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        area++;

        for (int i = 0; i < 4; i++) {
            int ci = current.first + d[i].first;
            int cj = current.second + d[i].second;

            if (valid(ci, cj)) {
                q.push({ci, cj});
                vis[ci][cj] = true;
            }
        }
    }

    return area;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
memset(vis, false, sizeof(vis));
int minArea = INT_MAX;
for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        if (grid[i][j] == '.' && !vis[i][j]) {
            int area = bfs(i, j);
            if (area < minArea) {
                minArea = area;
            }
            }
        }
    }
    if (minArea == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << minArea << endl;
    }
    return 0;
}