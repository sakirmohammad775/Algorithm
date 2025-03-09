#include <bits/stdc++.h>
using namespace std;

// Directions for knight's moves
vector<pair<int, int>> d = { {-2, -1}, {-1, -2}, {1, -2}, {2, -1},
                             {2, 1}, {1, 2}, {-1, 2}, {-2, 1} };

// Function to check if a cell is valid
bool valid(int i, int j, int n) {
    return i >= 0 && j >= 0 && i < n && j < n;
}

// BFS function to find the minimum steps for the knight to reach the queen
int bfs(int n, int kx, int ky, int qx, int qy) {
    // If knight and queen are in the same cell
    if (kx == qx && ky == qy) {
        return 0;
    }

    // BFS setup
    queue<pair<int, int>> q;
    vector<vector<int>> level(n, vector<int>(n, -1)); // Distance matrix

    q.push({kx, ky});
    level[kx][ky] = 0;

    while (!q.empty()) {
        pair<int, int> par = q.front();
        q.pop();
        int par_i = par.first;
        int par_j = par.second;

        // Explore all 8 possible moves
        for (int i = 0; i < 8; i++) {
            int ci = par_i + d[i].first;
            int cj = par_j + d[i].second;

            // Check if the new position is valid and unvisited
            if (valid(ci, cj, n) && level[ci][cj] == -1) {
                level[ci][cj] = level[par_i][par_j] + 1;

                // If queen's position is reached
                if (ci == qx && cj == qy) {
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
        int n, kx, ky, qx, qy;
        cin >> n >> n; // Chessboard size (n x n)
        cin >> kx >> ky; // Knight's position
        cin >> qx >> qy; // Queen's position


        if (kx < 0 || ky < 0 || kx >= n || ky >= n || qx < 0 || qy < 0 || qx >= n || qy >= n) {
            cout << -1 << endl;
            continue;
        }

        int result = bfs(n, kx, ky, qx, qy);
        cout << result << endl;
    }

    return 0;
}