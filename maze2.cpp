#include <bits/stdc++.h>
using namespace std;

char grid[1001][1001];
bool vis[1001][1001];
int dist[1001][1001];
pair<int, int> parent[1001][1001];
int n, m;
vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool valid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m && grid[i][j] != '#' && !vis[i][j];
}
void bfs(int si, int sj, int di, int dj) {
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    dist[si][sj] = 0;
    parent[si][sj] = {-1, -1};

    while (!q.empty()) {
        pair<int, int> par = q.front();
        q.pop();
        int par_i = par.first;
        int par_j = par.second;

        for (int i = 0; i < 4; i++) {
            int ci = par_i + dir[i].first;
            int cj = par_j + dir[i].second;

            if (valid(ci, cj)) {
                vis[ci][cj] = true;
                dist[ci][cj] = dist[par_i][par_j] + 1;
                parent[ci][cj] = {par_i, par_j};
                q.push({ci, cj});

                if (ci == di && cj == dj) {
                    return;
                }
            }
        }
    }
}

void markPath(int si, int sj, int di, int dj) {
    int i = di, j = dj;
    while (i != si || j != sj) {
        if (grid[i][j] != 'D' && grid[i][j] != 'R') {
            grid[i][j] = 'X';
        }
        pair<int, int> p = parent[i][j];
        i = p.first;
        j = p.second;
    }
}

int main() {
    cin >> n >> m;
    int si = -1, sj = -1, di = -1, dj = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'R') {
                si = i;
                sj = j;
            } else if (grid[i][j] == 'D') {
                di = i;
                dj = j;
            }
        }
    }

    memset(vis, false, sizeof(vis));
    memset(dist, -1, sizeof(dist));

    bfs(si, sj, di, dj);

    if (vis[di][dj]) {
        markPath(si, sj, di, dj);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}