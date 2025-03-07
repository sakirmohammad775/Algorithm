/*leetcode
class Solution {
public:
    bool vis[105][105];
    vector<pair<int,int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int n, m;

    bool valid(int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= m) {
            return false;
        }
        return true;
    }
    void dfs(int si, int sj, vector<vector<int>>& grid) {
       cout<<si<<" "<<sj<<endl;
        vis[si][sj] = true;
        for (int i = 0; i < 4; i++) {
            int ci = si + d[i].first;
            int cj = sj + d[i].second;
            if (valid(ci, cj)&& !vis[ci][cj] && grid[ci][cj] == 1) {
                dfs(ci, cj,grid);
            }
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {

        n = grid.size();    // roww
        m = grid[0].size(); // column
        memset(vis, false, sizeof(vis));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    dfs(i, j, grid);
                }
            }
        }
        return 0;
    }
};

*/