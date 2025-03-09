#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> d = { {-2, -1}, {-1, -2}, {1, -2}, {2, -1},
                             {2, 1}, {1, 2}, {-1, 2}, {-2, 1} };

bool valid(int i, int j, int n) {
    return i >= 0 && j >= 0 && i < n && j < n;
}

int bfs(int n, int si, int sj, int di, int dj) {
    if (si == di && sj == dj) {
        return 0;
    }

    queue<pair<int, int>> q;
    vector<vector<int>> level(n, vector<int>(n, -1));

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
            if (valid(ci, cj, n) && level[ci][cj] == -1) {
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
        int n, si, sj, di, dj;
        cin >> n >> n;
        cin >> si >> sj; 
        cin >> di >> dj; 

        if (si < 0 || sj < 0 || si >= n || sj >= n || di < 0 || dj < 0 || di >= n || dj >= n) {
            cout << -1 << endl;
            continue;
        }

        int step = bfs(n, si, sj, di, dj);
        cout << step << endl;
    }

    return 0;
}