#include <bits/stdc++.h>
using namespace std;

struct Cell {
    int x, y, dir;
};

int n, m;
vector<vector<char>> maze;
vector<vector<bool>> visited;
vector<vector<Cell>> parent;
int dx[] = {0, 0, -1, 1}; // Right, Left, Up, Down
int dy[] = {1, -1, 0, 0};

bool bfs(int sx, int sy, int dx, int dy) {
    queue<Cell> q;
    q.push({sx, sy, -1});  // No parent initially
    visited[sx][sy] = true;

    while (!q.empty()) {
        Cell cur = q.front();
        q.pop();

        if (cur.x == dx && cur.y == dy) {
            return true; // Found the exit
        }

        // Try moving in the specified order: Right -> Left -> Up -> Down
        for (int i = 0; i < 4; i++) {
            int nx = cur.x + ::dx[i];
            int ny = cur.y + ::dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] != '#' && !visited[nx][ny]) {
                visited[nx][ny] = true;
                parent[nx][ny] = {cur.x, cur.y, i}; // Store direction
                q.push({nx, ny, i});
            }
        }
    }
    return false; // No path found
}

// Function to backtrack and mark the path
void markPath(int ex, int ey) {
    while (maze[ex][ey] != 'R') {
        Cell p = parent[ex][ey];
        if (maze[p.x][p.y] != 'R' && maze[p.x][p.y] != 'D') {
            maze[p.x][p.y] = 'X'; // Mark the path
        }
        ex = p.x;
        ey = p.y;
    }
}

int main() {
    cin >> n >> m;
    maze.resize(n, vector<char>(m));
    visited.resize(n, vector<bool>(m, false));
    parent.resize(n, vector<Cell>(m, {-1, -1, -1}));

    int sx, sy, dx, dy;

    // Read input
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == 'R') {
                sx = i;
                sy = j;
            } else if (maze[i][j] == 'D') {
                dx = i;
                dy = j;
            }
        }
    }

    // Find shortest path using BFS
    if (bfs(sx, sy, dx, dy)) {
        markPath(dx, dy);
    }

    // Print updated maze
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << maze[i][j];
        }
        cout << "\n";
    }

    return 0;
}
