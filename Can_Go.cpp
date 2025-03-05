#include <bits/stdc++.h>
using namespace std;

char grid[105][105];
bool vis[105][105];
vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
    {
        return false;
    }
    if (vis[i][j])
    {
        return false;
    }
    if (grid[i][j]=='#')
    {
        return false;
    }
    return true;
}
bool bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    while (!q.empty())
    {
        auto [par_i, par_j] = q.front();
        q.pop();
        if (grid[par_i][par_j]=='B')
        {
            return true;
        }
        for (int i = 0; i < 4; i++)
        {
            int ci = par_i + d[i].first;
            int cj = par_j + d[i].second;
            if (valid(ci, cj))
            {
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
    int si = -1, sj = -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                si = i, sj = j;
            }
        }
    }
    memset(vis, false, sizeof(vis));
    if (si == -1 || sj == -1)
    {
        cout << "NO\n";
    }
    else if (bfs(si, sj))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
    return 0;
}