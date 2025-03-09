#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> d = { {-2, -1}, {-1, -2}, {1, -2}, {2, -1},
                             {2, 1}, {1, 2}, {-1, 2}, {-2, 1} };

bool valid(int i, int j, int n, int m) {
    return i >= 0 && j >= 0 && i < n && j < m;
}

int bfs(int n, int m, int si, int sj, int di, int dj) {
    if (si == di && sj == dj) {
        return 0;
    }

    queue<pair<int, int>> q;
    vector<vector<int>> level(n, vector<int>(m, -1));

    q.push({si, sj});
    level[si][sj] = 0;

    while (!q.empty()) {
        pair<int, int> par = q.front();
        q.pop();
        int par_i = par.first;
        int par_j = par.second;
        for (int i = 0; i < 8; i++) {
            int ci = par_i + d[i].first;
            int cj = par_j + d[i].second;
            if (valid(ci, cj, n, m) && level[ci][cj] == -1) {
                level[ci][cj] = level[par_i][par_j] + 1;

                if (ci == di && cj == dj) {
                    return level[ci][cj];
                }

                q.push({ci, cj});
            }
        }
    }
    return -1;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, si, sj, di, dj;
        cin >> n >> m;
        cin >> si >> sj;
        cin >> di >> dj;

        // Boundary check
        if (si < 0 || sj < 0 || si >= n || sj >= m || di < 0 || dj < 0 || di >= n || dj >= m) {
            cout << -1 << endl;
            continue;
        }

        int step = bfs(n, m, si, sj, di, dj);
        cout << step << endl;
    }

    return 0;
}