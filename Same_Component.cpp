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
bool bfs(int si,int sj,int di,int dj){
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
    
        int par_i = current.first;
        int par_j = current.second;
        if (par_i == di && par_j == dj) {
            return true;
        }
    
        for (int i = 0; i < 4; i++) {
            int ci = par_i + d[i].first;
            int cj = par_j + d[i].second;
    
            if (valid(ci, cj)) {
                q.push({ci, cj}); 
                vis[ci][cj] = true;
            }
        }
    }
    return false;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if (grid[x1][y1] != '.' || grid[x2][y2] != '.')
    {
        cout << "NO" << endl;
        return 0;
    }

    memset(vis, false, sizeof(vis));
    if (bfs(x1, y1, x2, y2))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}